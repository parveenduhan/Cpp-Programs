#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class UGraph
{
	public:
		int v;
		int *vertices;
		vector<int> *adj_list;

		UGraph(int v)
		{
			this->v = v;
			this->vertices = new int[v];
			this->adj_list = new vector<int>[v];

			for(int i = 0; i<v; i++)
				this->adj_list[i] = vector<int>(); 
		}

		~UGraph() 
		{
        		delete[] vertices;
        		delete[] adj_list;
    		}

		void add_edge(int u, int v)
		{
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		void print_graph()
		{
			for(int i = 0; i<this->v; i++)
			{
				for(auto x: adj_list[i])
				{
					cout<<i<<"-->"<<x<<", ";
				}
				cout<<endl;
			}
		}

		void BFS_core(int s, bool visited[], vector<int> bfs_arr)
		{
			queue<int> q;
			visited[s] = true;
			q.push(s);
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				bfs_arr.push_back(u);
				
				for(int i:this->adj_list[u])
				{
					if(!visited[i])
					{
						visited[i] = true;
						q.push(i);
					}
				}

			}
		}
		
		void BFS(int s)
		{
			bool visited[this->v];
			vector<int> bfs_arr;
			for(int i = 0; i<this->v; i++)
				visited[i] = false;
			BFS_core(s, visited, bfs_arr); // starting from source
			for(int i = 0; i<this->v; i++)
				if(!visited[i])
					BFS_core(i, visited, bfs_arr); // to include the case for disconnected graph
			for(int i: bfs_arr)
				cout<<i<<" ";
			cout<<endl;
		}
		void DFS_core(int s, bool visited[], vector<int> dfs_arr)
		{
			visited[s] = true;
			dfs_arr.push_back(s);
			for(int u: this->adj_list[s])
			{
				if(!visited[u])
					DFS_core(u,visited, dfs_arr);
			}
		}
		void DFS(int s)
		{
			bool visited[this->v];
			vector<int> dfs_arr;
			for(int i = 0; i<this->v; i++)
				visited[i] = false;
			DFS_core(s, visited, dfs_arr); // starting from source
			for(int i = 0; i<this->v; i++)
				if(!visited[i])
					DFS_core(i, visited, dfs_arr); // to include the case for disconnected graphs
			for(int i: dfs_arr)
				cout<<i<<" ";
			cout<<endl;
		}
		void shortest_path(int s)
		{
			if(!this->is_connected())
			{
				cout<<"Graph is not connected"<<endl;
				return;
			}
			
			bool visited[this->v] = {true};
			int path[this->v] = {0};

			queue<int> q;
			q.push(s);
			visited[s] = true;
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				for(int i : this->adj_list[u])
				{
					if(!visited[i])
					{
						path[i] = path[u]+1;
						visited[i] = true;
						q.push(i);
					}
				}
			}

			for(int i = 0; i<this->v; i++)
			{
				cout<<"distance of v"<<i<<" from v"<<s<<" is: "<<path[i]<<endl;
			}
		}
		
		bool is_connected()
		{
			bool visited[this->v] = {false};
			vector<int> bfs_arr;
			this->BFS_core(0, visited, bfs_arr);
			for(bool f: visited)
				if(!f)
					return false;
			return true;
		}

		bool contains_cycle_rec(int s, bool visited[], int parent)
		{
			visited[s] = true;
			for(int u: this->adj_list[s])
			{
				if(!visited[u])
				{
					if(contains_cycle_rec(u,visited,s))
						return true;
				}
				else 
					if(u != parent)
						return true;
			}
			return false;
		}
		bool contains_cycle()
		{
			bool visited[this->v] = {false};
			for(int i =0; i<this->v; i++)
				if(!visited[i])
					if(contains_cycle_rec(i, visited, -1))
						return true;
			return false;
		}
};
int main()
{
	int v;
	cout<<"Enter number of vertices:"<<endl;
	cin>>v;
	UGraph *graph = new UGraph(v);

	for(int i=0; i<v; i++)
	{
		for(int j = i+1; j<v; j++)
		{
			
			
				cout<<"Is there any edge between "<<i<<" & "<<j<<"(1/0)?"<<endl;
				int flag;
				cin>>flag;
				if(flag)
					graph->add_edge(i,j);
			
		}
	}

	graph->print_graph();
	graph->BFS(0);
	graph->DFS(0);
	graph->shortest_path(0);
/*	if(graph->is_connected())
		cout<<"graph is connected"<<endl;
	else
		cout<<"graph is not connected"<<endl;
*/
	if(graph->contains_cycle())
		cout<<"Graph has a cycle"<<endl;
	else
		cout<<"Graph does not has a cycle"<<endl;
	return 0;
}

					

