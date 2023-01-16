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
        int ind[1002] = { 0, };//ind[x]>> x�� �������� ������ ������= indegree ��.
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
            if (ind[i] == 0) {//indeg=0 �� ������������ ��� push 
                q.push(i);
            }
            result[i] = arr[i];//�ڱ��ڽ� �Ǽ��ð� �⺻������ �߰�.
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < adj[cur].size(); i++) {//bfs Ž�� + ��������
                int next = adj[cur][i];
                ind[next]--;
                result[next] = max(result[next], result[cur] + arr[next]);//���� �� or �������� ��ġ�� ���Ű� �� ��Ÿ��� ����.
                if (ind[next] == 0) {//���� ������ ���� indegree�� 0 �Ǹ� queue�� push�� Ž��
                    q.push(next);
                }
            }
        }

        cout << result[W] << endl;
    }

    return 0;
}
