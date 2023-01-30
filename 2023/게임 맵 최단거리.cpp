#include<vector>
#include<queue>
#include<iostream>
using namespace std;
queue<pair<int, pair<int, int> > > qu;
int visit[105][105];
int nw[4] = { 1,0,-1,0 };
int nh[4] = { 0,1,0,-1 };
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int width = maps.size(), height = maps[0].size();
    if (maps[0][0] == 0) return -1;
    qu.push({ 1,{0,0} });
    while (!qu.empty()) {
        int w = qu.front().second.first, h = qu.front().second.second, dist = qu.front().first;
        qu.pop();
        // cout<<w<<" "<<h<<endl;
        if (w == width - 1 && h == height - 1)
            return dist;
        if (visit[w][h]) continue;
        visit[w][h] = 1;
        for (int i = 0; i < 4; i++) {
            int n_w = w + nw[i], n_h = h + nh[i];
            if (0 > n_w || n_w >= width || 0 > n_h || n_h >= height)continue;//맵 밖으로
            if (maps[n_w][n_h] == 1) qu.push({ dist + 1,{n_w,n_h} });

        }
    }
    return -1;
}