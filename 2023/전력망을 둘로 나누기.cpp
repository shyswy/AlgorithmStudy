#include <string>
#include <vector>
#include<iostream>
using namespace std;
int parent[101];
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void join(int x, int y) {
    int p_x = find(x), p_y = find(y);
    parent[p_x] = p_y;

}
int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int min = 987654321;
    for (int k = 0; k < wires.size(); k++) {
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        int a, b, dif = 0;
        for (int i = 0; i < wires.size(); i++) {//k째 전선 빼고 연결

            if (i == k) {

                a = wires[i][0], b = wires[i][1];//a,b 간선제거 -> 트리가 나눠지는 2개 노드
              //  cout<<"disconnect: "<<a<<" "<<b<<endl;

                continue;
            }
            join(wires[i][0], wires[i][1]);
        }
        a = find(a);
        b = find(b);
        //  cout<<a<<" "<<b<<endl;
        for (int i = 1; i <= n; i++) {

            if (find(i) == a) dif++;
            else if (find(i) == b) dif--;
            // else cout<<"error!"<<endl;


        }
        //cout<<"dif "<<dif<<endl;
        if (dif < 0) dif = (-1) * dif;
        // cout<<"dif2 "<<dif<<endl;

        if (dif < min)min = dif;


    }
    answer = min;
    return answer;
}