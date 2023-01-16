#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

bool compare(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
    return a.first > b.first;
}

map<string, pair<int, pair<int, int> > > ma;// {총 재생량, {Max_idx,secondMax_idx} }
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int max = -1, sec_max = -1;
    plays.push_back(-1);
    int init = plays.size() - 1;
    for (int i = 0; i < genres.size(); i++) {
        if (ma.count(genres[i]) == 0)
            ma[genres[i]] = { 0,{init,init} };
        ma[genres[i]].first += plays[i];

        if (plays[ma[genres[i]].second.first] < plays[i]) {
            ma[genres[i]].second.second = ma[genres[i]].second.first;
            ma[genres[i]].second.first = i;
        }
        else if (plays[ma[genres[i]].second.second] < plays[i])
            ma[genres[i]].second.second = i;
    }

    //총 재생량이 높은 장르가 먼저 -> 총 재생량으로 sort가 필요하다.
    //map은 기본적으로 key의 오름차순으로 정렬되있는 구조.
    //map을 value 값 기준 sort 불가능하다!! -> vector로 옮겨서 sort
    vector< pair<int, pair<int, int>> > v;
    for (auto m : ma) {
        v.push_back(m.second);
    }

    sort(v.begin(), v.end(), compare);//총 재생량의 내림차순 정렬.

    for (auto vec : v) {
        pair<int, pair<int, int> > val = vec;
        if (val.second.first != init) //max가 디폴트값( 갱신 x) 아니라면
            answer.push_back(val.second.first);
        if (val.second.second != init)//second max가 디폴트값 아니라면
            answer.push_back(val.second.second);
    }
    return answer;
}