#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    smaller = NULL;
    larger = NULL;

    Node *smallTail = NULL;
    Node *largeTail = NULL;

    while (head != NULL)
    {
        Node *curr = head;
        head = head->next;
        curr->next = NULL;

        if (curr->val <= pivot)
        {
            if (smaller == NULL)
            {
                smaller = curr;
                smallTail = curr;
            }
            else
            {
                smallTail->next = curr;
                smallTail = curr;
            }
        }
        else
        {
            if (larger == NULL)
            {
                larger = curr;
                largeTail = curr;
            }
            else
            {
                largeTail->next = curr;
                largeTail = curr;
            }
        }
    }

    head = NULL;
}