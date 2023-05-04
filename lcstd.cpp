#include<iostream>
#include<string.h>
using namespace std;
class lcs{
    char x[100],y[100],b[100][100];
    int c[100][100];
    int m,n;
    public:
        void input(){
            char s1[100],s2[100];
            cin>>s1;
            cin>>s2;
            m=strlen(s1);
            n=strlen(s2);
            for(int i=0;i<m;i++){
                x[i+1]=s1[i];
            }
            for(int i=0;i<n;i++){
                y[i+1]=s2[i];
            }
            for(int i=0;i<=m;i++){
                for(int j=0;j<=n;j++){
                    c[i][j]=-1;
                }
            }
            
        }
        int lcstd(int i,int j){
            if(c[i][j]>=0){
                return c[i][j];
            }
            if(i==0||j==0){
                c[i][j]=0;
                return c[i][j];
            }
            if(x[i]==y[j]){
                c[i][j]=lcstd(i-1,j-1)+1;
                b[i][j]='d';
                return c[i][j];
            }
            else{
                int t1,t2;
                t1=lcstd(i-1,j);
                t2=lcstd(i,j-1);
                if(t1>=t2){
                    b[i][j]='t';
                    c[i][j]=t1;
                   

                }
                else{
                    b[i][j]='l';
                    c[i][j]=t2;
                }
                return c[i][j];
            }
        }
        void print(int i,int j){
            if(i==0||j==0){
                return;
            }
            if(b[i][j]=='l'){
                print(i,j-1);
            }
            else if(b[i][j]=='t'){
                print(i-1,j);
            }
            else{
                print(i-1,j-1);
                cout<<x[i];
            }
        }

};
int main(){
    lcs l;
    l.input();
    int a=l.lcstd(5,7);
    cout<<a;
    l.print(5,7);
}