#include <iostream>
#include <fstream>

using namespace std;
class PQ;
struct node{
   int ver;
   int weight;
   node *next;
};
struct vnode{
     string name;
     int key;
     int pi;
     int qid;
     bool inQueue;
     node *adjptr;
};
class graph{
        int n;
        vnode vertex[10];
        friend class PQ;
  public:
        void createGraph(){
        	int m;
        	ifstream fin("priminput.txt");
    //    	cout << "Enter number of vertices: ";
			fin >> n;                                       //Number of vertices
			for (int i=1; i<=n; i++){
	//			cout << "Enter name of the vertex: ";
				fin >> vertex[i].name;
 	            vertex[i].adjptr=NULL;
 	//            cout << "Enter number of adjacent vertices: ";
 	            fin >> m;                 //Number of adjacent vertices
	   			node *cur=NULL;
	   			for (int j=1; j<=m; j++){
			      	node *t=new node;
			      	fin>> t->ver;           //Get index of adjacent vertex
	      			fin>> t->weight;          //Get the weight of the edge
	      			t->next=NULL;
	      			if (cur==NULL)
	                    vertex[i].adjptr=t;
			        else
					    cur->next=t;
 			        cur=t;
 			    }
 			}
		}
        void PRIMS(int s);
        void display(){
        	cout << "Given Graph: " << endl;
        	for (int i=1; i<=n; i++){
        		cout << vertex[i].name << "\t";
        		node *t= vertex[i].adjptr;
        		while (t!=NULL){
        			cout << "--> (" << vertex[t->ver].name << ", " << t->weight << ") ";
        			t = t->next;
				}
				cout << endl;
			}
		}
};
class PQ{
     int Q[10];
     graph *G;
     int heapsize;
     
public:
	 bool isEmpty(){
	 	if (heapsize==0)
	 		return true;
	 	else
	 		return false;
	 }
     void createPQ(graph *g){
     	G = g;
     	heapsize=G->n;//no of vertex
		for (int i=1; i<=G->n; i++){
	       G->vertex[i].qid=i;
	       G->vertex[i].inQueue=true;
	       Q[i]=i;
	    }
	    for (int i=G->n/2; i>=1; i--)
	        MIN_HEAPIFY(i);
	 }
	 
     void MIN_HEAPIFY(int i){
     	int smallest=i;
		int l=2*i;
		int r=2*i+1;
		if (l<=heapsize && G->vertex[Q[l]].key<G->vertex[Q[i]].key)
 	       	smallest=l;
		if (r<=heapsize && G->vertex[Q[r]].key<G->vertex[Q[smallest]].key)
	       	smallest=r;
		if (smallest!=i){
			int t = Q[i];
	        Q[i] = Q[smallest];
	        Q[smallest]=t;
	        G->vertex[Q[i]].qid=i;
	        G->vertex[Q[smallest]].qid=smallest;
	        MIN_HEAPIFY(smallest);
	    }
	 }
	 
     int EXTRACT_MIN(){
     	int x=Q[1];
		G->vertex[x].inQueue=false;
		Q[1]= Q[heapsize];
		G->vertex[Q[1]].qid=1;
		heapsize=heapsize-1;
		MIN_HEAPIFY(1);
		return x;
	 };
	 
     void DECREASE_KEY(int i, int w){
     	G->vertex[Q[i]].key=w;
		while (i>1 && G->vertex[Q[i/2]].key>G->vertex[Q[i]].key){
	      int t= Q[i];
		  Q[i]=Q[i/2];
		  Q[i/2]=t;
	      G->vertex[Q[i]].qid=i;
	      G->vertex[Q[i/2]].qid=i/2;
	      i=i/2;
		}
	 }
};
void graph::PRIMS(int s){
    for (int i=1; i<=n;i++){
        vertex[i].key=9999;
	    vertex[i].pi=-1;
	}
	vertex[s].key=0;
	PQ Q;
	Q.createPQ(this);
	int total = 0;
	cout <<"Edges included in spanning tree are: " << endl;
	while (!Q.isEmpty()){
	    int u=Q.EXTRACT_MIN();
	    if (vertex[u].pi!=-1){
	        total += vertex[u].key;
	        cout << vertex[vertex[u].pi].name << "-->" << vertex[u].name << endl;
	    }
	    node *t=vertex[u].adjptr;
		while (t!=NULL){
		    if (vertex[t->ver].inQueue && t->weight<vertex[t->ver].key){
	            Q.DECREASE_KEY(vertex[t->ver].qid,t->weight);
	            vertex[t->ver].pi=u;
	        }
	        t=t->next;
	    }
	}
	cout << "Total cost = " << total << endl;
}
int main(){
	graph g;
	g.createGraph();
	g.display();
	g.PRIMS(1);
	return 0;
}




