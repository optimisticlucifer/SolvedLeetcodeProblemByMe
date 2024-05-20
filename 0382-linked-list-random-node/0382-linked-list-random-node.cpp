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
    ListNode *head;
    int count=0;

    int countLength(ListNode* head){
        ListNode* pointer=head;
        int n=0;
        while(pointer){
            n++;
            pointer=pointer->next;
        }
        return n;
    }

    Solution(ListNode* head) {
        this->head=head;
        count=countLength(head);
    }
    
    int getRandom() {
        int random=rand()%count;
        ListNode* pointer=head;
        while(random){
            pointer=pointer->next;
            random--;
        }
        return pointer->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */