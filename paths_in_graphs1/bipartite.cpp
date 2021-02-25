#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;

int BFS(vector<int> &Dist,vector<vector<int> > &adj, int source, vector<bool> &Visited) {
  Dist[source]= 0;
  queue<int> Q;
  Q.push(source);
  while (!Q.empty()){
    int vertex= Q.front();
    Q.pop();
    vector<int> neighbours= adj[vertex];
    for(int i=0;i<neighbours.size();i++){
      if (Visited[neighbours[i]]==false){
        Q.push(neighbours[i]);
        Visited[neighbours[i]]= true;
        Dist[neighbours[i]]= Dist[vertex]+1;
      }
      if((Dist[vertex]+Dist[neighbours[i]])%2==0)
        return 0;
    }
  }
  return 1; 
}

int bipartite(vector<vector<int> > &adj) {
  vector<bool> Visited(adj.size(),false);
  vector<int> Dist;
  for(int i=0;i<adj.size();i++){
    Dist.push_back(-1);
  } 
  for(int i=0;i<adj.size();i++){
    if (Visited[i]==false){
      Visited[i]= true;
      if(BFS(Dist,adj,i,Visited)==0)
        return 0;
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
