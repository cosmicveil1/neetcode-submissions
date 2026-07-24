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

   ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
         //step1:find the middle of the linked list using hare and tortoise
         ListNode* slow=head;
         ListNode* fast=head;
         ListNode* beforeslow=NULL;

         while(fast!=NULL && fast->next!=NULL){
            beforeslow=slow;
            slow=slow->next;
            fast=fast->next->next;
         }

         /*
        Example:
        1 -> 2 -> 3 -> 4 -> 5 -> 6

        beforeSlow = 3
        slow       = 4
        */

        //split the list in 2 halves
        beforeslow->next=NULL;

        /*
        First half:
        1 -> 2 -> 3 -> NULL

        Second half:
        4 -> 5 -> 6 -> NULL
        */

        // Step 3: Reverse the second half
        ListNode* second=reverseList(slow);

         /*
        Reversed second half:
        6 -> 5 -> 4 -> NULL
        */

        ListNode* first=head;

        // Used to attach the extra node in an odd-length list
        ListNode* lastInserted = NULL;

        // Step 4: Merge both halves alternately
        while(first!=NULL && second!=NULL){
            // Save next nodes before changing links
            ListNode* firstNext=first->next;
            ListNode* secondNext=second->next;

            //connect first node to second node
            first->next=second;
            // Connect second node to next node of first half
            second->next=firstNext;

            lastInserted=second;
            

            // Connect second node to next node of first half
            first = firstNext;
            second = secondNext;

        }

            // Odd-length list: second half can have one extra node
        if (second != NULL) {
            lastInserted->next = second;
        }


        
    }
};
