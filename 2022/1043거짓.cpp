#include<iostream>
using namespace std;
//입력받으면서 처리하려해서 문제. 다 받은 뒤 처리!

//선처리, 후처리에 대해 제대로 알고 짜야된다. 선처리가 코드상 짧다고 무조건 우겨넣지말자




int parent[100];
int arr[100];
int visit[100];
int siz[100];
int find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a]=find(parent[a]);

}

void uni(int a, int b) {
	int aa = find(a), bb = find(b);
	
		parent[bb] = aa;
	

}
int root1, root2;

int main() {
	int n, m, k, tmp, tmp2;
	cin >> n >> m;
	
	cin >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		siz[i]=0;
	}
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		arr[tmp] = 1;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		

		for (int j = 0; j < tmp; j++) {
			cin >> tmp2;
			root2 = find(tmp2);
			if (j == 0) {
				root1=root2;
				
			}
			else {
				uni(root1, root2);
				//cout << arr[tmp2] << " " << arr[root1] << endl;
				if(arr[root1]!=1)
					arr[root1] = arr[tmp2];
				
			}
			
		}
		if (tmp != 0)
			siz[root1]++;
		
		
	}

	for (int i = 1; i <= n; i++) {
		/*
		int p = find(i);
		if (arr[p] == 0 && !visit[p]) {
			visit[p] = 1;
			ans+=siz[p];
		}
		*/
		
		int p = find(i);
		cout << arr[p] << endl;
		if (arr[p]!=1) {
			ans++;
			
		}
	}
	cout << ans;



}