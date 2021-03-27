#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

void BFS(vector<vector<int> > &adj, vector<bool> Visited, vector<bool> &shortest){
  queue<int> Q;
  for(size_t i=0;i<adj.size();i++){
    if(Visited[i]==true)
      Q.push(i);
  }
  while(!Q.empty()){
    int vertex= Q.front();
    Q.pop();
    shortest[vertex]=false;
    vector<int> neighbours= adj[vertex];
    for(int i=0;i<neighbours.size();i++){
      if(Visited[neighbours[i]]==false){        
        Q.push(neighbours[i]);
        Visited[neighbours[i]]=true;
      }
    }
  }
}

void EdgeRelax(vector<long long> &Dist, int v, int u, long cost, bool &Relaxed){
  if (Dist[u]<std::numeric_limits<long long>::max() && Dist[v]>Dist[u]+cost){
    Dist[v] = Dist[u]+cost;
    Relaxed=true;
  }
}

vector<bool> BellmanFord(int vertex, vector<vector<int> > &adj, vector<vector<int> > cost, vector<long long> &Dist){
  Dist[vertex] = 0;
  int count = 0;
  vector<bool> Visited(adj.size(),false);
  while(count<adj.size()){
    for(size_t k=0;k<adj.size();k++){
      vector<int> neighbours = adj[k];
      for(size_t i=0;i<neighbours.size();i++){
        bool Relaxed = false;
        EdgeRelax(Dist,neighbours[i],k,cost[k][i],Relaxed);
        if(count==adj.size()-1)
          Visited[neighbours[i]]=Relaxed;
      }
    }
    count++;
  }
  return Visited;   
}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<bool> &reachable, vector<bool> &shortest) {
  vector<bool> Visited = BellmanFord(s,adj,cost,distance);
  reachable[s]=true;
  for(size_t i=0;i<distance.size();i++){
    if(distance[i]<std::numeric_limits<long long>::max())
      reachable[i]=true;
  }
  BFS(adj,Visited,shortest);
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<bool> reachable(n, false);
  vector<bool> shortest(n, true);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
