using namespace std;
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

struct ListNode
{
  int val;
  ListNode* next;
};

class Solution {
public:
    ListNode* findInsertAfter(ListNode* head, ListNode* search)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr && curr != search)
        {
            if(curr->val < search->val)
            {
                prev = curr;
                curr = curr->next;
            }
            else
                break;
       }
        return prev;        
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* result = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = NULL;
        ListNode* insertAfter = NULL;
        
        while(curr)
        {
            next = curr->next;
            if(curr->val < prev->val)
            {
                insertAfter = findInsertAfter(result, curr);
                prev->next = curr->next;
                if(insertAfter)
                {
                    ListNode* temp = insertAfter->next;
                    insertAfter->next = curr;
                    curr->next = temp;
                }
                else
                {
                    curr->next = result;
                    result = curr;
                }
            }
            else
            {
                prev = curr;
            }
            curr = next;
        }
        return result;
    }
};

//todo 
int main()
{
  // insert sort list code goes here
  return;
}
