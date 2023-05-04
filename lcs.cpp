#include<iostream>
#include <iomanip>
#include<fstream>
using namespace std;
class LCS{
	char X[100],Y[100],b[100][100],B[100][100];
	int c[100][100],C[100][100];
	public:
		void input(int m,int n){
			// ifstream fin("lcs_input.txt");
			char s1[100],s2[100];
			cin>>s1;
			cin>>s2;
			X[0]=' ';
			for(int i=0;i<m;i++)
				X[i+1]=s1[i];
			Y[0]=' ';
			for(int j=0;j<n;j++)
				Y[j+1]=s2[j];
			for(int i=0;i<=m;i++){
				for(int j=0;j<=n;j++)
					C[i][j]=-1;
			}
			cout<<"X="<<X<<",Y="<<Y<<":"<<endl;		
		}
		void LCS_LENGTH_BU(int m,int n,int& count){
			for(int j=0;j<=n;j++)
				c[0][j]=0;
			for(int i=1;i<=m;i++)
				c[i][0]=0;	
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					count++;
					if(X[i]==Y[j]){
						c[i][j]=c[i-1][j-1]+1;
						b[i][j]='D';
					}
					else if(c[i-1][j]>=c[i][j-1]){
						c[i][j]=c[i-1][j];
						b[i][j]='T';
					}
					else{
						c[i][j]=c[i][j-1];
						b[i][j]='L';
					}
				}
			}
			//output(m,n);
			cout<<"Max length:"<<c[m][n]<<endl;
		}
		void PRINT_LCS(int i,int j){
			if(i==0 || j==0)
				return;
			if(b[i][j]=='D'){
				PRINT_LCS(i-1,j-1);
				cout<<X[i];
			}
			else if(b[i][j]=='T')
				PRINT_LCS(i-1,j);
			else
				PRINT_LCS(i,j-1);
		}
		int LCS_LENGTH_TD(int i,int j,int& count){
			if(C[i][j]>=0)
				return C[i][j];
			if(i==0||j==0){
				C[i][j]=0;
				return C[i][j];
			}
			count++;
			if(X[i]==Y[j]){
				C[i][j]=LCS_LENGTH_TD(i-1,j-1,count)+1;
				B[i][j]='D';
				return C[i][j];
			}
			else{
				int t1,t2;
				t1=LCS_LENGTH_TD(i-1,j,count);
				t2=LCS_LENGTH_TD(i,j-1,count);
				
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
		int LCS_LENGTH_DC(int i,int j,int& count){
			if(i==0||j==0)
				return 0;
			count++;
			if(X[i]==Y[j])
				return LCS_LENGTH_DC(i-1,j-1,count)+1;
			else{
				int t1,t2;
				t1=LCS_LENGTH_DC(i-1,j,count);
				t2=LCS_LENGTH_DC(i,j-1,count);
				if(t1>=t2)
					return t1;
				else
					return t2;
			}
		}
		void output(int m,int n){
			cout<<"b:"<<endl;
			for(int i=0;i<=m;i++){
				for(int j=0;j<=n;j++)
					cout<<setw(4)<<c[i][j];
				cout<<endl;
			}
			cout<<"\nc:"<<endl;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++)
					cout<<setw(2)<<b[i][j];
				cout<<endl;
			}
		}
		void output2(int m,int n){
			cout<<"b:"<<endl;
			for(int i=0;i<=m;i++){
				for(int j=0;j<=n;j++)
					cout<<setw(4)<<C[i][j];
				cout<<endl;
			}
			cout<<"\nc:"<<endl;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++)
					cout<<setw(2)<<B[i][j];
				cout<<endl;
			}
		}
};
int main(){
	LCS l;
	int m,n,count;
	// int L[6]={5,7,10,12,15,17};
	
			m=5;n=7;
			
				cout<<"\n\nFor m="<<m<<",n="<<n<<",";
				l.input(m,n);
				count=0;
				cout<<"\nDivide and conquer approach:"<<endl;
				cout<<"Max length:"<<l.LCS_LENGTH_DC(m,n,count)<<endl;
				cout<<"Number of comparisons:"<<count<<endl;
				cout<<"\n\nDynammic Programming using bottom up:"<<endl;
				count=0;
				l.LCS_LENGTH_BU(m,n,count);
				cout<<"Number of comparisons:"<<count<<endl;
				cout<<"Longest Common Subsequence:";
				l.PRINT_LCS(m,n);
				cout<<"\n\n\nDynammic Programming using top down:"<<endl;
				count=0;
				int x=l.LCS_LENGTH_TD(m,n,count);
				// l.output2(m,n);
				cout<<"Max length:"<<x<<endl;
				cout<<"Number of comparisons:"<<count<<endl;
			
		
}
//CCBBC
//CACAABC