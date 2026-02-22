class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //create a adjacency list (graph)
        unordered_map<int, list<int> >adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];

            adj[u].push_back(v);
        }

        //calculate indegree
        vector<int> indegree(numCourses,0);
        for(auto a: adj){
            for(auto b: a.second){
                indegree[b]++;
            }
        }

        ///perform bfs 
        queue<int>q;
        /// push all courses which have 0 indegree
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
               q.push(i);
            }
        }

        //create ans vector
        vector<int>ans;
        while(!q.empty()){
            int f=q.front();
            q.pop();

            //add to the ans
            ans.push_back(f);
            //reduce indegree of it's neighbour
            for(auto nei: adj[f]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }

        if(ans.size()==numCourses){
            return true;
        } 

        return false;
    }
};