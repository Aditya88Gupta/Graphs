#include <iostream>
#include <vector>

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

int number_of_components(vector<vector<int> > &adj, vector<bool> &Visited) {
  int res = 0;
  for (int i=0;i<adj.size();i++){
    if(Visited[i]==false){
      res++;
      Explore(adj,i,Visited);
    }
  }
  return res;
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
  std::cout << number_of_components(adj,Visited);
}
