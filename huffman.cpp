#include<iostream>
#include<string>
#include <math.h>
using namespace std;

struct charnode
{
	char c;
	int freq;
	int codelen;
	string code;
	charnode *parent;
	charnode *left;
	charnode *right;
};

class PQ
{
	charnode **Q;
	int heapsize;
	// n;
	public:
		
		void create_PQ(charnode *C[], int len)
		{
		  heapsize = len - 1;
  		  Q = new charnode*[len];
		  for (int i=0; i<=heapsize; i++)
   		    Q[i]=C[i];
		  for(int i=(heapsize+1)/2;i>=0;i--)
		    Min_Heapify(i);
	    }
		void Min_Heapify(int i)
	    {
	     	int l=2*i+1;
	     	int r=2*i+2;
	     	int smallest;
	     	if (l<=heapsize && Q[l]->freq<Q[i]->freq)
	     		smallest=l;
	     	else
	     		smallest=i;
	     	if ( r<=heapsize && Q[r]->freq<Q[smallest]->freq)
	     		smallest=r;
	     	if(smallest!=i)
	     	{ 
	     		charnode *t = Q[i];
	     		Q[i]=Q[smallest];
	     		Q[smallest]= t;
	     		Min_Heapify(smallest);
	     	}
		}
		 
		void insert(charnode *z)
		{
		 	heapsize=heapsize+1;
		 	int i=heapsize;
		 	while(i>0 && Q[i/2]->freq>z->freq)
		 	{
		 		Q[i]=Q[i/2];
		 		i=i/2;
			}
			Q[i]=z;	 	
		}
		 	 
		charnode* Extract_Min()
		{ 
			charnode *temp;
			temp = Q[0];
	    	Q[0]=Q[heapsize];
	    	heapsize=heapsize-1;
	    	Min_Heapify(0);
	    	return temp;
		}	 	
};
class Huffman{
   charnode **C;
   int n;
public:
	Huffman(char ch[], int freq[], int len)
	{
		n = len;
		C = new charnode*[len];
		for (int i=0; i<n; i++){
			C[i]=new charnode;
			C[i]->c=ch[i];
			C[i]->freq=freq[i];
			C[i]->codelen=0;
			C[i]->code="";
			C[i]->left=C[i]->right=C[i]->parent=NULL;
	    }
    }
	void display()
    { 
 	    for(int i=0;i<n;i++)
    	{
    		findcode(C[i]);
 			cout<<C[i]->c<<"\t";
 	   		cout<<C[i]->freq<<"\t";
   			cout<<C[i]->codelen <<"\t";
   			cout<<C[i]->code<<"\t";
   			cout<<endl;
		}
	}

	int filesize()
	{
		int fs=0;
		for (int i=0; i<n; i++)
			fs += C[i]->freq * C[i]->codelen;
		return fs;
	}
	
	charnode* BuildTree()
	{
	   	PQ Q; 
		Q.create_PQ(C,n);
		for(int i=1;i<=n-1;i++)
		{
			charnode *x,*y,*z;
			z=new charnode;
			z->codelen=0;
			z->code="";
			z->parent=NULL;
			x=Q.Extract_Min();
			y=Q.Extract_Min();
			z->left=x;
			z->right=y;
			z->parent=NULL;
			x->parent=y->parent=z;
			z->freq=x->freq+y->freq;
			Q.insert(z);
		}
    	return Q.Extract_Min();
   }
   void findcode(charnode *t)
   {
	  if (t->codelen>0)
	      return;
	  if (t->parent==NULL){
		t->codelen=0;
        t->code="";	
	  }
	  else {
		findcode(t->parent);
		t->codelen = t->parent->codelen+1;
		if (t->parent->left==t)
		    t->code=t->parent->code+"0";
		else 
		    t->code=t->parent->code+"1";
	  }
   }
};


int main()
{
	int n;
	char a[20];
	int f[20];
	cout << "Enter No. of characters: ";
	cin >> n;
	cout << "Enter the char & freq: "<< endl;
	for(int i=0;i<n;i++)
	   cin >> a[i] >> f[i];
	Huffman H(a,f,n);
	cout << endl;	
    charnode *root=H.BuildTree();
    H.display();
    // charnode *t;
    int FL_FS;
    int VL_FS;
    int tot_freq=0;
    for (int i=0; i<n; i++)
    	tot_freq += f[i];
	FL_FS = tot_freq * (ceil)(log2(n)); 
	VL_FS = H.filesize();

	cout << "File size in Variable Length: " << VL_FS << endl;
	cout << "File size in Fixed Length: " <<  FL_FS << endl;
	cout << "Compression Ratio: " << 100-(double)VL_FS/FL_FS*100 << endl;
	return 0;
}

