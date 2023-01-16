#include<vector>
#include<queue>
#include<iostream>
using namespace std;

queue<int> qu; // bfs 탐색.


int main() {
	int tmp;

	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		qu.push(tmp);
	}
	for (int i = 0; i < 3; i++) {
		cout << qu.front();
		qu.pop();
	}

	
	




	

	



}