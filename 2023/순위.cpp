#include <string>
#include <vector>
#include<unordered_set>
#include<queue>
#include<iostream>
using namespace std;
vector<int> w[101]; // 정방향
vector<int> l[101];//역방향
int visit[101];
queue<int> qu;
int bfs(int st, vector<int>edge[]) { //chk=1: w , chk=0: l
    qu.push(st);
    int ans = 0;
    while (!qu.empty()) {
        int front = qu.front();
        qu.pop();
        for (auto a : edge[front]) {
            if (!visit[a]) {
                visit[a] = 1;
                qu.push(a);
                ans++;
            }
        }
    }
    return ans;
}

int solution(int n, vector<vector<int>> results) { //이긴 사람, 진 사람의 수를 bfs로 찾고, 그 합이 n-1이면 순위가 확정된 것.
    int answer = 0;
    for (int i = 0; i < results.size(); i++) {
        int win = results[i][0], lose = results[i][1];
        w[win].push_back(lose);
        l[lose].push_back(win);
    }
    for (int i = 1; i <= n; i++) {
        //  cout<<"i: "<<i<<endl;
        for (int i = 0; i < 101; i++) visit[i] = 0;
        int ww = bfs(i, w), ll = bfs(i, l);
        if (ww + ll >= n - 1) answer++;
        // cout<<"win: "<<ww<<" lose: "<<ll<<endl;
    }

    return answer;
}