#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <unordered_map>

using std::vector;
using std::pair;
using std::unordered_map;

class DisjointSet { 
   unordered_map<int, int> parent;
   public:
   void makeSet(int num){
      for(int i=0;i<num;i++) 
        parent[i] = i;
   }
   int Find(int l) { 
      if(parent[l] == l) 
        return l;
      return Find(parent[l]); 
   }
   void Union(int m, int n) { 
      int x = Find(m);
      int y = Find(n);
      parent[x] = y;
   }
};

bool sortbysec(const pair<pair<int,int>,double> &a, const pair<pair<int,int>,double> &b){
    return (a.second < b.second);
}

double Distance(int x1, int y1, int x2, int y2){
  return sqrt(pow((x1-x2),2)+pow((y1-y2),2)); 
}

double kruskals(vector<pair<pair<int,int>,double> > Edge, vector<int> x, vector<int> y, int k){
  int SetCount = x.size();
  DisjointSet Set;
  Set.makeSet(x.size());
  int i=0;
  double res=0;
  while(SetCount>=k){
    int start,end;
    double w = Edge[i].second;
    start = Edge[i].first.first;
    end = Edge[i].first.second;
    if(Set.Find(start)!=Set.Find(end)){
      res = w;
      Set.Union(start,end);
      SetCount--;
    }
    i++;
  }
  return res;
}

double clustering(vector<int> x, vector<int> y, int k) {
  vector<pair<pair<int,int>,double> > Edge;
  for(size_t i=0;i<x.size();i++){
    for(size_t j=0;j<x.size();j++){
      if(i==j)
        continue;
      double tmp = Distance(x[i],y[i],x[j],y[j]); 
      Edge.push_back(std::make_pair(std::make_pair(i,j),tmp)); 
    }
  }
  sort(Edge.begin(),Edge.end(),sortbysec);  
  double result = kruskals(Edge,x,y,k);
  return result;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::fixed << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
