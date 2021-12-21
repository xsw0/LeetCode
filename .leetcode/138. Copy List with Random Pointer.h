/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> um;

        {
            Node* p = head;
            while (p)
            {
                um.insert({ p, new Node(p->val) });
                p = p->next;
            }
        }

        {
            Node* p = head;
            while (p)
            {
                um[p]->next = um[p->next];
                um[p]->random = um[p->random];
                p = p->next;
            }
        }

        return um[head];
    }
};
