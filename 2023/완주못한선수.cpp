#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;

//map 사용


map<string, int> ma;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (int i = 0; i < completion.size(); i++) ma[completion[i]]++;

    for (int i = 0; i < participant.size(); i++) ma[participant[i]]--;

    for (auto it : ma) {   //  it.first= key   it.second=value
        if (it.second < 0) answer = it.first;
    }

    /*
    auto 없이
    map<string, int>::iterator iter;
    for (iter = ma.begin(); iter != ma.end(); iter++) {
        iter->first,  iter->second
    }
    */
    return answer;
}