#include<iostream>
#include<vector>
#include<unordered_set>

using std::vector;
using std::pair;
using std::unordered_set;

void Explore(vector<bool> &Visited, vector<vector<int> > &adj, int vertex, bool &flag, unordered_set <int> &track){
  Visited[vertex]=true;
  track.insert(vertex);
  vector<int> neighbours=adj[vertex];
  for(int i=0;i<neighbours.size();i++){
    if (Visited[neighbours[i]]!=true)
      Explore(Visited,adj,neighbours[i],flag,track);
    else if (track.find(neighbours[i])!=track.end())  
      flag=true;
  }
  track.erase(track.find(vertex));
}

int acyclic(vector<bool> &Visited, vector<vector<int> > &adj, int n){
  bool flag=false;
  for (int i=0;i<n;i++){
    if(Visited[i]!=true){
      unordered_set <int> track;
      Explore(Visited,adj,i,flag,track);
      if (flag)
        return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<bool> Visited;
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  for (size_t i = 0; i < n; i++)
    Visited.push_back(false);

  std::cout << acyclic(Visited,adj,n);
}
