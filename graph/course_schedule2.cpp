class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // declare an adj (graph)
        unordered_map<int,list<int>>adj;
        //build adj
        int n= prerequisites.size();
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
        }

        //count indegree
        vector<int> indegree(numCourses,0);
        for(auto i: adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        }


        /// perform bfs 
        queue<int>q;
        // push which nodes has 0 indegree
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        // implement bfs
        while(!q.empty()){
            int f=q.front();
            q.pop();

            //push ans
            ans.push_back(f);

            ///iterate through child
            for(auto nei: adj[f]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }

        }
     
     if(ans.size()!=numCourses){
        ans={};
     }
     return ans;
    }
};