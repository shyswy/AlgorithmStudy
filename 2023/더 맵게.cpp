#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;
vector<int> v;
priority_queue<int> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(-scoville[i]);
    }
    while (!pq.empty()) {
        int lowest = -pq.top();
        int mix = -1;

        if (lowest >= K) break;
        while (!pq.empty() && mix < K) {
            mix = -pq.top();
            pq.pop();
            if (pq.empty()) return -1;
            mix -= 2 * pq.top();

            pq.pop();
            pq.push(-mix);

            answer++;
        }
    }

    return answer;
}