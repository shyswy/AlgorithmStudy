#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        int arr[1002];
        for (int i = 1; i <= n; i++) cin >> arr[i];
        

        vector<int> adj[1002];
        int ind[1002] = { 0, };//ind[x]>> x번 정점으로 들어오는 정점수= indegree 값.
        queue<int> q;
        int result[1002];

        while (k--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            ind[b]++;
        }

        int W;
        cin >> W;

        for (int i = 1; i <= n; i++) {
            if (ind[i] == 0) {//indeg=0 즉 시작정점들을 모두 push 
                q.push(i);
            }
            result[i] = arr[i];//자기자신 건설시간 기본값으로 추가.
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < adj[cur].size(); i++) {//bfs 탐색 + 위상정렬
                int next = adj[cur][i];
                ind[next]--;
                result[next] = max(result[next], result[cur] + arr[next]);//기존 값 or 현재정점 거치는 갱신값 중 긴거리로 갱신.
                if (ind[next] == 0) {//위의 과정을 통해 indegree가 0 되면 queue에 push해 탐색
                    q.push(next);
                }
            }
        }

        cout << result[W] << endl;
    }

    return 0;
}
