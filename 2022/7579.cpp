#include<iostream>
#include<algorithm>
using namespace std;
//knapsack �� �ּҺ������ ���¼��� ����������.
int N, M, ans, sum;
int b[101], c[101];
int dp[101][10001];

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) cin >> b[i];
	for (int i = 1; i <= N; i++)
	{
		cin >> c[i];
		sum += c[i];
	}

	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j - c[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + b[i]);

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum; i++)//���� ���> ���� ��� Ž��
	{
		if (dp[N][i] >= M)//M�̻��� �޸� ������ ����( ������� ã�������� �ּҺ��)
		{
			cout << i << endl;
			break;
		}
	}


}