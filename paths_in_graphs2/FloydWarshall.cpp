#include<iostream>
#include<cstdio>
#include<climits>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

long **Mat(NULL);

vector<int> split(string str){
    size_t pos = 0;
    string token;
    vector<string>temp;
    while ((pos = str.find(" ")) != string::npos){
        token = str.substr(0, pos);
        //cout << token << std::endl;
        temp.push_back(token);
        str.erase(0, pos + 1);
        //cout << str << std::endl;
    }
    token = str.substr(0, pos);
    temp.push_back(token);
    vector<int> input;
    for(size_t i=0;i<temp.size();i++){
        stringstream geek(temp[i]);
        if(temp[i]=="INF"){
            input.push_back(INT_MAX);
            continue;
        }
        int x = 0;
        geek>>x;
        input.push_back(x);
    }
    
    return input;
}


void printMat(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(Mat[i][j]==INT_MAX){
                cout<<"INF"<<"  ";
                continue;
            }
            cout<<Mat[i][j]<<"  ";
        }
    cout<<endl;
    }
}

void FloydWarshall(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(Mat[i][j]>Mat[i][k]+Mat[k][j])
                    Mat[i][j]=Mat[i][k]+Mat[k][j];
            }
        }
    }
}

int main() {  
  int n(4);
  Mat = new long*[n];  
  for(int i = 0; i < n; i++){
      Mat[i] = new long[n];
      string input;
      getline(cin,input);
      vector<int> List = split(input);
      for(int j=0;j<List.size();j++){
        Mat[i][j]=List[j];
      }
  }
  FloydWarshall(n);
  printMat();

}