#include <string>
#include <vector>
#include<iostream>
using namespace std;

int count(int num) { //몇자리 수 인가?   ex: 100> 3자리   10> 2자리   1> 1자리
    int ans = 1;
    while (num /= 10) {

        ans++;
    }
    return ans;
}

int func(vector<char> v, int n) {

    vector<char> prev;
    int len = v.size();
    int num = 0;

    for (int i = 0; i < v.size(); i += n) {
        vector<char> tmp;
        for (int j = i; j < i + n; j++) {
            tmp.push_back(v[j]);
        }
        if (i != 0) {
            if (tmp == prev) { //이전 문자열과 같다면
                len = len - n;   //반복횟수만큼 그 문자열을 제외하고
                num++;
            }
            else {
                if (num) { //만약 이전 문자열과 다른 문자열을 찾았다면
                    len += count(num + 1);    // 반복되는 문자열이 종료되면 반복횟수에 대한 길이를 추가.
                }
                num = 0;
            }
        }
        prev = tmp; //이전 문자열 저장.
    }
    if (num)len += count(num + 1); //예외처리. 마지막까지 반복이 일어난 경우
    return len;
}

int solution(string s) {
    int answer = 0;
    vector<char> v;

    answer = s.size();
    for (int i = 0; i < s.size(); i++)
        v.push_back(s[i]); //대입연산자 위해서

    for (int i = 1; i < s.size() / 2 + 1; i++) { //전체 길이의 절반이 넘는 문자열은 반복 불가하므로 제외.    
        int val = func(v, i);
        if (answer > val) answer = val;
    }
    return answer;
}