#include<iostream>
using namespace std;
int cnt = 0,r,c,n;
int a = 1;

//4개의 사분면으로 나눈 뒤, 1, 2, 3, 4 사분면 탐색
void z(int w, int h,int len) { //왼쪽 위 꼭짓점, 길이
	
	if (0 > w || w >= a || 0 > h || h >= a)
		return;
	if (    ! ( ( w<=c&&c<w + len )&& (h<=r&& r<h + len)       )    ) {  //만약 내가 찾는 r,c가 이번에 탐색할 사분면 내부에
											        //없다면, 사분면안의 점의 수를 cnt에 더하고 스킵( 탐색x) 
		cnt += len * len;
		
		return;
	}

		
	if (len == 1) {   //최소단위 까지 자른 뒤 개수 센다. 
		cnt++;
		
		if (w == c && h == r)
			cout << cnt-1;
		return;
	}



	z(w, h, len / 2);
	z(w+ len / 2, h, len / 2);
	z(w, h+ len / 2, len / 2);
	z(w+ len / 2, h+ len / 2, len / 2);
	
	

	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> r >> c;
	
	for (int i = 0; i < n; i++)
		a *= 2;


	z(0, 0, a);

	
	
}
