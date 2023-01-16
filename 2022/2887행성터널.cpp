#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int arr[3][100001];
int p[100001];
vector<pair<int,int>> x, y, z;
priority_queue <  pair<  int,pair<int, int>  >  > edges;

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
void join(int x, int y) {
	int px = find(x), py = find(y);
	if (px != py)
		p[py] = px;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a,b,c,dx,dy,dz,ans=0,time=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;// x, y, z
		x.push_back({a,i});
		y.push_back({ b,i });
		z.push_back({ c,i });
		p[i] = i;
	}
	sort(x.begin(), x.end());   //x,y,z,를 각각 sort 함으로써 x,y,z좌표 차이의 최솟값을 편하게 구한다.
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 0; i < n-1; i++) {
		dx = x[i + 1].first - x[i].first;//sort된 x좌표들이기에 바로옆에있는 x좌표가 자신이 얻을 수 있는 최소 dx( x좌표 변화량) 이다.
		dy = y[i + 1].first - y[i].first;
		dz = z[i + 1].first - z[i].first;
		edges.push({ -dx,{x[i + 1].second,x[i].second} });
		edges.push({ -dy,{y[i + 1].second,y[i].second} });
		edges.push({ -dz,{z[i + 1].second,z[i].second} });
	}
	while (!edges.empty()||time==n) {//모든 정점을 연결시 ( n-1개 간선으로 mst완성시 더이상 찾지 않고   종료한다
		int from=edges.top().second.first, to=edges.top().second.second, w=-edges.top().first;
		edges.pop();
		if (find(from) != find(to)) {
			join(from, to);
			ans += w;
			time++;
		}
	}
	cout << ans << endl;

	

}