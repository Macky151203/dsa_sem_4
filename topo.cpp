#include<iostream>
using namespace std;
enum vcolor{
    White,Gray,Black
};
struct node{
    int ver;//index
    node *next;
};
struct vnode{
    int d,f,pi;
    string name;
    node *adjptr;
    vcolor color;
};
class graph{
    int n,time;
    node *list;
    vnode vertex[10];
    public:
        void creategraph(){
            cout<<"enter no of vertices- ";
            cin>>n;
            int m;
            for(int i =1;i<=n;i++){
                cout<<"enter name of vertx- ";
                cin>>vertex[i].name;
                cout<<"enter no of adj vertx for "<<vertex[i].name <<endl;
                cin>>m;
                vertex[i].adjptr=NULL;
                node *cur= NULL;
                for(int j=1;j<=m;j++){
                    node *t= new node;
                    cout<<"enter index of adj vetex- "<<endl;
                    cin>>t->ver;
                    if(cur==NULL){
                        vertex[i].adjptr=t;
                    }
                    else{
                        cur->next=t;
                    }
                    t->next=NULL;
                    cur=t;
                }
            }
        }
        void display(){
            for(int i=1;i<=n;i++){
                cout<<vertex[i].name;
                node *t= vertex[i].adjptr;
                while(t!=NULL){
                    cout<<"->"<<t->ver;
                    t=t->next;
                }
                cout<<endl;
            }
        }
        void dfs_visit(int u){
            int v;
            time++;
            vertex[u].color=Gray;
            vertex[u].d=time;
            node *temp= vertex[u].adjptr;
            while(temp!=NULL){
                v=temp->ver;
                if(vertex[v].color==White){
                    vertex[v].pi=u;
                    dfs_visit(v);
                }
                temp=temp->next;
            }
            time++;
            vertex[u].f=time;
            vertex[u].color=Black;
            node *t= new node;
            t->ver=u;
            t->next=list;
            list=t;
        }
        void dfs(){
            for(int i=1;i<=n;i++){
                vertex[i].color=White;
                vertex[i].pi=0;
            }
            time=0;
            list=NULL;
            for(int i=1;i<=n;i++){
                if(vertex[i].color==White){
                    dfs_visit(i);
                }
            }

        }
        void topsort(){
            dfs();
            node *t= new node;
            t=list;
            while(t!=NULL){
                cout<<vertex[t->ver].name<<" ";
                t=t->next;
            }
        }
};
int main(){
    graph g;
    g.creategraph();
    g.display();
    g.topsort();
}