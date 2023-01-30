#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<string, vector<string>> ma;
int ans_size;
int cnt = 0;
vector<string> aa;
map<string, int> num;
bool dfs(map<string, int> visit, string now, int depth, vector<string> path) {

    if (depth == ans_size) { //처음 구해진 답이 정답. 이후부턴 탐색할 필요 x 
        aa = path;


        return true;
    }
    for (auto to : ma[now]) {

        string edge = now + to;
        if (visit[edge] >= num[edge]) continue;
        map<string, int> local_visit = visit;
        vector<string> local_path = path;
        local_visit[edge]++;
        local_path.push_back(to);

        if (dfs(local_visit, to, depth + 1, local_path)) {// 정답을 찾은 뒤론 더이상 탐색 x
            return true;
        }
    }
    return false;


}


vector<string> solution(vector<vector<string>> tickets) {

    vector<string> answer;

    ans_size = tickets.size();
    for (auto t : tickets) {
        ma[t[0]].push_back(t[1]);
        num[t[0] + t[1]]++;// 해당 항공권의 개수 저장.
    }
    for (auto a : ma) {//각 key(출발지) 마다 목적지의 사전순 정렬.
        sort(a.second.begin(), a.second.end());
        ma[a.first] = a.second;

    }



    map<string, int> vis;
    vector<string> pat;
    pat.push_back("ICN");
    dfs(vis, "ICN", 0, pat);
    answer = aa;


    return answer;
}