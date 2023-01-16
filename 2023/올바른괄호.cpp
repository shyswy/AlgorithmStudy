#include<string>
#include <iostream>
#include<stack>
#include<vector>
using namespace std;

stack<char> stk;
vector<char> v;
bool solution(string s)
{
    bool answer = true;
    for (auto c : s) {
        if (c == '(')
            stk.push(c);
        else {
            if (!stk.empty())
                stk.pop();
            else {
                answer = false; //')'에 대한 '(' 가 없다.
                break;
            }
        }
    }
    if (!stk.empty()) answer = false; //'(' 에 대한 ')' 가 부족하다. 
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}