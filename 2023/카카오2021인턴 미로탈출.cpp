#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;
#define inf 987654321
vector< pair< bool, pair<int, int> > > v[1010];

bool state[1010];
int dist[1010][1025];
int trap_no[1010];
int glob_trap = 0 << 10;

int trap_state(int state, int num, int to) {//현재 state에서 num째 trap을 "to" 상태로.
    if (to == 1) {
        int n = 1 << num;
        return state |= n;
    }
    else {
        int n = 1 << num;
        return state -= n;
        //return state^=n;
    }
}

int get_trap_state(int state, int num) { //현재 state에서 num번째 trap의 active상태 리턴
    int n = 1 << trap_no[num];
    if (n & state) return 1;
    else return 0;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 1025; j++) {
            dist[i][j] = inf;
        }
    }
    priority_queue<pair<int, pair<int, int> > > pq;




    for (int i = 0; i < traps.size(); i++) {

        state[traps[i]] = true; //trap or not
        trap_no[traps[i]] = i;
    }

    for (int i = 0; i < roads.size(); i++) {
        int st = roads[i][0], ed = roads[i][1], w = roads[i][2];
        v[st].push_back({ true,{w,ed} });// 정방향 edge
        v[ed].push_back({ false,{w,st} });// 역방향 edge        
    }
    pq.push({ 0,{0,start} });


    while (!pq.empty()) {

        int ed = pq.top().second.second, w = -pq.top().first;
        int local_state = pq.top().second.first;
        pq.pop();
        if (ed == end) { //최단 거리 찾기 완료
            answer = w;
            break;
        }
        if (state[ed]) { //방문 노드가 trap일시 트랩 상태 반전.
            if (get_trap_state(local_state, ed) == 1) {
                local_state = trap_state(local_state, trap_no[ed], 0);
            }
            else if (get_trap_state(local_state, ed) == 0) {
                local_state = trap_state(local_state, trap_no[ed], 1);
            }
        }


        if (dist[ed][local_state] < w)  continue;
        dist[ed][local_state] = w;
        for (auto e : v[ed]) {   // v[st] >> {bool,  {w, ed} }
            //e.first>> treu:정방향 or false: 역방향
            //w: edge의 가중치
            //ed: 현재 노드
            int n_st = ed, n_ed = e.second.second;// 현재 노드, 해당 간선을 통한 다음노드
            if (!state[n_st] && !state[n_ed]) { //둘다 trap x

                if (e.first)
                    pq.push({ -(w + e.second.first),{local_state,n_ed} });
            }
            else if (state[n_st] && state[n_ed]) {// 둘다 trap

                if (get_trap_state(local_state, n_st) == get_trap_state(local_state, n_ed)) {

                    if (e.first) {

                        pq.push({ -(w + e.second.first),{local_state,n_ed} });
                    }
                }
                else if (get_trap_state(local_state, n_st) != get_trap_state(local_state, n_ed)) {

                    if (!e.first) {
                        pq.push({ -(w + e.second.first),{local_state,n_ed} });

                    }
                }

            }
            else if (state[n_st] && !state[n_ed]) {// 둘 중 1개는 trap

                if (get_trap_state(local_state, n_st) != 1) {
                    if (e.first)
                        pq.push({ -(w + e.second.first),{local_state,n_ed} });
                }
                else {
                    if (!e.first)
                        pq.push({ -(w + e.second.first),{local_state,n_ed} });

                }
            }
            else if (!state[n_st] && state[n_ed]) {// 둘 중 1개는 trap

                if (get_trap_state(local_state, n_ed) != 1) {
                    if (e.first)
                        pq.push({ -(w + e.second.first),{local_state,n_ed} });;
                }
                else {
                    if (!e.first)
                        pq.push({ -(w + e.second.first),{local_state,n_ed} });
                }
            }



        }
    }
    return answer;
}
