/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    void dfs(Node* node, Node* clone, unordered_map<Node*, Node*>& mp){
       // traverse the neighbor
       for(Node* nei: node->neighbors){
            //check is it's clone exist or not?
            if(mp[nei]==NULL){
                //create clone 
                Node* cloneNei= new Node(nei->val);
                mp[nei]=cloneNei;
                clone->neighbors.push_back(cloneNei);
                //call dfs
                dfs(nei, cloneNei, mp);

            }else{
                //no need to clone just push
                clone->neighbors.push_back(mp[nei]);
            }
       }
    }

public:
    Node* cloneGraph(Node* node) {
        //if the given Graph is NULL then Return NULL
        if(node==NULL){
            return NULL;
        }

        // clone the given node
        Node* clone_head= new Node(node->val);
        // trac the cloned node
        unordered_map<Node*, Node*>mp;
        mp[node]=clone_head;

        //now travese the whole given graph and clone the neighbor 
        dfs(node, clone_head, mp);

        // return the head of the Cloned graph
        return clone_head;

    }
};