#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
    ofstream outf1,outf2,outf3;
    int n;
    n=10000;
    srand((long int)clock());
    outf1.open("in.txt");
    outf2.open("asc.txt");
    outf3.open("dsc.txt");
    for(int i=0;i<n;i++){
        outf1<<rand()%30000<<"\t";
    }
    for(int i=0;i<n;i++){
        outf2<<i<<"\t";
    }
    for(int i=n;i>0;i--){
        outf3<<i<<"\t";
    }
    
    outf1.close();
    outf2.close();
    outf3.close();
    return 0;
}