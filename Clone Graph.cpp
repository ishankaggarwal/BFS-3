//Time Complexity- O(n+m)
//Space Complexity- O(n)

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node==NULL){
            return NULL;
        }
        
        vector<Node*> visited(101,NULL);
        Node* copy=new Node(node->val);
        visited[copy->val]=copy;
        
        for(auto curr:node->neighbors){
            if(visited[curr->val]==NULL){
                Node* newnode=new Node(curr->val);
                copy->neighbors.push_back(newnode);
                dfs(curr,newnode,visited);
            }
            else{
                copy->neighbors.push_back(visited[curr->val]);
            }
        }
        return copy;
    }
    
    void dfs(Node* curr,Node* node,vector<Node*> &visited){
        
        visited[node->val]=node;
        for(auto ele:curr->neighbors){
            if(visited[ele->val]==NULL){
                Node* newnode=new Node(ele->val);
                node->neighbors.push_back(newnode);
                dfs(ele,newnode,visited);
            }
            else{
                node->neighbors.push_back(visited[ele->val]);
            }
        }
    }
};