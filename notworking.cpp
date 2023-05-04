#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class LCS
{
    char X[100], Y[100], b[100][100], B[100][100];
    int c[100][100], C[100][100];
    int m, n;

public:
    void input(int &M, int &N)
    {
        cout << "Enter first sequence:";
        cin >> X;
        cout << "Enter second sequence:";
        cin >> Y;
        m = strlen(X);
        n = strlen(Y);
        M = m;
        N = n;
        for (int i = m; i >= 1; i--)
        {
            X[i] = X[i - 1];
        }
        X[0] = ' ';
        for (int i = n; i >= 1; i--)
        {
            Y[i] = Y[i - 1];
        }
        Y[0] = ' ';
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                C[i][j] = -1;
            }
        }
    }
    int LCS_BUP()
    {
        for (int i = 0; i <= m; i++)
        {
            c[i][0] = 0;
        }
        for (int j = 0; j <= n; j++)
        {
            c[0][j] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (X[i] == Y[j])
                {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    b[i][j] = 'D';
                }
                else if (c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 'T';
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 'L';
                }
            }
        }
        return c[m][n];
    }
    void print(int i, int j)
    {
        if (i == 0 || j == 0)
            return;
        else if (b[i][j] == 'D')
        {
            print(i - 1, j - 1);
            cout << X[i];
        }
        else if (b[i][j] == 'T')
        {
            print(i - 1, j);
        }
        else
        {
            print(i, j - 1);
        }
    }
    void display()
    {
        cout << "C:";
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << c[i][j]<<" ";
            }
            cout << endl;
        }
        cout << "B:";
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << b[i][j]<<" ";
            }
            cout << endl;
        }
    }
};
int main()
{
    LCS l;
    int m, n;
    l.input(m, n);
    int lenght = l.LCS_BUP();
    cout << "lenght=" << lenght << endl<<endl;
    l.print(m, n);
    l.display();
}