#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class radix{
     int a[100],b[100];
     
    public:
        void in(){
            for(int i=0;i<4;i++){
                cout<<"enter- ";
                cin>>a[i];
            }
        }
        void out(){
            
            for(int i=0;i<4;i++){
                cout<<a[i]<<" ";
            }
        }
        
        void countsort(int n,int k,float in,int &count){
           
            int c[k+1];
            for(int i=0;i<=k;i++){
                c[i]=0;
            }
            for(int i=0;i<n;i++){
                c[(int)(a[i]/in)%10]++;
            }
            for(int i=1;i<=k;i++){
                c[i]+=c[i-1];
            }
            for(int i=n-1;i>=0;i--){
                count++;
                b[c[(int)(a[i]/in)%10]-1]=a[i];
                c[(int)(a[i]/in)%10]--;
            }
            for(int i=0;i<n;i++){
                a[i]=b[i];
            }
        }
        int maxvalue(int n){
            int max=a[0];
            for(int i=1;i<n;i++){
                if(a[i]>max){
                    max=a[i];
                }
            }
            return max;
        }
        void radixsort(int n,int &count){
            
            int max= maxvalue(n);
            
            for(int i=1;max/i>0;i=i*10){
                countsort(n,9,i,count);
            }
        }
    
};
int main(){
   
    int count=0;
    
    radix r;
    r.in();
    r.radixsort(4,count);
    r.out();
   
    return 0;

}