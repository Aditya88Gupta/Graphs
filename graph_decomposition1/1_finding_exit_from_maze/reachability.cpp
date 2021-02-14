
#include<iostream>
#include<vector>

using std::vector;
using std::pair;


void Explore(vector<vector<int> > &adj, int x, vector<bool> &Visited){
  Visited[x]=true;
  vector<int> neighbours = adj[x];
  for(int i=0;i<neighbours.size();i++){
    if(Visited[neighbours[i]]==false)
      Explore(adj,neighbours[i],Visited);
  }  
}

int reach(vector<vector<int> > &adj, int x, int y, vector<bool> &Visited){
  Explore(adj,x,Visited);
  if (Visited[y]==true)
    return 1;
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<bool> Visited;
  for(int i=0;i<n;i++){
    Visited.push_back(false);
  } 
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1,Visited);
}
