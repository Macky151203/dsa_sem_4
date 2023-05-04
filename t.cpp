#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;
int count = 0;
class Sort
{
    int a[10010];

public:
    void readInput(int n, int choice)
    {
        ifstream fin;
        switch (choice)
        {
        case 1:
            fin.open("in.txt");
            break;
        case 2:
            fin.open("ascending.txt");
            break;
        case 3:
            fin.open("descending.txt");
        }
        for (int i = 0; i < n; i++)
        {

            fin >> a[i];
        }
        fin.close();
    }
    void writeOutput(int n)
    {
        ofstream fout("output.txt");
        for (int i = 0; i < n; i++)
            fout << a[i] << "\t"; // a[n-1-i]->descending
        fout.close();
    }
    int insertionSort(int n)
    {
        int count = 0, key, j;
        for (int i = 1; i < n; i++)
        {
            key = a[i];
            j = i - 1;
            count++;
            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j = j - 1;
                count++;
            }
            a[j + 1] = key;
        }
        return count;
    }
    void merge(int p, int q, int r, int &count)
    {
        int n1, n2;
        n1 = q - p + 1;
        n2 = r - q;
        int L[n1 + 1], R[n2 + 1];
        for (int i = 0; i <= n1; i++)
        {
            L[i] = a[p + i];
        }
        L[n1] = INT_MAX;
        for (int i = 0; i <= n2; i++)
        {
            R[i] = a[q + i + 1];
        }
        R[n2] = INT_MAX;
        int i = 0, j = 0;
        for (int k = p; k <= r; k++)
        {
            count++;
            if (L[i] <= R[j])
            {
                a[k] = L[i];
                i++;
            }
            else
            {
                a[k] = R[j];
                j++;
            }
        }
    }
    void mergeSort(int p, int r, int &count)
    {
        if (p < r)
        {
            int q = (p + r) / 2;
            mergeSort(p, q, count);
            mergeSort(q + 1, r, count);
            merge(p, q, r, count);
        }
    }
    void maxheapify(int i, int n, int &count)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest;
        int temp;
        if (l < n && a[l] > a[i])
        {
            largest = l;
            count++;
        }
        else
        {
            largest = i;
        }

        if (r < n && a[r] > a[largest])
        {
            largest = r;
            count++;
        }
        if (largest != i)
        {
            temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            maxheapify(largest, n, count);
        }
    }
    void buildmaxheap(int n, int &count)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            maxheapify(i, n, count);
        }
    }
    int heapsort(int &count)
    {
        int t;
        // int size=a.length();
        int n;
        n = sizeof(a) / sizeof(a[0]);
        buildmaxheap(n, count);
        for (int i = n - 1; i >= 1; i--)
        {
            t = a[i];
            a[i] = a[0];
            a[0] = t;
            maxheapify(i, 0, count);
        }
        return count;
    }
};
int main()
{
    int choice, n, count = 0;
    Sort s;
    int len[5] = {10, 50, 100, 500, 1000};
    do
    {
        cout << "\n1.Insertion Sort\n2.Merge Sort\n3.Exit\nEnter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nFor Random input:" << endl;
            for (int i = 0; i < 5; i++)
            {
                n = len[i];
                s.readInput(n, 1);
                count = s.insertionSort(n);
                s.writeOutput(n);
                cout << "For input size=" << n << ", Number of comparisons:" << count << endl;
            }
            cout << "\nFor Ascending-ordered input:" << endl;
            for (int i = 0; i < 5; i++)
            {
                n = len[i];
                s.readInput(n, 2);
                count = s.insertionSort(n);
                s.writeOutput(n);
                cout << "For input size=" << n << ", Number of comparisons:" << count << endl;
            }
            cout << "\nFor Descending-ordered input:" << endl;
            for (int i = 0; i < 5; i++)
            {
                n = len[i];
                s.readInput(n, 3);
                count = s.insertionSort(n);
                s.writeOutput(n);
                cout << "For input size=" << n << ", Number of comparisons:" << count << endl;
            }
            break;
        case 2:
            cout << "\nFor Random input:" << endl;
            for (int i = 0; i < 5; i++)
            {
                n = len[i];
                s.readInput(n, 1);
                count = 0;
                s.mergeSort(0, n - 1, count);
                s.writeOutput(n);
                cout << "For input size=" << n << ", Number of comparisons:" << count << endl;
            }
            cout << "\nFor Ascending-ordered input:" << endl;
            for (int i = 0; i < 5; i++)
            {
                n = len[i];
                s.readInput(n, 2);
                count = 0;
                s.mergeSort(0, n - 1, count);
                s.writeOutput(n);
                cout << "For input size=" << n << ", Number of comparisons:" << count << endl;
            }
            cout << "\nFor Descending-ordered input:" << endl;
            for (int i = 0; i < 5; i++)
            {
                n = len[i];
                s.readInput(n, 3);
                count = 0;

                s.mergeSort(0, n - 1, count);
                s.writeOutput(n);
                cout << "For input size=" << n << ", Number of comparisons:" << count << endl;
            }
            break;
        case 3:
            cout << "\nFor Random input:" << endl;
            for (int i = 0; i < 5; i++)
            {
                n = len[i];
                s.readInput(n, 1);
                count = 0;

                // n=a.size()/a.size(a[0]);
                s.heapsort(count);
                s.writeOutput(n);
                cout << "For input size=" << n << ", Number of comparisons:" << count << endl;
            }
            break;

        default:
            exit(0);
        }
    } while (true);
}