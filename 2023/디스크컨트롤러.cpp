#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
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
        int tLow = 987654321, lenLow = 0, min = 987654321, it = -1;
        for (int i = 0; i < low.size(); i++) {
            if (tLow > low[i][0])tLow = low[i][0];
            if (time >= low[i][0]) {
                if (min > low[i][1]) {
                    min = low[i][1];
                    it = i;

                }
            }
        }
        if (it == -1) {
            time = tLow;
        }
        else {
            //cout<<"st time: "<<time<<" end: "<<(time+min)<<endl;
            time += min;
            // cout<<time<<" "<<low[it][0]<<" "<<time-low[it][0]<<endl;
            answer += (time - low[it][0]);
            low.erase(low.begin() + it);
            //cout<<"sz: "<<low.size()<<endl;
        }



    }
    answer /= jobs.size();
    return answer;
}