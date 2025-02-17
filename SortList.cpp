class Solution {
    public:
        ListNode* merge(ListNode* left, ListNode* right) {
            if (!left) return right;
            if (!right) return left;
            
            if (left->val < right->val) {
                left->next = merge(left->next, right);
                return left;
            } else {
                right->next = merge(left, right->next);
                return right;
            }
        }
        
        ListNode* sortList(ListNode* head) {
            if (!head || !head->next) return head;
            
            ListNode* slow = head, *fast = head, *prev = nullptr;
            
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            
            prev->next = nullptr;
            ListNode* left = sortList(head);
            ListNode* right = sortList(slow);
            
            return merge(left, right);
        }
    };
    
    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL\n";
    }
    