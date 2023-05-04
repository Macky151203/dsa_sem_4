#include<iostream>
#include<string.h>
using namespace std;
class SM{
	char T[100],P[100];
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
		int PREPROCESS_RK(int d,int q){
			int count,p;
			count=0;
			p=0;
			for(int i=0;i<m;i++){
				count++;
				p=(d*p+P[i])%q;
			}
			cout<<"Preprocessing count="<<count<<endl;
			return p;
		}
		int RK_MATCHER(int p,int d,int q){
			int h=1,count,flag;
			for(int i=0;i<m-1;i++)
				h=(h*d)%q;//10^m-1
			count=0;
			int t;
			t=0;
			for(int i=0;i<m;i++){
				count++;
				t=(d*t+T[i])%q;
			}
			
			for(int s=0;s<=n-m;s++){
				count++;
				flag=0;
				if(p==t){
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
				if(s<n-m)
					t=(d*(t-T[s]*h)+T[s+m])%q;
				if(t<0)
					t+=q;
			}
			return count;
		}
};
int main(){
	int ch=1;
	int d=10,q=4999;
	while(ch==1){
		SM sm;
		sm.input();
		cout<<"\nNaive:"<<endl;
		int x=sm.NAIVE();
		cout<<"Number of basic operations:"<<x<<endl;
		cout<<"\nRabin-Karp:"<<endl;
		int p=sm.PREPROCESS_RK(d,q);
		int c=sm.RK_MATCHER(p,d,q);
		cout<<"Number of basic operations:"<<c;
		cout<<"\n\nEnter 1 to continue:";
		cin>>ch;
	}
}