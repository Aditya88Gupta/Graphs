#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool SortBySecond(const pair<int,int> &A, const pair<int,int> &B){ 
    return (A.second > B.second); 
}


void Explore_2(vector<bool> &Visited, vector<vector<int> > &adj, int vertex){
  Visited[vertex]=true;
  vector<int> neighbours=adj[vertex];
  for(int i=0;i<neighbours.size();i++){
    if (Visited[neighbours[i]]!=true)
      Explore_2(Visited,adj,neighbours[i]);
  }
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

int DFS(vector<bool> &Visited, vector<vector<int> > &adj, vector<vector<int> > &adjReverse, vector< pair <int,int>> &Map){
  int postNumber=0;
  for (int i=0;i<adj.size();i++){
    if(Visited[i]!=true){
      Explore(Visited,adjReverse,i,Map,postNumber);
    }
  }
  sort(Map.begin(),Map.end(),SortBySecond);
  for (size_t i = 0; i < adj.size(); i++)
    Visited[i]=false;
  int SCC=0;  
  for(int i=0;i<Map.size();i++){
    if(Visited[Map[i].first]!=true){
      Explore_2(Visited,adj,Map[i].first);
      SCC++;
    }
  }
  return SCC;
}

int number_of_strongly_connected_components(vector<vector<int> > &adj, vector<vector<int> > &adjReverse){
  vector< pair <int,int>> Map;
  vector<bool> Visited;
  for (size_t i = 0; i < adj.size(); i++){
    Visited.push_back(false);
    Map.push_back(std::make_pair(i,0));
  }  
  return DFS(Visited,adj,adjReverse,Map);
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adjReverse(n, vector<int>());
  
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adjReverse[y-1].push_back(x-1);
  }
  
  std::cout << number_of_strongly_connected_components(adj,adjReverse);
}
