#include <string>
#include <vector>

using namespace std;
int arr[101];
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int prev_left_day = -1;
    for (int i = 0; i < progresses.size(); i++) {
        int left_work = 100 - progresses[i];
        int left_day;
        if (left_work % speeds[i] != 0) //날짜가 나누어 떨어지 않으면 하루 더 해야한다.
            left_day = left_work / speeds[i] + 1;// 몇일을 더 일해야 완료가능한지
        else {//날짜가 나누어 떨어질 때
            left_day = left_work / speeds[i];
        }
        if (prev_left_day > left_day) left_day = prev_left_day;
        //이전 작업이 더 오래걸린다면 이전작업의 종료일로 종료일을 갱신
        arr[left_day]++; //종료 날짜에 종료된 작업 수 +1
        prev_left_day = left_day;
    }
    for (auto a : arr) {
        if (a != 0)
            answer.push_back(a);
    }
    return answer;
}
