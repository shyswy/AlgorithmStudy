#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

queue<pair<int, int>> qu;//무게, 들어온 순간.
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;//다리에 들어온 시간.
    qu.push({ truck_weights[0],1 });
    int sum = truck_weights[0];
    int it = 0;
    int tmp;

    for (int i = 1; i < truck_weights.size(); i++) {
        while (sum + truck_weights[i] > weight) { //진입 불가.
            sum -= qu.front().first; // 가능할 때까지 맨 앞차를 빼고, 무게를 제외한다.

            tmp = qu.front().second + bridge_length; //빠져나간 차가 빠져나간 시간. 
            qu.pop();

        }
        qu.push({ truck_weights[i],tmp });
        sum += truck_weights[i];
        //cout<<sum<<endl;
    }
    while (!qu.empty()) {
        answer = qu.front().second + bridge_length;
        qu.pop();

    }


    return answer;
}