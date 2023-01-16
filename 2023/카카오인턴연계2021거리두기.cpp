#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char p[5][5];
int visit[5][5];
bool chk = true;
void parser(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            p[i][j] = v[i][j];
        }
    }

}
void dfs(int i, int j, int depth) {
    visit[i][j] = 1;
    if (depth > 2) return;
    for (int n = 0; n < 4; n++) {
        int nx = i + dx[n], ny = j + dy[n];
        if (nx < 0 || nx>4 || ny < 0 || ny>4) continue;
        if (visit[nx][ny] == 1) continue;
        if (p[nx][ny] == 'X')continue;
        if (p[nx][ny] == 'P') {
            chk = false;
            //cout<<"fail: "<<nx<<" "<<ny<<endl;
            return;
        }
        else if (p[nx][ny] == 'O') {
            dfs(nx, ny, depth + 1);
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int k = 0; k < places.size(); k++) {
        parser(places[k]);

        chk = true;
        // cout<<"num: "<<k<<endl;

        for (int i = 0; i < 5; i++) { //5*5
            for (int j = 0; j < 5; j++) {



                if (chk && p[i][j] == 'P') { //dfs
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            visit[i][j] = 0;
                        }
                    }
                    dfs(i, j, 1);


                }
            }

        }
        if (chk)answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}