#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
private:
	int V;
	list<iPair> *adj;

	int minKey(vector<int> key, vector<bool> mstSet)
	{
		int mi = INT_MAX;
		int mi_index;
		for (int i = 0; i < V; ++i)
		{
			if(mstSet[i]==false && mi > key[i])
			{
				mi = key[i];
				mi_index = i;
			}
		}

		return mi_index;
	}

public:
	Graph(int v)
	{
		V = v;
		adj = new list<iPair>[v];
	}

	void addEdge(int u, int v, int w)
	{
		adj[u].push_back(make_pair(w, v));
		adj[v].push_back(make_pair(w, u));
	}

	void mst()
	{
		vector<bool> mstSet(V, false);	
		vector<int> parent(V, -1);
		vector<int> key(V, INT_MAX);

		key[0] = 0;
		int totalWeight = 0;

		for (int i = 0; i < V; ++i)
		{
			int u = minKey(key, mstSet);

			mstSet[u] = true;
			totalWeight += key[u];

			for(auto x: adj[u])
			{
				int v = x.second;
				int weight = x.first;

				if(key[v] > weight && mstSet[v]==false)
				{
					key[v] = weight;
					parent[v] = u;
				}
			}
		}

		for (int i = 1; i < V; ++i)
		{
			cout << parent[i] << " - " << i  << ": " << key[i] << endl;
		}
		cout << "\nTotal Weight: " << totalWeight << "\n\n";	
	}
};

int main() 
{ 
    int V = 9; 
    Graph g(V); 
  
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.mst(); 
  
    return 0; 
} 