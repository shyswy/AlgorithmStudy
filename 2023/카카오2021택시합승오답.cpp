#include <string>
#include <vector>
#include<queue>
#include<queue>
#include<memory.h>
#include<iostream>
using namespace std;
#define inf 100001
typedef struct {
    int from, to, cost;

}edge;
int dist[200][200];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }


    //S>A
    priority_queue < pair<int, pair<int, int>> >pq;
    for (auto it : fares) {
        if (it[0] == s)
            pq.push({ -it[2],{it[0],it[1]} });

        if (it[1] == s)
            pq.push({ -it[2],{it[1],it[0]} });

    }
    //&&(dist[s][a]==inf||dist[s][b]==inf)
    while (!pq.empty()) {
        int from = pq.top().second.first, to = pq.top().second.second, cost = -pq.top().first;
        pq.pop();
        //cout<<from<<" "<<to<<" "<<cost<<endl;
        //cout<<dist[s][to]<<" "<<dist[s][from]<<endl;
        if (dist[s][to] > dist[s][from] + cost && dist[s][from] != inf) {

            dist[s][to] = dist[s][from] + cost;

            for (auto it : fares) {
                if (it[0] == to)
                    pq.push({ -it[2],{it[0],it[1]} });

                if (it[1] == to)
                    pq.push({ -it[2],{it[1],it[0]} });
            }
        }
    }
    int StoA = dist[s][a];
    int StoB = dist[s][b];






    //A>B
    pq = priority_queue < pair<int, pair<int, int> > >();
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }

    for (auto it : fares) {
        if (it[0] == a)
            pq.push({ -it[2],{it[0],it[1]} });

        if (it[1] == a)
            pq.push({ -it[2],{it[1],it[0]} });
    }
    //&&dist[a][b]==inf
    while (!pq.empty()) {
        int from = pq.top().second.first, to = pq.top().second.second, cost = -pq.top().first;
        pq.pop();

        //cout<<dist[a][to]<<" "<<dist[a][from]<<endl;
        if (dist[a][to] > dist[a][from] + cost && dist[a][from] != inf) {

            dist[a][to] = dist[a][from] + cost;

            for (auto it : fares) {
                if (it[0] == to)
                    pq.push({ -it[2],{it[0],it[1]} });

                if (it[1] == to)
                    pq.push({ -it[2],{it[1],it[0]} });
            }
        }
    }

    int AtoB = dist[a][b];

    int low;
    if (StoA > StoB) low = StoB;
    else low = StoA;
    int together = low + AtoB, isorate = StoA + StoB;
    cout << low << " " << AtoB << " " << isorate << endl;
    if (together < isorate) answer = together;
    else answer = isorate;


    return answer;
}