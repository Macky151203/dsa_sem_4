#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;
struct Sum
{
    int li;
    int ri;
    int sum;
};
class Stock
{
    long int a[10010];

public:
    void readInput(int n)
    {
        ifstream fin;
        fin.open("input2.txt");
        for (int i = 0; i < n; i++)
            fin >> a[i];
        fin.close();
    }
    Sum FIND_MAX_CROSSING_SUBARRAY(int l, int m, int h, int &count)
    {
        Sum s;
        int left_max, right_max;
        left_max = INT_MIN;
        int sum = 0;
        for (int i = m; i >= l; i--)
        {
            sum += a[i];
            count++;
            if (sum > left_max)
            {
                left_max = sum;
                s.li = i;
            }
        }
        right_max = INT_MIN;
        sum = 0;
        for (int j = m + 1; j <= h; j++)
        {
            sum += a[j];
            count++;
            if (sum > right_max)
            {
                right_max = sum;
                s.ri = j;
            }
        }
        s.sum = left_max + right_max;
        return s;
    }
    Sum FIND_MAX_SUBARRAY(int l, int h, int &count)
    {
        Sum s;
        if (l == h)
        {
            s.li = l;
            s.ri = h;
            s.sum = a[l];
            return s;
        }
        else
        {
            int m = (l + h) / 2;
            Sum L, R, C;
            L=FIND_MAX_SUBARRAY(l, m, count);
            R=FIND_MAX_SUBARRAY(m + 1, h, count);
            C=FIND_MAX_CROSSING_SUBARRAY(l, m, h, count);
            if (L.sum >= R.sum && L.sum >= C.sum)
            {
                s.li = L.li;
                s.ri = L.ri;
                s.sum = L.sum;
                return s;
            }
            else if (R.sum >= L.sum && R.sum >= C.sum)
            {
                s.li = R.li;
                s.ri = R.ri;
                s.sum = R.sum;
                return s;
            }
            else
            {
                s.li = C.li;
                s.ri = C.ri;
                s.sum = C.sum;
                return s;
            }
        }
    }
    void MAX_SUBARRAY_BF2(int n, Sum &s, int &count)
    {
        int max_sum = INT_MIN, sum;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                count++;
                sum = sum + a[j];
                if (sum > max_sum)
                {
                    s.li = i;
                    s.ri = j;
                    max_sum = sum;
                    s.sum = sum;
                }
            }
        }
    }
};
int main()
{
    Stock s;
    Sum s2, s3;
    int count = 0, choice, n;
    int len[7] = {5, 50, 100, 500, 1000, 5000, 10000};
    do
    {
        cout << "\n1.Crossing Sub Array\n2.Brute force\n3.Exit\nEnter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < 7; i++)
            {
                n = len[i];
                s.readInput(n);
                count = 0;
                s2=s.FIND_MAX_SUBARRAY(0, n - 1, count);
                cout << "For input size=" << n << ", Number of comparisons:" << count << endl;
                cout << s2.li << " " << s2.ri << " " << s2.sum << endl;
            }
            break;
        case 2:
            for (int i = 0; i < 7; i++)
            {
                n = len[i];
                s.readInput(n);
                count = 0;
                s.MAX_SUBARRAY_BF2(n, s3, count);
                cout << "For input size=" << n << ", Number of comparisons:" << count << endl;
                cout << s3.li << " " << s3.ri << " " << s3.sum << endl;
            }
            break;
        default:
            exit(0);
        }
    } while (true);
}