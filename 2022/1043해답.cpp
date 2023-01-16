

//������ �Ҽ� �ִ� ��Ƽ�� �ִ밪��>> ������ �ƴ� ����� 1���̶� ��Ƽ���� ���� ����� ���ִ� ��Ƽ�� ���� �Ȱ�����.
//��� �Է� �ް� �� ��, �ٽ� �� ��Ƽ�� Ȯ���ϸ� �ش���Ƽ�� ��� ��Ƽ ������ ���Ǿƴ� ����� 1���̶� ������ ����. 



#include <iostream>
using namespace std;
int n, m, rn; //�����, ��Ƽ��, ���ǻ�� ��
int par[51], isTrue[51], party[51][51];//�θ�,���ǻ��,��Ƽ���

int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void uni(int x, int y) { par[find(y)] = find(x); }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; // �����, ��Ƽ��
    cin >> rn; // ���� ��
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 0; i < rn; i++) cin >> isTrue[i]; //���� ���
    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        cin >> party[i][0];
        for (int j = 1; j <= num - 1; j++) {
            cin >> party[i][j]; //i��° ��Ƽ�� j�� ������
            uni(party[i][0], party[i][j]); //0�� �����ڿ� ���Ͽ�
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        bool ok = true;
        for (int j = 0; j < rn; j++) {
            //���ǵ� ��� ������
            if (find(party[i][0]) == find(isTrue[j])) {
                ok = false; break;
            }
        }
        if (ok) cnt++; //������ +1
    }
    cout << cnt << '\n';
}