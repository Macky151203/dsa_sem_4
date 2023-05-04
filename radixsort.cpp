#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
class RadixSort
{
    int A[10000];
    int B[10000];

public:
    int size;

    void readInput(int n)
    {
        if (n >= 10 && n < 100)
        {
            ifstream fin1("radix_2_digit.txt");
            for (int i = 1; i <= n; i++)
                fin1 >> A[i];
        }
        if (n >= 100 && n < 1000)
        {
            ifstream fin2("radix_3_digit.txt");
            for (int i = 1; i <= n; i++)
                fin2 >> A[i];
        }
        if (n >= 1000 && n <= 10000)
        {
            ifstream fin3("radix_4_digit.txt");
            for (int i = 1; i <= n; i++)
                fin3 >> A[i];
        }
    }

    void writeOutput(int n)
    {
        if (n >= 10 && n < 100)
        {
            ofstream fout1("radix_2_digit_output.txt");
            for (int i = 1; i <= n; i++)
                fout1 << B[i] << "\t";
            fout1.close();
        }
        if (n >= 100 && n < 1000)
        {
            ofstream fout2("radix_3_digit_output.txt");
            for (int i = 1; i <= n; i++)
                fout2 << B[i] << "\t";
            fout2.close();
        }
        if (n >= 1000 && n <= 10000)
        {
            ofstream fout3("radix_4_digit_output.txt");
            for (int i = 1; i <= n; i++)
                fout3 << B[i] << "\t";
            fout3.close();
        }
    }

    int maxArray(int n)
    {
        int max = A[0];
        for (int i = 1; i <= n; i++)
        {
            if (A[i] > max)
            {
                max = A[i];
            }
        }
        return max;
    }

    void Count_Sort(int n, int div, int &count)
    {
        int C[10];
        for (int i = 0; i <= 10; i++)
        {
            C[i] = 0;
        }
        // for any number the digits must be 0-9
        for (int i = 0; i <n; i++)
        {
            C[(A[i] / div) % 10]++;
            count++;
        }
        for (int i = 1; i <= 10; i++)
        {
            C[i] = C[i] + C[i - 1];
        }
        for (int i = n-1; i >= 0; i--)
        {
            B[C[(A[i] / div) % 10]-1] = A[i];
            C[(A[i] / div) % 10]--;
            count++;
        }
        for (int i = 0; i < n; i++)
        {
            A[i] = B[i];
        }
    }

    void Radix_Sort(int d, int &count)
    {
        int max = maxArray(d);
        for (int i = 1; max / i > 0; i *= 10)
        {
            Count_Sort(d, i, count);
        }
    }
};

int main()
{
    char option;
    int count;
    RadixSort R;
    do
    {
        cout << "\nEnter input array size : ";
        cin >> R.size;
        R.readInput(R.size);
        count = 0;
        R.Radix_Sort(R.size, count);
        cout << "\nSize = " << R.size << "  No. of comparisons : " << count;
        R.writeOutput(R.size);
        cout << "\nContinue(y/n)? : ";
        cin >> option;
    } while (option == 'y');
    cout << "\nProgram terminated...";
    return 0;
}