#include<iostream>
#include<string.h>
using namespace std;
class kmp{
    char p[100],t[100];
    int pi[100];
    int m,n;
    public:
        void input(){
            cin>>p;
            cin>>t;
            m=strlen(p);
            n=strlen(t);

        }
        int naive(){
            int count,flag;
            for(int s=0;s<=n-m;s++){
                flag=0;
                for(int i=0;i<m;i++){
                    count++;
                    if(p[i]!=t[i+s]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    cout<<"pattern found with shift- "<<s<<endl;
                }
            }
            return count;
        }
        void computpre(){
            int count,k;
            count=0;
            k=0;
            pi[0]=0;
            for(int q=1;q<m;q++){
                count++;
                while(k>0 && p[k]!=p[q]){
                    k=pi[k-1];
                    count++;
                }
                if(p[k]==p[q]){
                    k++;
                }
                pi[q]=k;
            }
            cout<<"prep process count- "<<count<<endl;
        }
        int kmpmatch(){
            int count,q;
            count =0;
            q=0;
            for(int i=0;i<n;i++){
                count++;
                while(q>0 && p[q]!=t[i]){
                    q=pi[q-1];
                    count++;
                }
                if(p[q]==t[i]){
                    q++;
                    if(q==m){
                        cout<<"pattern macte with shift- "<<i-m+1<<endl;
                        q=pi[q-1];
                    }
                }
            }
            return count;
        }
};
int main(){
    kmp k;
    k.input();
    k.computpre();
    int a=k.kmpmatch();
    cout<<a;
}