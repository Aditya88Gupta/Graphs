#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::queue;
using std::pair;

int BFS(vector<vector<int> > &adj, int s, int t) {
  vector<pair<bool,int>> Dist;
  for(int i=0;i<adj.size();i++){
    pair<bool,int> tmp;
    tmp.first= false;
    Dist.push_back(tmp);
  } 
  Dist[s].first= true;
  Dist[s].second= 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()){
    int vertex= Q.front();
    Q.pop();
    vector<int> neighbours= adj[vertex];
    for(int i=0;i<neighbours.size();i++){
      if (Dist[neighbours[i]].first==false){
        Q.push(neighbours[i]);
        Dist[neighbours[i]].first= true;
        Dist[neighbours[i]].second= Dist[vertex].second+1;
      }
    }
  }
  if(Dist[t].first==false)
    return -1;
  return Dist[t].second;  
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << BFS(adj, s, t);
}
