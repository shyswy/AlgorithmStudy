#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;
queue<pair<int, int>> qu;//무게, 들어온 순간.
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;//truck_weights[0];
    int tmp = 0;
    int prev = 0;
    for (int i = 0; i < truck_weights.size(); i++) {
        if (sum + truck_weights[i] > weight) {
            while (sum + truck_weights[i] > weight) { //진입 불가.
                sum -= qu.front().first; // 가능할 때까지 맨 앞차를 빼고, 무게를 제외한다.
                tmp = qu.front().second + bridge_length; //빠져나간 차가 빠져나간 시간. 
                qu.pop();

            }
        }
        if (tmp < prev + 1) tmp = prev + 1; //바로 앞의 차를 기다리는 시간.
        qu.push({ truck_weights[i],tmp });
        sum += truck_weights[i];
        if (i == truck_weights.size() - 1)
            answer = tmp + bridge_length;
        prev = tmp;
    }
    return answer;
}