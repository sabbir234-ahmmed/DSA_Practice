class Solution {

    ///implement dfs 
    void dfs(unordered_map<string, vector<pair<string,double>> >& adj, 
             string src, string dst, unordered_set<string>& visited, 
            double product, double &ans){
            // if source already visited then return 
            if(visited.find(src) != visited.end()){
                return;
            }

             //visit the curr src
            visited.insert(src);

            //if source == dst then return ans
            if(src==dst){
                ans=product;
                return ;
            }
            
           

            //try to reach dst
            for(auto &p : adj[src]){
                string v=p.first;
                double val= p.second;
                 

                // call for curr v
                dfs(adj, v, dst, visited, product*val, ans );
            }
                   
            }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        ///determine the size of equations
        int n=equations.size();

        /// declare a unordered_map to established adjacency list
        unordered_map< string, vector<pair<string,double>> > adj;

        //iterate the equations and making graph
        for(int i=0;i<n;i++){
            //get string variables
            string u=equations[i][0];
            string v=equations[i][1];

            //get values
            double val=values[i];  // u/v
            //establishing adjacency 
            adj[u].push_back({v,val});  // you may assume that val= cost from u to v
            //consider reverse also
            adj[v].push_back({u, 1.0/val}); // v/u

        }

        /// declaring a vector for storing answer
        vector<double> result;

        ///generate ans for all queries
        for(int i=0;i<queries.size();i++){
            //source
            string src=queries[i][0];
            //destination
            string dst=queries[i][1];

            double ans=-1.0;
            double product=1.0;

            // check src exist or not
            if(adj.find(src) != adj.end()){
                // take a space for checking visited node
                unordered_set<string> visited;

                //src exist
                //perform dfs
                dfs(adj, src, dst, visited, product, ans);

            }

            //store ans
            result.push_back(ans);
        }

        return result;
    }
};