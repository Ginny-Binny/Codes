
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* current = dummy;
        
        while (current->next && current->next->next) {
            int gcd_value = gcd(current->next->val, current->next->next->val);
            ListNode* new_node = new ListNode(gcd_value);
            new_node->next = current->next->next;
            current->next->next = new_node;
            current = new_node;
        }
        
        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
    
private:
    int gcd(int a, int b) {
        while (b) {
            a = a % b;
            std::swap(a, b);
        }
        return a;
    }
};