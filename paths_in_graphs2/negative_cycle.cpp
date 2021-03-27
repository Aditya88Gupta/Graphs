#include <iostream>
#include <vector>
#include <climits>

using std::vector;

void EdgeRelax(vector<long long> &Dist, int v, int u, long cost, bool &Relaxed){
  if (Dist[v]>Dist[u]+cost){
    Dist[v] = Dist[u]+cost;
    Relaxed=true;
  }
}

bool BellmanFord(int vertex, vector<vector<int> > &adj, vector<vector<int> > cost, vector<long long> &Dist){
  Dist[vertex]=0;
  bool Relaxed = true;
  int count = 0;
  while(Relaxed && (count!=adj.size())){
    Relaxed = false;
    for(size_t k=0;k<adj.size();k++){
      vector<int> neighbours = adj[k];
      for(size_t i=0;i<neighbours.size();i++)
        EdgeRelax(Dist,neighbours[i],k,cost[k][i],Relaxed);
    }
    count++;
  } 
  if(count==adj.size())
    return true;
  return false;  
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  vector<long long> Dist(adj.size(),INT_MAX);
  for(size_t i=0;i<adj.size();i++){
    if(Dist[i]==INT_MAX){
      bool tmp = BellmanFord(i,adj,cost,Dist);
      if(tmp)
        return 1;
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
