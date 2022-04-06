
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    inline int sum(char a, char b, int excess) {
        return a - '0' + b - '0' + excess;
    }
    
    ListNode* add(ListNode* l, int val) {
        ListNode *novo = new ListNode(val);
        l->next = novo;
        return novo;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string n1 = "", n2 = "";
        while(l1 != nullptr) {
            n1 += to_string(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            n2 += to_string(l2->val);
            l2 = l2->next;
        }
        ListNode* head;
        ListNode* l;
        head = new ListNode();
        l = new ListNode();
        int excess = 0;
        for(int i = 0; i < min(n1.length(), n2.length()); i++) {
            int val = sum(n1[i], n2[i], excess);
            excess = val >= 10 ? 1 : 0;
            if(head->next == nullptr) {
                l->val = val%10;
                head->next = l;
            }
            else
                l = add(l, val%10);
        }
        
        if(n1.length() < n2.length())
            swap(n1, n2);
        
        for(int i = n2.length(); i < n1.length(); i++) {
            int val = sum(n1[i], '0', excess);
            excess = val >= 10 ? 1 : 0;
            l = add(l, val%10);
        }
        if(excess)
            add(l, excess);
        return head->next;
    }
    
};
