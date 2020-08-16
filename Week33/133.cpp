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
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        set<int> visited;
        queue<Node*> qn;
        unordered_map<int, Node*> nmap;

        visited.insert(node->val);
        qn.push(node);
        Node* head = new Node(node->val);
        nmap[node->val] = head;
        // qn2.push(head);
        while(!qn.empty()){
            Node* tmp = qn.front();
            qn.pop();
            Node* curr = nmap[tmp->val];
            for(auto p: tmp->neighbors){
                if(nmap.count(p->val) == 0){
                    nmap[p->val] = new Node(p->val);
                }
                curr->neighbors.emplace_back(nmap[p->val]);
            }
            // copy
            // qn2.push(new Node(tmp->val, tmp->neighbors));
            cout << tmp->val;
            for(auto p: tmp->neighbors){
                if(visited.count(p->val) == 0){
                    qn.push(p);
                    visited.insert(p->val);
                }
            }
        }

        return head;


    }
};