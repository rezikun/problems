class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        if(head->next == head)
            return head;
        if(head->next == NULL)
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy, *second = dummy;
        bool flag = false;
        while(first != second || flag == false){
            flag = true;
            for(int i = 0; i < 2; ++i){
                if(second->next == first){
                    second = second->next;
                    break;
                }
                if(second->next != NULL)
                    second = second->next;
                else 
                    return NULL;
            }
            if(second == first){
                break;
            }
            if(first->next != NULL)
                first = first->next;
        }
        second = second->next;
        int count = 1;
        while(second != first){
            ++count;
            second = second->next;
        }   
        first = head;
        ListNode *it = first;
        for(; 1 == 1; first = first->next){
            int i = 0;
            for(it = first; i < count; it = it->next){
                if(it->next == first)
                    return it->next;
                ++i;
            }
        }
    }
};
