#include<iostream>
#include<iomanip>
#define inf 99999
using namespace std;
class FM{
	int D[100][100],pi[100][100];
	int n;
	public:
		FM(int N){
			n=N;
		}
		void initialize(int W[][100]){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)
					D[i][j]=W[i-1][j-1];
			}
		}
		void Floyd_Warshall(int W[][100]){
			//n=5;
			initialize(W);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(D[i][j]==inf || i==j)
						pi[i][j]=0;
	 				else
						pi[i][j]=i;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(D[i][j]>D[i][k]+D[k][j] && pi[i][k]!=0 && pi[k][j]!=0){
							D[i][j]=D[i][k]+D[k][j];
							pi[i][j]=pi[k][j];
						}
					}
				}
			}
		}
		void ouput(){
			cout<<"\nD:"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)
					cout<<setw(7)<<D[i][j]<<" ";
				cout<<endl;
			}
			cout<<"\nPi:"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)
					cout<<setw(7)<<pi[i][j]<<" ";
				cout<<endl;
			}
		}
	
};
int main(){
	int n;
	int W[100][100];
	cout<<"Enter number of vertices:";
	cin>>n;
	cout<<"Enter the values in W(infinite=99999):\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>W[i][j];
	}
	cout<<"\nW:"<<endl;
	//int W[5][5]={0,3,8,inf,-4,inf,0,inf,1,7,inf,4,0,inf,inf,2,inf,-5,0,inf,inf,inf,inf,6,0};
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<setw(7)<<W[i][j]<<" ";
		cout<<endl;
	}
	FM fm(n);
	fm.Floyd_Warshall(W);
	fm.ouput();
}