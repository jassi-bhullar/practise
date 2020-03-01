#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
private:
	int V;
	list<iPair> *adj;

	int minKey(int key[], bool mstSet[])
	{
		int mi = INT_MAX;
		int mi_index;
		for (int i = 0; i < V; ++i)
		{
			if(mstSet[v]==false && mi > key[v])
			{
				mi = key[v];
				mi_index = v;
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

		for (int i = 0; i < V; ++i)
		{
			int u = minKey(key, mstSet);

			mstSet[u] = true;

			for(auto x: adj[u])
			{
				int v = x.second;
				int weight = x.first;

				if(key[v] > weight)
				{
					key[v] = weight;
				}
			}
		}
	}
};