
class Solution{
    int postNum=1;
    
    public:
	//Function to detect cycle in an undirected graph.
	
	void Explore(bool &Cycle, vector<bool> &Visited, int vertex, vector<int> adj[], vector<int> &postNumber){
	    Visited[vertex]=true;
	    int count=0;
	    for(int i=0;i<adj[vertex].size();i++){
	        if(Visited[adj[vertex][i]]==false){
	            Visited[adj[vertex][i]]=true;
	            Explore(Cycle,Visited,adj[vertex][i],adj,postNumber);
	        }
	        else if(postNumber[adj[vertex][i]]==-1)
	            count++;
	        if(count==2){
	            Cycle=true;
	            break;
	        }
	    }
	    postNumber[vertex]=postNum++;
	}
	
	bool isCycle(int V, vector<int> adj[]){
	   	vector<int> postNumber(V,-1);
	   	vector<bool> Visited(V,false);
	   	bool Cycle=false;
	   	for(int i=0;i<V;i++){
	   	    if(Visited[i]==false){
	   	        Explore(Cycle,Visited,i,adj,postNumber);
	   	        if(Cycle)
	   	           return Cycle;
	   	    }
	   	}
	   	return Cycle;
	}
};