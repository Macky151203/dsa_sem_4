#include<iostream>
#include<limits.h>
using namespace std;
class MCM{
	int m[100][100],s[100][100];
	public:
		void Bottom_Up_MCM(int P[],int l){
			int n=l-1,x=INT_MAX,q,j;
			for(int i=1;i<=n;i++){
				m[i][i]=0;
			}		
			for(int l=1;l<=n-1;l++){
				for(int i=0;i<n-l;i++){
					j=i+l;
					m[i][j]=INT_MAX;
					for(int k=i;k<j;k++){
						q=m[i][k]+m[k+1][j]+P[i]*P[k+1]*P[j+1];
						if(m[i][j]>q){
							
							s[i][j]=k+1;
							m[i][j]=q;
						}
					}	
				}
			}	
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<m[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<s[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void OPT_PAR(int i,int j){
			if(i==j)
				cout<<" A"<<i<<" ";
			else{
				cout<<"(";
				OPT_PAR(i,s[i-1][j-1]);
				OPT_PAR(s[i-1][j-1]+1,j);
				cout<<")";
			}
			return;
		}
		int recursive_matrix_chain(int P[],int i,int j){
			if(i==j)
				return 0;
			m[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int q=recursive_matrix_chain(P,i,k)+recursive_matrix_chain(P,k+1,j)+P[i-1]*P[k]*P[j];
				if(q<m[i][j])
					m[i][j]=q;	
			}
			return m[i][j];	
		}
};
int main(){
	MCM m;
	int P[5]={3,6,2,4,5};
	int l=5;
	m.Bottom_Up_MCM(P,5);
	cout<<endl;
	m.OPT_PAR(1,4);
	cout<<endl;
	int x=m.recursive_matrix_chain(P,1,4);
	cout<<x;
}