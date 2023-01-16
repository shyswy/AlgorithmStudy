#include <string>
#include <vector>
#include<queue>
#include<queue>
#include<memory.h>
#include<iostream>
using namespace std;
#define inf 987654321
int dist[300][300];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
    for (auto it : fares) {
        int p1 = it[0], p2 = it[1], cost = it[2];
        dist[p1][p2] = cost;
        dist[p2][p1] = cost;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == inf || dist[k][j] == inf) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int min = dist[s][s] + dist[s][a] + dist[s][b];

    for (int i = 1; i <= n; i++) {
        if (dist[s][i] == inf || dist[i][a] == inf || dist[i][b] == inf)continue;

        if (min > dist[s][i] + dist[i][a] + dist[i][b])
            min = dist[s][i] + dist[i][a] + dist[i][b];
    }
    answer = min;
    return answer;
}