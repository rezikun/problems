class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        for(ListNode *it = head; 1 == 1; it = it->next){
            ++count;
            if(it->next == NULL){
                it->next = head;
                break;
            }
        }
        ListNode *l2head;
        ListNode *it = head;
        k = k%count;
        for(int i = 0; i < abs(count - k - 1); ++i){
            it = it->next;
        }
        l2head = it->next;
        it->next = NULL;
        return l2head;
    }
};
