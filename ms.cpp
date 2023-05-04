#include <iostream>
#include <limits.h>
using namespace std;
void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int l[n1 + 1];
    int R[n2 + 1];
    for (int i = 0; i < n1; i++)
    {
        l[i] = a[p + i];
    }
    l[n1] = INT_MAX;
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[q + j + 1];
    }
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    for (int k = p; k < r; k++)
    {
        if (l[i] <= R[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int A[] = {45, 32, 76, 22, 90, 12, 87, 34, 56};
    mergeSort(A, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << A[i] << '\t';
    }
}
