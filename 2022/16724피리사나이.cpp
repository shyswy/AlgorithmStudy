#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;
const int max_v = 11000000;
int parent[max_v];
string str[1000];
char ma[1000][1000];
//�и������� ����> �ʿ��� safe���� ��. 1���� ��ȯ ����Ŭ���� 1���� �ʿ���. find union���� ���հ��� ã��.
int n, m;
int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);

}
void join(int x, int y) {
	int xx = find(x), yy = find(y);
	if (xx != yy) {
		parent[yy] = xx;
	}
}
int visit[1100000];

void dfs(int y, int x) {//�ʹ۰��� ���� ����. ���� ����
	int i = y, j = x,p= find(i * m + j);//1���� ����ȭ.
	//cout << i <<" "<< j << endl;
	visit[i * m + j] = 1;
	
	
	if (ma[i][j]== 'D') {
	
		if (p != find((i + 1) * m+j)) {
			join(  i * m+j, (i + 1) * m + j);//��ĭ �� ������ �ڽ�����
			dfs(i+1,j);
		}
	}
	else if (ma[i][j] == 'U') {
	
		if (find((i-1) * m + j) != p) {
			join( i * m+j, (i - 1) * m + j);
			dfs((i - 1),j);
		}
	}
	else if (ma[i][j] == 'L') {
		
		
		if (p != find(i*m+(j-1))) {
			
			join( i*m+j, i * m + (j - 1));
			dfs(i ,(j - 1));
		}
	}
	else if (ma[i][j] == 'R') {
		if (p != find(i*m+(j+1))) {
			join(i*m+j,i * m + (j + 1));
			dfs(i,j+1);
		}

	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			parent[i * m + j] = i * m + j;
		}

	}
	
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (int j = 0; j < m; j++)
			ma[i][j] = str[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			if (!visit[i * m + j]) {
				
				dfs(i, j);
			
				
				//cout << "end\n";
			}
			
		



		}
	}
	for (int i = 0; i < n * m; i++) {//��Ʈ ����� ����= ������ ����
		if (parent[i] == i)
			ans++;

	}
	cout << ans;



}