#include<iostream>
#include<string.h>
using namespace std;
class Lcs{
    char x[100],y[100],b[100][100],B[100][100];
    int c[100][100],C[100][100];
    public:
        void input(int &M, int &N){
			// ifstream fin("lcs_input.txt");
			char s1[100],s2[100];
			cin>>s1;
			cin>>s2;
			x[0]=' ';
            int m=strlen(s1);
            int n=strlen(s2);
            M=m;
            N=n;
			for(int i=0;i<m;i++)
				x[i+1]=s1[i];
			y[0]=' ';
			for(int j=0;j<n;j++)
				y[j+1]=s2[j];
			for(int i=0;i<=m;i++){
				for(int j=0;j<=n;j++){
					C[i][j]=-1;
                }
			}
			// cout<<"X="<<x<<",Y="<<y<<":"<<endl;		
		}
        void lcs_bu(int m,int n){
            for(int i=0;i<=m;i++){
                c[i][0]=0;
            }
            for(int i=0;i<=n;i++){
                c[0][i]=0;
            }
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(x[i]==y[j]){
                        c[i][j]=c[i-1][j-1]+1;
                        b[i][j]='d';
                    }
                    else if(c[i-1][j]>=c[i][j-1]){
                        c[i][j]=c[i-1][j];
                        b[i][j]='t';
                    }
                    else{
                        c[i][j]=c[i][j-1];
                        b[i][j]='l';
                    }
                }
            }
            cout<<"max length- "<<c[m][n]<<endl;
        }

        int lcs_td(int i,int j){
            if(C[i][j]>=0){
                return C[i][j];
            }
            if(i==0||j==0){
                C[i][j]=0;
                return C[i][j];
            }
            if(x[i]==y[j]){
                C[i][j]=lcs_td(i-1,j-1)+1;
                B[i][j]='d';
                return C[i][j]; 
            }
            else{
				int t1,t2;
				t1=lcs_td(i-1,j);
				t2=lcs_td(i,j-1);
				
				if(t1>=t2){	
					C[i][j]=t1;
					B[i][j]='T';
				}
				else{
					C[i][j]=t2;
					B[i][j]='L';
				}
				return C[i][j];
			}
        }

        int lcs_dc(int i,int j){
            if(i==0||j==0){
                return 0;
            }
            if(x[i]==y[j]){
                return lcs_dc(i-1,j-1)+1;
            }
            else{
                int t1,t2;
                t1=lcs_dc(i-1,j);
                t2=lcs_dc(i,j-1);
                if(t1>=t2){
                    return t1;
                }
                else{
                    return t2;
                }
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
    int m,n;
    Lcs l;
    // m=5,n=7;
    l.input(m,n);
    l.lcs_bu(m,n);
    int x=l.lcs_td(m,n);
    cout<<x;
    l.print(m,n);
}