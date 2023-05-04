#include<iostream>
#include<limits.h>
using namespace std;
struct Sum{
    int li;
    int ri;
    int sum;
};
class maxsub{
    int a[10];
    public:
        // void input(){
        //     for(int i=0;i<10;i++){
        //         cout<<"enter- ";
        //         cin>>a[i];
        //     }
        // }
        
        Sum crosssubarr(int l,int m ,int h, int &count, int a[]){
            int leftmax=INT_MIN;
            Sum s;
            int sum=0;
            for(int i=m;i>=l;i--){
                sum=sum+a[i];
                count++;
                if(sum>leftmax){
                    leftmax=sum;
                    s.li=i;
                    
                }
            }
            int rightmax=INT_MIN;
            sum=0;
            for(int i=m+1;i<=h;i++){
                sum=sum+a[i];
                count++;
                if(sum>rightmax){
                    rightmax=sum;
                    s.ri=i;
                }
            }
            s.sum=leftmax+rightmax;
            return s;
        }
        Sum maxsubarr(int l,int h,int &count, int a[]){
            Sum s;
            int m;
            if(l==h){
                s.li=l;
                s.ri=h;
                s.sum=a[l];
                return s;
            }
            else{
                m=(l+h)/2;
                Sum L,R,C;
                L= maxsubarr(l,m,count,a);
                R=maxsubarr(m+1,h,count,a);
                C=crosssubarr(l,m,h,count,a);
                if(L.sum>R.sum&&L.sum>C.sum){
                    s.li=L.li;
                    s.ri=L.ri;
                    s.sum=L.sum;
                    return s;
                }
                else if(R.sum>L.sum&&R.sum>C.sum){
                    s.li=R.li;
                    s.ri=R.ri;
                    s.sum=R.sum;
                    return s;
                }
                else{
                    s.li=C.li;
                    s.ri=C.ri;
                    s.sum=C.sum;
                    return s;
                }
            }
        }
        
};
int main(){
    maxsub m;
    Sum s;
    int count=0;
    int a[10]={1,2,-13,10,12,1,3,4,5,-20};
    s=m.maxsubarr(0,9,count,a);
    cout<<s.li<<" "<<s.ri<<" "<<s.sum;
    return 0;
}
