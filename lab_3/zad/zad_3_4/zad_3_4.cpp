#include<stdio.h>
#include<math.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, t, i, players[1000], count, k = 1;
	printf("������� ���������� �������: ");
	scanf_s("%d", &n);
	printf("������� ����: ");
	scanf_s("%d", &m);
	printf("������� ����� ������, � �������� ���������� ����: ");
	scanf_s("%d", &t);
	count = m;
	if (t >= n || n<=5) printf("��������� ������������ ��������� ������");
	else {
		for (int i = 1; i <= n; i++) {
			players[i] = i;
		}
		while (k <= n) {
			for (i = t; i <= n; i++) {
				count--;
				if (players[i] == 0) count++;
				if (count == 0) {
					if (k <= 5) printf("����� ����� %d �����.\n", i);
					if (k == n)
					{
						printf("����������� ���������� ������� ��� ������� %d.\n", i);
						k++;
						break;
					}
					k++;
					players[i] = 0;
					count = m;
				}
			}
			t = 1;
		}
	}
	return 0;
}