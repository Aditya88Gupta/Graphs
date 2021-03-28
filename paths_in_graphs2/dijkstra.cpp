#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

typedef pair<int,long long> pi;

struct Comp { 
    constexpr bool operator()( 
        pair<int, long long> const& a, 
        pair<int, long long> const& b) 
        const noexcept 
    { 
        return a.second > b.second; 
    } 
};

void EdgeRelax(vector<long long> &Dist, int v, int u, long cost){
  if (Dist[v]>Dist[u]+cost){
    Dist[v] = Dist[u]+cost;
  }
}

long long Dijkstra(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {

  vector<long long> Dist(adj.size(),INT_MAX);
  vector<bool> Found(adj.size(),false);
  Dist[s] = 0;
  priority_queue<pi, vector<pi>, Comp> Q;
  for(int i=0;i<adj.size();i++){
    Q.push(std::make_pair(i,Dist[i]));
  }

  while (!Q.empty()){
    int vertex = Q.top().first;
    if(Found[vertex]==true){
      Q.pop();
      continue;
    }
    //std::cout<<Q.top().first+1<<" "<<Q.top().second<<"\n";
    Q.pop();
    Found[vertex]=true;
    vector<int> neighbours = adj[vertex];
    for(size_t i=0;i<neighbours.size();i++){
      long long tmp = Dist[neighbours[i]];
      EdgeRelax(Dist,neighbours[i],vertex,cost[vertex][i]);
      if(tmp!=Dist[neighbours[i]])
        Q.push(std::make_pair(neighbours[i],Dist[neighbours[i]]));
    }
  }
  if(Dist[t]!=INT_MAX)
    return Dist[t];
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << Dijkstra(adj, cost, s, t);
}
