#include<iostream>
#include<string.h>
using namespace std;
class SM{
	char T[100],P[100];
	int pi[100];
	int m,n;
	public:
		void input(){
			cout<<"\nEnter the pattern:";
			cin>>P;
			cout<<"Enter the text:";
			cin>>T;
			m=strlen(P);
			n=strlen(T);
		}
		int NAIVE(){
			int count=0,flag;
			for(int s=0;s<=n-m;s++){
				flag=0;
				for(int j=0;j<m;j++){
					count++;
					if(P[j]!=T[s+j]){
						flag=1;
						break;
					}
				}
				if (flag==0)
					cout<<"Pattern occurs with valid shift "<<s<<endl;
			}
			return count;
		}
		void COMPUTE_PREFIX(){	
			int k=0,count=0;
			pi[0]=0;
			for (int q=1;q<m;q++){
				count++;
				while(k>0 && P[k]!=P[q]){
					k=pi[k-1];
					count++;
				}
				if(P[k]==P[q])
					k++;
				pi[q]=k;
			}
			cout<<"Preprocessing Pattern count="<<count<<endl;
		}
		int KMP_MATCHER(){
			int count=0,q=0;
			for (int i=0;i<n;i++){
				count++;
				while(q>0 && P[q]!=T[i]){
					q=pi[q-1];
					count++;
				}
				if(P[q]==T[i]){
					q++;
					if(q==m){
						cout<<"Pattern occurs with valid shift "<<i-m+1<<endl;
						q=pi[q-1];
					}	
				}
			}
			return count;
		}
};
int main(){
	int ch=1;
	while(ch==1){
		SM sm;
		sm.input();
		cout<<"\nNaive:"<<endl;
		int x=sm.NAIVE();
		cout<<"Number of basic operations:"<<x<<endl;
		cout<<"\nKMP:"<<endl;
		sm.COMPUTE_PREFIX();
		int c=sm.KMP_MATCHER();
		cout<<"Number of basic operations:"<<c;
		cout<<"\n\nEnter 1 to continue:";
		cin>>ch;
	}
}