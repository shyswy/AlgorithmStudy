#include <string>
#include <vector>
#include<queue>
using namespace std;
//mst
int parent[101];
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);

}
void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py)
        parent[px] = py;
}
priority_queue<pair<int, pair<int, int> > > pq;
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < 101; i++)
        parent[i] = i;
    for (int i = 0; i < costs.size(); i++) {
        int f = costs[i][0], t = costs[i][1], w = costs[i][2];
        pq.push({ -w,{f,t} });
    }
    int cnt = 0;
    while (!pq.empty()&&cnt<n) { //n-1개 간선 선택완료시 종료!
        int nf = pq.top().second.first, nt = pq.top().second.second, nw = -pq.top().first;
        pq.pop();
        if (find(nf) != find(nt)) {
            join(nf, nt);
            cnt++;
            answer += nw;
        }
    }
    return answer;
}