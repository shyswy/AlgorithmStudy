


#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), cmp);
    int f = 0, b = people.size() - 1;
    int sum = 0;

    while (f <= b) {

        if (f == b) {// 1개남음
            answer++;
            break;
        }
        if (people[f] + people[b] <= limit) {
            f++;
            b--;
        }
        else {
            f++;
        }
        answer++;
    }






    return answer;
}

//80 70 50 50
//80 <> 50 x
//100  1 2 3 4,,,, 8

//90 89  10 1

//90 70  30 10
// 50 50 10 20 20
//제일 무거운 사람부터 가장 많은 사람과 탈 수 있게.( 같은 수면 무거운 사람을 포함)
//





//max 2개 제한 x 시..? 하려했

#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), cmp);
    int f = 0, b = people.size() - 1;
    int sum = 0;

    int back = people.size() - 1;
    for (int i = 0; i < people.size(); i++) {
        if (i == back) {
            answer++;
            break;
        }
        sum = people[i];

        for (back; back > i; back--) {
            if (sum + people[back] < limit) {
                sum += people[back];
            }
            else {
                back++;
                answer++;
                break;
            }
        }
    }




    return answer;
}