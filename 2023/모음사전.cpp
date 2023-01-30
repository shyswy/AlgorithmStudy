#include <string>
#include <vector>
#include<iostream>
#include<map>
using namespace std;
map<char, int> parse;
int num[5] = { 781,156,31,6,1 };
int solution(string word) {
    int answer = 0;
    vector<int> v;
    parse['A'] = 0;
    parse['E'] = 1;
    parse['I'] = 2;
    parse['O'] = 3;
    parse['U'] = 4;
    for (int i = 0; i < word.size(); i++) {
        int tmp = parse[word[i]];
        answer += (num[i] * tmp + 1);
    }
    return answer;
}

//1562
//781  (문자)+ 5^4 (4자리) + 5^3 + 5^2+ 5^1  ( 1자리) =780+1( 해당 문자 1개만)
//
// A (1~ 780 )    E(781~ 1560)

//AAAAA
//A~~~

//E~~~~

//AEAEA

//A:0, E:1 , I: 2 , O:3, U:4

// 맨 뒤:() 1+1+1+1 +(1)  +1

// 2번쨰: 1+1+1+1+ (5)  +1 -> 4째자리에서 Ax 수-> 마지막자리 미정+ 마지막자리 없는 경우
//(AAAA)


// ( 5^4+5^3+5^2+5 (+1) ) *2 +1
// 

//1* 781 +1   + 2*156+1     +3*31 +1
// 781  312   93
//1093+93     

//781*1+1   + 156*2+1

// +1 +1 +1 +1
