#include<iostream>
#include<iomanip>
#define inf 99999
using namespace std;
class fw{
    int d[100][100],pi[100][100];
    public:
        void ini(int w[][100],int n){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    d[i][j]=w[i-1][j-1];
                }
            }
        }
        void floyd(int w[][100], int n){
            ini(w,n);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(d[i][j]==inf || i==j){
                        pi[i][j]=0;
                    }
                    else{
                        pi[i][j]=i;
                    }
                }
            }

            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(d[i][j]>(d[i][k]+d[k][j]) && pi[i][k]!=0 && pi[k][j]!=0){
                            d[i][j]=d[i][k]+d[k][j];
                            pi[i][j]=pi[k][j];
                        }
                    }
                }
            }
            
        }
        void output(int n){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<d[i][j]<<"  ";
                }
                cout<<endl;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<pi[i][j]<<"  ";
                }
                cout<<endl;
            }
        }
};
int main(){
    int x[100][100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x[i][j];
        }
    }
    fw w;
    w.floyd(x,n);
    w.output(n);
}