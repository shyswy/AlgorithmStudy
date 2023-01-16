#include <string>
#include <vector>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;


struct Node { // 양방향 연결 리스트
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next) {}   //생성자
};


stack<Node*>  stk; //삭제된 노드를 저장하는 stack 자료구조
string solution(int n, int k, vector<string> cmd) {
    //string answer = "";
    string answer(n, 'X');
    Node* it = new Node(0, NULL, NULL); //각 개체는 생성 후 개별적인 객체로 유지됨. 포인터로 가르켜야한다 .


    Node* cur; //현재 위치를 가르키는 포인터.

    for (int i = 1; i < n; i++) {
        it->next = new Node(i, it, NULL);
        it = it->next;
        if (i == k)
            cur = it;
    }



    for (auto c : cmd) {
        if (c[0] == 'U') {
        
            int num = stoi(c.substr(2, 8));   
            while (num--) cur = cur->prev;
        }
        else if (c[0] == 'D') {
            int num = stoi(c.substr(2, 8));
            while (num--)cur = cur->next;
        }
        else if (c[0] == 'C') {
            stk.push(cur);
            if (cur->prev != NULL) cur->prev->next = cur->next;
            if (cur->next != NULL) cur->next->prev = cur->prev;
            if (cur->next == NULL) cur = cur->prev;
            else cur = cur->next;


        }
        else if (c[0] == 'Z') {
            if (!stk.empty()) {
                Node* tmp = stk.top();
                if (tmp->prev != NULL) tmp->prev->next = tmp;
                if (tmp->next != NULL) tmp->next->prev = tmp;
                stk.pop();
            }

        }
    }
    while (cur->prev != NULL)cur = cur->prev; //첫번째 연결 리스트로 위치 이동.
    while (cur != NULL) { //시작~ 끝 완전탐색.
        answer[cur->n] = 'O'; //삭제되지 않은 노드들을 표시한다.
        cur = cur->next;
    }
    return answer;
}