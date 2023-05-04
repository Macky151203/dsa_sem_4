#include<iostream>
#include<fstream>
using namespace std;
struct datanode
{
        float data;
        datanode *link;
};
struct headnode
{
        int count;
        datanode *first;
};


class BucketSort
{

	
		float a[10000];
		headnode h[10];
datanode *T,*pPre,*pLoc,*pWalker;
	
	public:
	
	void readInput(int n)
	{
			// ifstream fin("uni_rand.txt");
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				//cout<<a[i]<<"\n";
			}
	}
	void bucket_sort(int n)
	{
		int x;
		int count=0;
		for(int i=0;i<n;i++)
		{
			h[i].first=NULL;
			h[i].count=0;
		}
		
		for(int i=1;i<=n;i++)
		{
			x=a[i]*n;//index
			
			
			cout<<x<<endl;
			
			pPre=NULL;
			pLoc=h[x].first;
							
			while(pLoc!= NULL && a[i]>=pLoc->data)
			{
				pPre=pLoc;
				pLoc= pLoc->link;
			}
			
			datanode *pNew=new datanode;
			pNew->data=a[i];
			if(pPre==NULL)
			{
				pNew->link=h[x].first;
				h[x].first=pNew;
			}
			else
			{
				pNew->link=pPre->link;
				pPre->link=pNew;
			}
			h[x].count++;

		}	
		
		// ofstream fout("bucket_output.txt");
		for(int i=0;i<n;i++)
		{
			pWalker=h[i].first;
			count=count+h[i].count;
			while(pWalker!=NULL)
			{
				cout<<pWalker->data<<"\n";
				//cout<<pWalker->data<<"\n";
				pWalker=pWalker->link;
			}

		}
		cout<<"Count value:"<<count<<endl;
	}
		
		
};
int main()
{
	BucketSort bs;
	int n;
	cout<<"Enter the input size"<<endl;
	cin>>n;
	bs.readInput(n);
	bs.bucket_sort(n);
}