#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High, int i = 0, int j = 0);
void Print(int** a, const int k, const int n, int i = 0, int j = 0);
int MinInRow(int** a, const int row, const int colCount, int j = 0);
int sum(int** a, int k, int n, int i = 0);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 5;
    int High = 51;
    int k, n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    cout << "sum = " << sum(a, k, n) << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High, int i, int j)
{
    if (i < k) {
        if (j < n) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, k, n, Low, High, i, j + 1);
        }
        else {
            Create(a, k, n, Low, High, i + 1, 0);
        }
    }
}

void Print(int** a, const int k, const int n, int i, int j)
{
    if (i < k) {
        if (j < n) {
            cout << setw(4) << a[i][j];
            Print(a, k, n, i, j + 1);
        }
        else {
            cout << endl;
            Print(a, k, n, i + 1, 0);
        }
    }
    else {
        cout << endl;
    }
}

int MinInRow(int** a, const int row, const int colCount, int j)
{
    if (j == colCount - 1) {
        return a[row][j];
    }
    else {
        int minValue = MinInRow(a, row, colCount, j + 1);
        return (a[row][j] < minValue) ? a[row][j] : minValue;
    }
}

int sum(int** a, int k, int n, int i)
{
    if (i == k) {
        return 0;
    }
    else {
        return MinInRow(a, i, n) + sum(a, k, n, i + 1);
    }
}