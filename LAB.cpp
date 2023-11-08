#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
int sumDiagonal(int** matrix, int n, int m);

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int Low = 7;
    int High = 65;
    int n;

    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    int diagonalSum = sumDiagonal(a, n, n);
    cout << " sumDiagonal " << diagonalSum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int sumDiagonal(int** matrix, int n, int m)
{
    int diagonalSum = 0;

    int minDim = min(n, m);

    for (int i = 0; i < minDim; ++i)
    {
        diagonalSum += matrix[i][i];
    }

    return diagonalSum;
}
