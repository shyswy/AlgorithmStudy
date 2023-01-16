#include<iostream>
using namespace std;
char lst[1000001];




//  i째부터 해서 Pn 찾으면,  i+1 부터 탐색하는 것이 아닌, Pn이 끝나는 위치부터 탐색하고 앞의 IO 1개 없다고 치자.
//ex) n=2 
//IOIOIOI  >> IOIOI 찾고 나서 앞을 날리자   IO / IOI   > 계속해서 찾기시작
//IO / IOI OI  >> 다시 n=2 완성. .... 이렇게 O(N)으로 가능.


int main() {
	int n, L,ans=0;
	cin >> n >> L;
	for (int i = 0; i < L; i++) {
		cin >> lst[i];

	}
	for (int i = 0; i < L; i++) {
		int num = 0;
		if (lst[i] == 'I'&&lst[i+1]=='O') { // IO 스타트 이후로  해당 O 부터 OI , OI ... OI 쌍의 수 를 num에 누적.
			while (lst[i+1] =='O'&& lst[i + 2]=='I'&&i<L) {
				i += 2;
				num++;
				if (num == n) {
					num--;
					ans++;
				}
			}

		}

	}
	cout << ans;
		
}