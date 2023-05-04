#include<iostream>
#include<string.h>
using namespace std;
class rk{
    char T[100],P[100];
    int m,n;
    public:
        void input(){
            cout<<"enter p - ";
            cin>>P;
            cout<<"enter t -";
            cin>>T;
            m=strlen(P);
            n=strlen(T);
        }
        int naive(){
            int count,flag;
            count=0;
            
            for(int s=0;s<=n-m;s++){
                flag=0;
                for(int i=0;i<m;i++){
                    count++;
                    if(P[i]!=T[i+s]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    cout<<"pattern found with valid shift- "<<s<<endl;
                }
            }
            return count;
        }
        int preprocess(int d,int q){
            int count,p;
            count=0;
            p=0;
            for(int i=0;i<m;i++){
                count++;
                p=(d*p+P[i])%q;
            }
            cout<<"preprocess count- "<<count<<endl;
            return p;
        }
        int rkmatch(int q,int d,int p){
            int count,flag,t,h;
            h=1;
            for(int i=0;i<m-1;i++){
                h=(h*d)%q;
            }
            count =0;
            t=0;
            for(int i=0;i<m;i++){
                count++;
                t=(d*t+T[i])%q;
            }
            for(int s=0;s<=n-m;s++){
                flag=0;
                count++;
                if(p==t){
                    for(int i=0;i<m;i++){
                        count++;
                        if(P[i]!=T[i+s]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        cout<<"aptter found with shift- "<<s<<endl;
                    }
                }
                if(s<n-m){
                    t=(d*(t-(T[s])*h)+T[s+m])%q;
                }
                if(t<0){
                    t+=q;
                }
            }
            return count;
        }
};
int main(){
    rk r;
    r.input();
   cout<<"naive count "<< r.naive();
    int p=r.preprocess(10,4999);
    cout<<"RK count- "<<r.rkmatch(4999,10,p);
}