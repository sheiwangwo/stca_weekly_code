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
    ListNode* cut(ListNode* head, int n){
        ListNode* p = head;
        while(p && --n){
            p = p->next;
        }
        if(!p){
            return NULL;
        }else{
            ListNode* next = p->next;
            p->next = NULL;
            return next;
        }

    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;

        while(left && right){
            if(left->val < right->val){
                p->next = left;
                left = left->next;
                p = p->next;
            }
            else{
                p->next = right;
                right = right->next;
                p = p->next;
            }
        }
        p->next = left ? left : right;
        return dummyHead->next;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        int len = 0;
        ListNode* p= head;
        while(p){
            p = p->next;
            len++;
        }
        cout << len << endl;

        for (int size = 1; size < len; size <<= 1) {
            ListNode* cur = dummyHead->next;
            ListNode* tail = dummyHead;

            while(cur){
                ListNode* left = cur;
                ListNode* right = cut(left, size);
                cur = cut(right, size);

                tail->next = merge(left,right);
                while(tail->next){
                    tail = tail->next;
                }

            }

        }
        return dummyHead->next;
    }
};