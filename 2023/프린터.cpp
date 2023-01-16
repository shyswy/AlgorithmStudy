#include <string>
#include <vector>
#include<queue>
using namespace std;
vector<pair<int, int>> v;

priority_queue<int> pq;
queue<pair<int, int> > qu;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++) {
        qu.push({ priorities[i],i });
        pq.push(priorities[i]);
    }

    while (!pq.empty()) {
        int max = pq.top();
        pair<int, int> front = qu.front();
        if (max > front.first) {
            qu.pop();
            qu.push(front);
        }
        else {//가장 중요도 높은 문서 출력
            answer++;
            if (front.second == location) //원하는 문서 찾으면 종료.
                break;
            pq.pop();
            qu.pop();
        }
    }


    return answer;
}