#include <string>
#include <vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;


/*
int strtoint(string s) { //00:00:00 포맷 -> 초
    string sec = s.substr(6, 2);
    string min = s.substr(3, 2);
    string hour = s.substr(0, 2);

    int result = stoi(sec) + stoi(min) * 60 + stoi(hour) * 60 * 60;
    return result;
}

string inttostr(int i) { //초 -> 00:00:00 포맷
    int sec = i % 60;
    i /= 60;
    int min = i % 60;
    i /= 60;
    int hour = i;
    string result = "";
    if (hour < 10)result += "0";
    result += to_string(hour);
    result += ":";
    if (min < 10)result += "0";
    result += to_string(min);
    result += ":";
    if (sec < 10)result += "0";
    result += to_string(sec);

    return result;
}

*/


string decode(int num) {
    string ans;
    int st = num;
    int tmp;
    if (st / 3600) {
        tmp = st / 3600;
        if (tmp / 10 != 0) { //2자리수
            ans += (char)(tmp / 10) + 48;
        }
        else {
            ans += (char)48;
        }
        ans += (char)tmp % 10 + 48;
        st %= 3600;
    }

    else
        ans += "00";
    ans += ":";
    if (st / 60) {
        tmp = st / 60;
        if (tmp / 10 != 0) { //2자리수
            ans += (char)(tmp / 10) + 48;
        }
        else {
            ans += (char)48;
        }
        ans += (char)tmp % 10 + 48;
        // cout<<"chk2: "<<tmp/10<<" "<<tmp%10<<endl;
        st %= 60;
    }
    else
        ans += "00";

    ans += ":";

    if (st == 0) ans += "00";
    else {
        if (st / 10 != 0) {
            ans += (char)(st / 10) + 48;
        }
        else {
            ans += (char)48;
        }
        ans += (char)st % 10 + 48;
    }
    //  cout<<"chk3: "<<st/10<<" "<<st%10<<endl;
    return ans;
}

int parser_single(string str) {
    int tmp;
    int time = 0;
    int arr[3] = { 3600,60,1 };
    int t = 0;
    for (int i = 0; i < 8; i += 3) {
        string ss;
        tmp = 0;
        ss += str[i];
        ss += str[i + 1];
        time += stoi(ss) * arr[t++];
    }
    return time;
}

pair<int, int> parser(string str) {
    int tmp;
    int st = 0, ed = 0;
    int arr[3] = { 3600,60,1 };
    int t = 0;
    for (int i = 0; i < 8; i += 3) {
        string ss;
        tmp = 0;
        // tmp+= ( stoi(str[i])*10 +stoi(str[i+1]) );
        ss += str[i];
        ss += str[i + 1];
        st += stoi(ss) * arr[t++];
    }
    t = 0;
    for (int i = 9; i < 17; i += 3) {
        string sss;
        tmp = 0;
        sss += str[i];
        sss += str[i + 1];
        ed += stoi(sss) * arr[t++];
    }
    pair<int, int> time = { st,ed };
    return time;
}
int arr[360000];
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<int> st;
    vector<int> ed;
    vector<pair<int, int> > tl;
    pair<int, int> tmp;
    int adv = parser_single(adv_time);
    int play = parser_single(play_time);
    if (adv >= play) return "00:00:00";
    for (int i = 0; i < logs.size(); i++) {
        tmp = parser(logs[i]);
        int st = tmp.first, ed = tmp.second;
        for (int j = st; j < ed; j++) {
            arr[j]++;
        }
    }
    long long int sum = 0;
    for (int i = 0; i < adv; i++) {
        sum += arr[i];
    }
    long long int max = sum, max_point = 0;
    for (int i = 0; i + adv < play; i++) {
        int front = i, back = i + adv;
        int add_time = arr[back], del_time = arr[front];

        sum += (add_time - del_time);
        if (sum > max) {
            max = sum;
            max_point = i + 1;
        }

    }
    answer = decode(max_point);
    return answer;
}