#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
map<int, int> visit; // visit[숫자]=해당 숫자 개수
priority_queue<int> front; //D 
priority_queue<int, vector<int>, greater<int>>  back; //D -1
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int f = 0, b = 0;
    int cnt = 0;
    for (auto op : operations) {
        if (op[0] == 'I') {
            string str = op.substr(2, op.size());
            int num = stoi(str);
            visit[num]++;
            front.push(num);
            back.push(num);
            cnt++;
            b++;
        }
        else if (op[0] == 'D') {
            if (cnt == 0) {
                // cout<<"queue empty ";

                continue;
            }
            if (op[2] == '1') { //erase max
                cnt--;
                int max = front.top(); 
                front.pop();
                while (!front.empty() && visit[front.top()] == 0) { //이미 지워진 값은 스킵
                    max = front.top();
                    front.pop();


                }
                visit[max]--;





            }
            else if (op[2] == '-') {//erase min
                cnt--;
                int min = back.top();
                back.pop();
                while (!back.empty() && visit[back.top()] == 0) {//이미 지워진 값은 스킵
                    min = back.top();
                    back.pop();
                }
                visit[min]--;

                //b--;


            }
        }
    }
    if (cnt == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {

        answer.push_back(front.top());
        answer.push_back(back.top());

    }
    return answer;
}

//f: 1,-1; (1제거)  -1     2,-1                 2,-1
//b: -1,1;          -1,1  -1,1,2   (-1제거)      1,2
//   f  b