// Time complexity:
// queue push, pop :
// O(n)
// indices group iteration from map:
// O(a)+O(b)+O(c)+.....= O(n)
// Hence a+b+c=n the total nuber of indices of the given array
// Total Time complexity: O(n)+O(n)= O(n)

// space complexity:
// O(n) for using , extra space map and vector

class Solution {

    public:
          int bfs(vector<int>& arr, vector<bool>& visited, int n){
            /// base cases
            if(n==1){
                return 0;
            }


            queue<int>q;
            q.push(0);
            visited[0]=true;

            /// creat a map , value ---> index 
            map<int, vector<int>>indices;

            // sotre  map
            for(int i=0;i<n; i++){
                int value=arr[i];
                int index=i;

                indices[value].push_back(i);
            }



            int mini_jumps=0;

            while(!q.empty()){

                int qSize=q.size();
                
               
                // process for all current level place
                // that means move for curr place
                while(qSize--){

                      int currPlace=q.front();
                      q.pop();

                      // is carrPlace== destination
                      if(currPlace==(n-1)){
                        return mini_jumps;
                       }

                    // move1 -----currPlace+1
                    if(currPlace+1 <n && !visited[currPlace+1]){
                        // if not visited this palce then take a successfull move 
                         
                            q.push(currPlace+1);
                            visited[currPlace+1]=true;
                    }

                    // move2 ---- currPlace-1
                    if(currPlace-1 >=0 && !visited[currPlace-1]){
        
                        // if not vistied then take a move
                       
                            q.push(currPlace-1);
                            visited[currPlace-1]=true;
                    
                    }


                    // move3 --- where arr[currPlace]=== arr[j]
                    // then move currPlace= j
                    int value=arr[currPlace];

                    //iterate the indices of current value
                
                    for(auto index : indices[value]){
                        // visit current index if it is not yet visted
                        if(!visited[index]){
                            q.push(index);
                            visited[index];
                        }
                    }

                    // clear the current value's indices
                    indices[value].clear();

                }

                 mini_jumps++;



            }

            return mini_jumps;


          }
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();

        vector<bool>visited(n,false);

        int mini_jump=bfs(arr, visited, n);

        return mini_jump;

    }
};