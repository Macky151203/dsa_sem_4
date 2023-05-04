#include<iostream>
using namespace std;
struct node{
    int weight,from,to;
    node *next;
};
struct vnode{
    int d,pi;
    string name;
};
class graph{
    int m,n;
    vnode vertex[10];
    node *elist;
    public:
        void creategraph(){
            cout<<"enter no of vertices- ";
            cin>>n;
            for(int i=1;i<=n;i++){
                cout<<"enter the name of the vertices "<<i <<" ";
                cin>>vertex[i].name;
            }
            cout<<"enter no of edges ";
            cin>>m;
            elist=NULL;
            node *cur=NULL;
            for(int i=1;i<=m;i++){
                cout<<"enter index of from and to- ";
                node *t= new node;
                cin>>t->from;
                cin>>t->to;
                cout<<"enter weight ";
                cin>>t->weight;
                if(elist==NULL){
                    elist=t;
                }else{
                    cur->next=t;
                }
                t->next=NULL;
                cur=t;
            }
        }
        void ini(int s){
            for(int i=1;i<=n;i++){
                vertex[i].d=999;
                vertex[i].pi=-1;
            }
            vertex[s].d=0;
        }
        void relax(int u,int v,int w){
            if(vertex[v].d>vertex[u].d+w){
                vertex[v].d=vertex[u].d+w;
                vertex[v].pi=u;
            }
        }
        bool bf(int s){
            node *t;
            ini(s);
            for(int i=1;i<=n-1;i++){
                t=elist;
                while(t!=NULL){
                    relax(t->from,t->to,t->weight);
                    t=t->next;
                }
            }
            t=elist;
            while(t!=NULL){
                if(vertex[t->to].d>vertex[t->from].d+t->weight){
                    return false;
                    
                }
                t=t->next;
            }
            return true;

        }
        void display(){
            for(int i=1;i<=n;i++){
                cout<<vertex[i].name<<" "<<vertex[i].d<<" "<<vertex[i].pi<<" "<<endl;
            }
        }
};
int main(){
    graph g;
    g.creategraph();
    bool res=g.bf(1);
    if(res){
        g.display();
    }
    else{
        cout<<"podavenna";
    }
    return 0;
}