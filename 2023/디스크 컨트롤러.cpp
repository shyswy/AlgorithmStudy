#include <string>
#include <vector>
#include<queue>
using namespace std;
priority_queue<int> pq;
bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}
int solution(vector<vector<int>> jobs) {

    int time = 0;
    vector<vector<int>> low = jobs;
    int answer = 0;
    sort(low.begin(), low.end(), compare);

    while (!low.empty()) {
        int tLow = 0, lenLow = 0;
        for (int i = 0; i < low.size(); i++) {
            if (tLow > low[i][0]) tLow = low[i][0];
            if (lenLow > low[i][1]) lenLow = low[i][1];


            if (time >= low[i][0]) {
                time += low[i][1];
                low.erase(low.begin() + i);
            }
        }
        if (time < tLow) { //현재 요청 수행 할 거 없다면, 가장 빨리 들어온 요청 수행
            time = tLow;
            answer = time +
        }
        else {

        }


    }
    return answer;
}