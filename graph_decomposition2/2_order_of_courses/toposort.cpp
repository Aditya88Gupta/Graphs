#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

bool SortBySecond(const pair<int,int> &A, const pair<int,int> &B){ 
    return (A.second > B.second); 
}


void Explore(vector<bool> &Visited, vector<vector<int> > &adj, int vertex, vector< pair <int,int>> &Map, int &postNumber){
  Visited[vertex]=true;
  vector<int> neighbours=adj[vertex];
  for(int i=0;i<neighbours.size();i++){
    if (Visited[neighbours[i]]!=true)
      Explore(Visited,adj,neighbours[i],Map,postNumber);
  }
  Map[vertex].second=++postNumber;
}

void DFS(vector<bool> &Visited, vector<vector<int> > &adj, int n, vector< pair <int,int>> &Map){
  int postNumber=0;
  for (int i=0;i<n;i++){
    if(Visited[i]!=true){
      Explore(Visited,adj,i,Map,postNumber);
    }
  }
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector< pair <int,int>> Map;
  vector<int> order;
  vector<bool> Visited;
  for (size_t i = 0; i < adj.size(); i++){
    Visited.push_back(false);
    Map.push_back(std::make_pair(i,0));
  }
  DFS(Visited,adj,adj.size(),Map);
  sort(Map.begin(),Map.end(),SortBySecond);
  for (int i=0;i<Map.size();i++){
    //std::cout<<Map[i].first+1<<", "<<Map[i].second<<"\n";
    order.push_back(Map[i].first);
  }
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
