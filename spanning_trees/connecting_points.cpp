#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

typedef pair<int,double> pi;

struct Comp { 
    constexpr bool operator()( 
        pair<int, double> const& a, 
        pair<int, double> const& b) 
        const noexcept 
    { 
        return a.second > b.second; 
    } 
};

double Distance(int x1, int y1, int x2, int y2){
  return sqrt(pow((x1-x2),2)+pow((y1-y2),2)); 
}

double minimum_distance(vector<int> x, vector<int> y){
  vector<double> Dist(x.size(),INT_MAX);
  double result=0;
  vector<bool> Found(x.size(),false);
  Dist[0] = 0;
  priority_queue<pi, vector<pi>, Comp> Q;
  for(int i=0;i<x.size();i++){
    Q.push(std::make_pair(i,Dist[i]));
  }
  while(!Q.empty()){
    int vertex = Q.top().first;
    if(Found[vertex]==true){
      Q.pop();
      continue;
    }
    Q.pop();
    Found[vertex]=true;
    result+= Dist[vertex];
    for(size_t i=0;i<x.size();i++){
      if(Found[i]==true)
        continue;
      double tmp = Distance(x[i],y[i],x[vertex],y[vertex]); 
      if(tmp<Dist[i]){
        Q.push(std::make_pair(i,tmp));
        Dist[i]=tmp;
      }
    }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout<<std::fixed;
  std::cout << std::setprecision(9) << minimum_distance(x, y) << std::endl;
}
