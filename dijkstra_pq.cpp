#include <bits/stdc++.h> 
using namespace std; 

typedef pair<int, int> iPair;
// #define iPair pair<int,int> 

class Graph
{
private:
	int V;
	list<iPair> *adj;

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

	void shortestPath(int src)
	{
		priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

		vector<int> dist(V, INT_MAX);

		dist[src] = 0;
		pq.push(make_pair(0, src));

		while(!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();

			for(auto x: adj[u])
			{
				int v = x.second;
				int weight = x.first;

				if(dist[v] > dist[u] + weight)
				{
					dist[v] = dist[u] + weight;
					pq.push(make_pair(dist[v], v));
				}
			}
		}

		for (int i = 0; i < V; ++i)
		{
			cout << i << ": " << dist[i] << endl;
		}
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
  
    g.shortestPath(0); 
  
    return 0; 
}