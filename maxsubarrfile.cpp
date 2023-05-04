#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    ofstream outf;
    srand((long int)clock());
    outf.open("input2.txt");
    for (int i = 0; i < 10000; i++)
    {
        int num = rand() % 30;
        if (rand() % 2 == 0)
            outf << num * -1 << "\t";
        else
            outf << num << "\t";
    }
    outf.close();
}