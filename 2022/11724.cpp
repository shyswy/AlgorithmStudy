#include<iostream>
#include<vector>
using namespace std; //연결요소의 수 = 몇덩어리?
vector<int> v[1002];
int visit[1002];
void dfs(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		int nxt = v[x][i];
		if (visit[nxt] == 0) {
			visit[nxt] = 1;
			dfs(nxt);
		}
	}
}


int main() {
	int n, m,f,t;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> f >> t;
		v[f].push_back(t);
		v[t].push_back(f);
	}
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			
			dfs(i);
			num++;
		}
	}



	cout << num;

}