#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;
int inf = numeric_limits<int>::min();

int mochila(vector <int> &p, vector <int> &v, int N, int M, vector <vector<int>> &memo){

	if(N == 0 || M == 0) return 0;
	else if(M < 0) return inf;
	else if (memo[N][M] != -1) return memo[N][M];
	else if (p[N] > M){
		memo[N][M] = mochila(p, v, N -1, M, memo);
		return memo[N][M];
	}
	else if(p[N] <= M){
		memo[N][M] = max(mochila(p, v, N -1, M, memo), v[N] + mochila(p,v,N -1,M - p[N], memo));
		return memo[N][M];
	}
	return 0;
}

int main(){
	vector <int> p = {9, 6, 5};
	vector <int> v = {38, 40, 24};
	if(p.size() != v.size()) return -1; 
	cout << "dame el peso maximo de la mochila: ";
	int m; cin >> m;
	vector <vector <int>> memo(v.size(), vector<int>(m, -1));	
	int res = mochila(p, v, v.size() - 1, m, memo); 
	cout << "puedes conseguir un beneficio de :" << res << endl;
	return 0;
}
