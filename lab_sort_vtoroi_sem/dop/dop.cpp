#include<iostream>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

using namespace std;
int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, m, a[100][100];
    int temp = 0;
    cout << "Строки: ";
    cin >> n;
    cout << "Столбцы: ";
    cin >> m;

    system("cls");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 100;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            for (int i1 = 0; i1 < n - i - 1; i1++)
            {
                for (int j1 = 0; j1 < m - j - 1; j1++) {
                    if (i == j + 1 || i + 1 == j || i == j)
                    {
                        if (a[i1][j1] > a[i1 + 1][j1 + 1]) {
                            temp = a[i1][j1];
                            a[i1][j1] = a[i1 + 1][j1 + 1];
                            a[i1 + 1][j1 + 1] = temp;
                        }
                    }
                }
            }
        }

    cout << "\n" << "Итог" << "\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
