#include <iostream>
#include <map>

#define EMPTY NULL
using namespace std;

/*  Problema:	        Algoritmo:
    ¿Hay camino?	    BFS
    ¿Está conectado?	BFS
    ¿Es bipartido?	    BFS con colores
    ¿Hay ciclo?	        DFS recursivo
    Caballo / Reinas	DFS (backtracking)

    Lenguaje pseudocódigo:
    EMPTY -> NULL
    .push(var) -> añadir a una estructura(normalmente a q, que es una cola)
    .pop() -> sacar el primer elemento de la cola, guardarlo en una variable cur y eliminarlo de q
    (<-) -> (=) el operador <- es la asignacion = 
    = -> == el operador = es la igualdad estricta de una condicion ==
    procedure -> void, procedure es una funcion que no devuelve ningun valor, solo modifica variables, son los void
    function -> int, char, string , function si que es una funcion que aparte de modificar variables, devuelve un valor con return
*/

queue <string> q; // cola FIFO, primero que entra, primero que sale
map <string, bool> visitado; // TablaHash con clave string i valor bool
using ListaAristas = vector <pair<string, string> >; // Conexion entre dos nodos, origen y destino

/*procedure*/ void BFS(ListaAristas edges, string v){ // recorrido en anchura, mira todos los nodos de una altura, sirve para encontrar el camino más corto
    q.push(v);
    visitado[v] = true;

    while (/*q != EMPTY*/ !q.empty()){ // do
        string cur = q.front(); /* <- */
        q.pop();

        for (int i = 0; i < edges.size(); i++){ // do
            string origen = edges[i].first; /* <- */
            string destino = edges[i].second; /* <- */

            if (origen == cur){ // then
                if (/*not*/ !visitado[destino]){ // then
                    visitado[destino] = true; /* <- */
                    q.push(destino);
                }
            }
        }
    }
}

/*procedure*/ void DFS(ListaAristas edges, string u){ // recorrido en profundidad, baja hasta el final de un camino
    visitado[u] = true; /* <- */

    for (auto par : edges){ // do
        string a = par.first;
        string v = par.second;

        if (a == u){ //then
            if (/*not*/ !visitado[v]) { //then
                DFS(edges, v);
            }
        }
    }
}

/*function*/ int contarCaminos(ListaAristas edges, string origen, string destino){ // recorrido en profundidad usando Backtracking
    if (origen == destino) {
        return 1;
    }

    visitado[origen] = true; /* <- */
    int total = 0;

    for (auto par : edges){ // do
        string a = par.first;
        string v = par.second;

        if (a == origen){ //then
            if (/*not*/ !visitado[v]) { //then
              total += contarCaminos(edges, v, destino);
            }
        }
    }

    visitado[origen] = false;
    return total;
}

int Suma(BST root){
    if (root == NULL) // then
        return 0;
    int suml = Suma(root.left);
    int sumr = Suma(root.right);
    root.val = root.val + suml + sumr;
}

int DiskUsage(BST root){
    if (root.content = NULL)// then
        return root.size;
    root.size = root.size + DiskUsage(root.content);
    root.size = root.size + DiskUsage(root.next);
    return root.size;
}