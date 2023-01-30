#include <string>
#include <vector>
#include<unordered_set>
#include<iostream>
using namespace std;
unordered_set<int> s[9]; //s[k] -> k개의 N으로 만들 수 있는 수의 모음
int num(int n, int t) {
    int sum = 0;
    for (int i = 0; i < t; i++) {
        sum += n;
        n *= 10;
    }
    return sum;
}
int solution(int N, int number) {
    int answer = 0;

    for (int i = 1; i <= 8; i++) {
        s[i].insert(num(N, i)); // s[k] 에 k개의 N을 이어 붙이는 경우의 수 추가
    }

    //   N을 5개 쓰는 수:   3개 + 2개 ->   2+1개 + 1+1개 ->  ( (1+1)+1 ) + (1+1)
    //이렇게 모든 경우의 수를 dp로 찾을 수 있다.

    for (int k = 1; k <= 8; k++) {
        for (int i = 1; i < k; i++) {   // 8를 만들 수 있는 2가지 경우의 수 선택
            int j = k - i;
            for (auto si : s[i]) {
                for (auto sj : s[j]) {
                    s[k].insert(si + sj); //+
                    if (si - sj > 0) s[k].insert(si - sj); //-
                    s[k].insert(si * sj);//*
                    if (si / sj > 0)s[k].insert(si / sj);// 나누기
                }
            }

        }
    }
    for (int i = 1; i <= 8; i++) {
        if (s[i].find(number) != s[i].end()) return i;
    }
    return -1;
}