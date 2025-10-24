#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
int inf = numeric_limits<int>::max(); 

int cambio(vector <int> v, int M, int i, vector <vector<int>> memo){

	if (M == 0) return 0;
	else if (M < -1) return inf;
	else if (i > v.size()) return 0;
	else if (v[i] > M){
		memo[i][M] = cambio(v, M, i + 1, memo);
		return memo[i][M];
	}
	else{
		memo[i][M] = min(1 + cambio(v, M - v[i], i, memo), cambio(v, M, i + 1, memo));
		return memo[i][M];
	}

}

int main(){

	vector <int> v = {1,4,6};
	cout << "dame la cantidad a devolver: ";
	int M; cin >> M;
	vector <vector <int>> memo(v.size(), vector<int>(M, -1));
	int res = cambio(v, M, 0,memo);
	cout << "La cantidad mínima a devolver es : " << res << endl;
	return 0;
}
