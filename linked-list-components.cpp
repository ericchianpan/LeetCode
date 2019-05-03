/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> g(G.begin(), G.end());
        int num_components = 0;
        while(head != NULL) {
            if(g.find(head->val) == g.end()) {
                head = head->next;
                continue;
            }
            num_components++;
            while(g.find(head->val) != g.end()) {
                head = head->next;
                if(head == NULL) break;
            }
        }
        return num_components;
    }
};

/*
    std::unordered_set and std::unordered_map are implement by hash table
    std::set and std::map are balanced binary search tree (red black tree)
    in the small scale data, use hash table is faster than red black tree.
*/
