#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int ma[101][101];
int solution(int m, int n, vector<vector<int>> puddles) { //오른쪽, 아래로만 -> 도착만 하면 무조건 최단거리 거리 계산할필요없다.
    int answer = 0;
    bool find = false;
    int min_dist = 0;
    queue< pair<int, int>  > qu;
    qu.push({ 1,1 });
    for (auto p : puddles) {
        ma[p[0]][p[1]] = 1;
    }
    while (!qu.empty()) {
        int x = qu.front().first, y = qu.front().second;
        qu.pop();
        //cout<<x<<" "<<y<<endl;
        if (x == m && y == n)answer++;
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            //cout<<nx<<" "<<ny<<endl;
            if (ma[nx][ny] == 1) continue; //물이 있는 웅덩이는 갈 수 없다.
            if (0 < nx && nx <= m && 0 < ny && ny <= n) {
                //if(find&&(dist+1)>min_dist) continue;
                qu.push({ nx,ny });
            }
        }

    }
    //  cout<<min_dist<<endl;
    return answer;
}


//dp로 푼 풀이.
/*
1111
1x12
1124  -> 오른쪽, 아래로 도달만 하면 최단거리다!

*/


#include <string>
#include <vector>
using namespace std;
int dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    //m 가로 열
    //n 세로 행
    dp[1][1] = 1;

    for (int i = 0; i < puddles.size(); i++) { //물웅덩이는 -1
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int a = 0;
            int b = 0;
            if (dp[i][j] == -1)
                continue;
            if (dp[i - 1][j] != -1)
                a = dp[i - 1][j];
            if (dp[i][j - 1] != -1)
                b = dp[i][j - 1];
            dp[i][j] += (a + b) % 1000000007;
        }
    }

    return dp[n][m];
}