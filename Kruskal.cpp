#include <iostream>
#include <fstream>

using namespace std;
struct node
{
	int from;
	int to;
	int weight;
	bool status;
	node *next;
};

class graph
{
	int n, m;
	string vertex[20];
	int parent[20], rank[20];
	node *elist;

public:
	void createGraph()
	{
		// ifstream fin("krus_input.txt");
		cout << "Enter number of vertices: ";
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cout << "Enter name of the vertex - " << i << ": ";
			cin >> vertex[i];
		}
		cout << "Enter number of edges: ";
		cin >> m;
		elist = NULL;
		for (int j = 0; j < m; j++)
		{
			node *t = new node;
			cout << "Enter index of from vertex: ";
			cin >> t->from;
			cout << "Enter index of to vertex: ";
			cin >> t->to;
			cout << "Enter edge weight: ";
			cin >> t->weight;
			t->status = false;
			t->next = NULL;
			if (elist == NULL || elist->weight > t->weight)
			{ // insert at begining
				t->next = elist;
				elist = t;
			}
			else
			{ // insert according to increasing order
				node *temp = elist;
				while (temp->next != NULL && temp->next->weight <= t->weight)
					temp = temp->next;
				t->next = temp->next;
				temp->next = t;
			}
		}
	}

	void MakeSet(int v)
	{
		parent[v] = v;
		rank[v] = 0;
	}

	int FindSet(int v)
	{
		while (parent[v] != v)
			v = parent[v];
		return v;
	}

	void Union(int u, int v)
	{
		if (rank[u] > rank[v])
			parent[v] = u;
		else
		{
			parent[u] = v;
			if (rank[u] == rank[v])
				rank[v]++;
		}
	}

	void FindSpanningTree()
	{
		for (int i = 1; i <= n; i++)
			MakeSet(i);
		int count = 1, totalwt = 0;
		node *temp = elist;
		cout << "Edges included in minimum weight spanning tree are :" << endl;
		while (temp != NULL && count <= n - 1)
		{
			int i = FindSet(temp->from);
			int j = FindSet(temp->to);
			if (i != j)
			{
				temp->status = true;
				count++;
				totalwt = totalwt + temp->weight;
				cout << temp->from << " --> " << temp->to << ":  " << temp->weight << endl;
				Union(i, j);
			}
			temp = temp->next;
		}
		cout << endl
			 << "Total Weight of the MWST is : " << totalwt << endl;
	}
};

int main()
{
	graph g;
	g.createGraph();
	g.FindSpanningTree();
	return 0;
}
