#include <string>
#include <vector>
#include<iostream>
using namespace std;



long long  sum_total(vector<int> del) {
    int sum = 0;
    for (int i = 0; i < del.size(); i++) sum += del[i];
    
    return sum;


}

int endpoint_del(vector<int> del) { //할당량 남은 가장 끝집.
    for (int i = del.size() - 1; i >= 0; i--) {
        if (del[i] != 0)  return i;
    }
    return -1;// 할당량 남은 끝집 x 
}
int endpoint_pick(vector<int>pick) {
    for (int i = pick.size() - 1; i >= 0; i--) {
        if (pick[i] != 0)  return i;
    }
    return -1;
}



long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long  ep_del = endpoint_del(deliveries), ep_pick = endpoint_pick(pickups);
    long long  cy_len;
    long long  rem;
    int total = sum_total(deliveries);
    if (total > cap) rem = cap;
    else { rem = total; }

    while (ep_del != -1 || ep_pick != -1) { //수거, 택배 모두 종료시까지 
        ep_del = endpoint_del(deliveries), ep_pick = endpoint_pick(pickups);
        // cout<<ep_del<<" "<<ep_pick<<endl;
        if (ep_del < ep_pick) cy_len = ep_pick;
        else cy_len = ep_del;
        cout << total << " ";
        if (total > cap) rem = cap;
        else { rem = total; }

        if (total < 0) total = 0;

        while (rem > 0 && ep_del != -1) { //택배 다 전달할 때 까지 뒤에서부터 전달  

            if (deliveries[ep_del] <= rem) {
                rem -= deliveries[ep_del];
                total -= deliveries[ep_del];
                deliveries[ep_del] = 0;
                
            }
            else {
                deliveries[ep_del] -= rem;
                total -= rem;
                rem = 0;


            }
            ep_del = endpoint_del(deliveries);

        }
        rem = 0;
        while (rem < cap && ep_pick != -1) {


            if ((pickups[ep_pick] + rem) <= cap) {
                rem += pickups[ep_pick];
                pickups[ep_pick] = 0;



            }
            else {
                pickups[ep_pick] -= (cap - rem);
                rem = cap;


            }
            ep_pick = endpoint_pick(pickups);

        }

        answer += (cy_len + 1) * 2;
    }







    return answer;
}

int main() {



    int a = 1;
    int b = 7;
    vector<int> d = { 0, 0, 1, 0, 1, 0,0 }, p = { 0, 0, 0, 0, 0, 0, 3 };
    cout << solution(a, b, d, p);
        
}