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
public:
    Node* util(Node* node,unordered_map<Node*,Node*>& mp){
        // we have a node lets create this first
        Node* ref = new Node(node->val);
        //lets create the neighbors
        mp[node]=ref;
        for(auto it : node->neighbors){
            if(mp.find(it)==mp.end()){
               ref->neighbors.push_back(util(it,mp));
            }else{
                ref->neighbors.push_back(mp[it]);
            }
        }
        return ref;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node== NULL)return NULL;
        return util(node,mp);
    }
};