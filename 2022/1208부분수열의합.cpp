#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
//�������� ���� ��� �κ��� ���ѵ�, �� �׷캰 1���� �̾�

//https://blog.naver.com/gmlwo308/222081888774
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, s,tmp;
	cin >> n >> s;
	int m = n / 2;
	vector<int> l, r,la,ra;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		l.push_back(tmp);
		
	      
	}
	for (int i = m ; i < n; i++) {
		cin >> tmp;
		r.push_back(tmp);
	}
	for (int i = 0; i < (1 << l.size());i++) {  //2^n�� ��� �κ����� ã�� ���� 
		int sum = 0;
		
		for (int j = 0; j < l.size(); j++) {
			if (   i & 1<<j ) {//�ش� ��Ʈ�� ���������� 0 �� �ƴ� ���� ���´�!  ( 1x )
				sum += l[j];
			}
		}
		la.push_back(sum);
	}


	for (int i = 0; i < (1 << r.size()); i++) {  //2^n�� ��� �κ����� ã�� ���� 
		int sum = 0;
		
		for (int j = 0; j < r.size(); j++) {
			if ((i & 1<<j) ) {
				sum += r[j];
			}
		}
		ra.push_back(sum);
	}

	sort(ra.begin(), ra.end());// ���� Ž�� ���� ������ ���� ����

	long long  ans = 0;
	for (long long  i : la) {    //   s-i + i ==s      s-i��   ���� ���հ� ������ S�ϼ��Ǵ� ��
		auto l = lower_bound(ra.begin(),ra.end(), s - i); //s-i�� ���ų� ū �� �� ������ ù ��ġ
		auto u = upper_bound(ra.begin(),ra.end(), s - i); //s-i���� ū �� �� ������ ù��ġ
		ans += u - l;   //upperbound-lower bound �� ra���� ���� s-i�� ���� ����. 
	}
	if (s == 0)
		ans -= 1;
	cout << ans << endl;
	
	
}


//�ٸ����
	//�� �������� 2����Ʈ �˰���      
	//         -5 -2 0  2 3 6 8    1
	//ex) la��  -2, 0, 2, 5   ������� ��, ����  la�� ù°����(-2) �� ra�� i°���� ���� S���� ũ�ٸ�, la�� ��°����(0) ���� �յ�
	//S���� ũ�� ������ la�� �����Ű�鼭 ra�� ���Ҹ� ���� ��ų �� �ִ�( la �� �ε����� �����ϸ鼭 ������ ���� �� ���� ra�� �ش���ҿ�
	//�������� S���� Ŀ���� ������ ���� �� ����)