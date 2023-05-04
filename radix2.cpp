#include <iostream>
#include <fstream>
using namespace std;
class radixSort
{
    long int A[10010], B[10010];

public:
    void readInput(int n, int choice)
    {
        ifstream fin;
        switch (choice)
        {
        case 0:
            fin.open("Input10.txt");
            break;
        case 1:
            fin.open("Input50.txt");
            break;
        case 2:
            fin.open("Input100.txt");
            break;
        case 3:
            fin.open("Input500.txt");
            break;
        case 4:
            fin.open("Input1000.txt");
            break;
        case 5:
            fin.open("Input5000.txt");
            break;
        case 6:
            fin.open("Input10000.txt");
            break;
        }
        for (int i = 0; i < n; i++)
            fin >> A[i];
        fin.close();
    }
    void writeOutput(int n)
    {
        ofstream fout("radixSortOutput.txt");
        for (int i = 0; i < n; i++)
            fout << A[i]<<" ";
        fout.close();
    }
    void count_sort(int n, int k, float exp, int &count)
    {
        int C[k + 1];
        for (int i = 0; i <= k; i++)
            C[i] = 0;
        for (int j = 0; j < n; j++)
            C[(int)(A[j] / exp)%10]++;
        for (int i = 1; i <= k; i++)
            C[i] += C[i - 1];
        for (int j = n - 1; j >= 0; j--)
        {
            count++;
            B[C[(int)(A[j] / exp)%10] - 1] = A[j];
            C[(int)(A[j] / exp)%10]--;
        }
        for (int i = 0; i < n; i++)
            A[i] = B[i];
    }
    int maxValue(int n)
    {
        int max = A[0];
        for (int i = 1; i < n; i++)
        {
            if (A[i] > max)
                max = A[i];
        }
        return max;
    }
    void radix_sort(int n, int &count)
    {
        int max = maxValue(n);
        for (int i = 1; max / i > 0; i *= 10)
        {
            count_sort(n, 9, i, count);
        }
    }
};
int main()
{
    int choice, n, count;
    radixSort rs;
    int len[7] = {10, 50, 100, 500, 1000, 5000, 10000};
    int k[7] = {6, 20, 40, 200, 400, 2000, 4000};
    do
    {
        cout << "\n1.Count Sort\n2.Radix Sort\n3.Exit\nEnter option:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < 7; i++)
            {
                n = len[i];
                rs.readInput(n, i);
                count = 0;
                rs.count_sort(n, k[i], 0.1, count);
                cout << "For input size=" << n << ",Number of comparisons:" << count << endl;
                rs.writeOutput(n);
            }
            break;
        case 2:
            for (int i = 0; i < 7; i++)
            {
                n = len[i];
                rs.readInput(n, i);
                count = 0;
                rs.radix_sort(n, count);
                cout << "For input size=" << n << ",Number of comparisons:" << count << endl;
                rs.writeOutput(n);
            }
            break;
        default:
            exit(0);
        }
    } while (true);
}