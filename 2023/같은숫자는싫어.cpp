#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr[0]); //최초 값 삽입
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i + 1] != arr[i])
            answer.push_back(arr[i + 1]); //다른 값이 나오면 추가

    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    return answer;
}