#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    ofstream fout1("Input10.txt");
    srand((long int)clock());
    for (int i = 0; i < 10; i++)
        fout1 << rand() % 6 << "\t";
    fout1.close();

    ofstream fout2("Input50.txt");
    srand((long int)clock());
    for (int i = 0; i < 50; i++)
        fout2 << rand() % 20 << "\t";
    fout2.close();

    ofstream fout3("Input100.txt");
    srand((long int)clock());
    for (int i = 0; i < 100; i++)
        fout3 << rand() % 40 << "\t";
    fout3.close();

    ofstream fout4("Input500.txt");
    srand((long int)clock());
    for (int i = 0; i < 500; i++)
        fout4 << rand() % 200 << "\t";
    fout4.close();

    ofstream fout5("Input1000.txt");
    srand((long int)clock());
    for (int i = 0; i < 1000; i++)
        fout5 << rand() % 400 << "\t";
    fout5.close();

    ofstream fout6("Input5000.txt");
    srand((long int)clock());
    for (int i = 0; i < 5000; i++)
        fout6 << rand() % 2000 << "\t";
    fout6.close();

    ofstream fout7("Input10000.txt");
    srand((long int)clock());
    for (int i = 0; i < 10000; i++)
        fout7 << rand() % 4000 << "\t";
    fout7.close();
}