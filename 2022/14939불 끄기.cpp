//비트 마스킹
#include<iostream>
using namespace std;
bool arr[100][100];
bool origin[100][100];
char c;
int dx[5] = { 0, 0,1,0,-1 };
int dy[5] = { 0, 1, 0, -1, 0 };

//각 전구의 스위치는 최대 1번만 눌러야 최소 값 나온다 ( 2번누르면 원래대로 돌아감)
// 따라서 스위치를 누르는 순서는 결과에 영향이 없다!!



void click(int x, int y) {
	for (int i = 0; i < 5; i++) {
		if (!((0 > x + dx[i]) || (x + dx[i] >= 10) || (0 > y + dy[i]) || (y + dy[i] >= 10))) {//범위 밖으로 나간건 무시.
			//arr[x + dx[i]][y + dy[i]] = ( !(arr[x + dx[i]][y + dy[i]])  ); //클릭된곳 전부 뒤집기.(자신,상,하,좌,우)

			if (arr[x + dx[i]][y + dy[i]])
				arr[x + dx[i]][y + dy[i]] = false;
			else
				arr[x + dx[i]][y + dy[i]] = true;
		}
	}
}

int go() {
	int cnt = 0;
	for (int i = 1; i < 10; i++) {//첫줄은 앞에서 구함.
		for (int j = 0; j < 10; j++) {
			if (arr[i - 1][j]) {  //윗 전구 켜저있으면 무조건 꺼야한다.

				click(i, j);
				cnt++;

			}   //만약 윗줄이 꺼져있는데 누른다면, 윗줄을 켜버린다. 따라서 윗줄이 꺼져있으면 클릭하지 않는다.

		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			if (arr[i][j])return -1;// 하나라도 켜져있으면 전부 끄기 실패!
	}
	return cnt;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ans = 987654321, tmp, cnt2;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> c;
			c != '#' ? (arr[i][j] = true) : (arr[i][j] = false);
			origin[i][j] = arr[i][j];
		}
	}
	for (int bit = 0; bit < 1024; bit++) { // 2진수     0000000000 ~ 1111111111  ( 각 위치의 전구를 누르거나, 누르지 않거나 따져봄

		for (int i = 0; i < 10; i++) {         //경우의 수 완료 후 다시 배열 초기화 후 진행. 
			for (int j = 0; j < 10; j++) {

				arr[i][j] = origin[i][j];
			}
		}


		cnt2 = 0;//첫줄에 눌린 스위치 수
		//첫째 줄이 확정된 상태라면 ,다음 줄 부터는 윗줄의 전구를 끄는 경우의 수만 적용되야한다!
		//('모든 전구를 끌 경우의수'  윗줄을 다 못끈 상태에서 다음줄로 넘어가면 못 끈 윗줄을 끌 수 없게 된다.
		for (int i = 0; i < 10; i++) {// 각각 첫째 bit ~ 마지막 bit 만 추출한다.
			if (bit & (1 << i)) {//내가 눌리는 경우의수라면
				click(0, i);
				cnt2++;


			}
		}



		tmp = go();
		if (tmp != -1 && ans > (tmp + cnt2)) {
			ans = tmp + cnt2;
		}



	}

	if (ans != 987654321)
		cout << ans;
	else
		cout << -1;

}