#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


#include "llrec.h"

static void llpivotHelper(Node* curr, int pivot,
                          Node*& smaller, Node*& smallerTail,
                          Node*& larger, Node*& largerTail)
{
    if (curr == NULL)
    {
        return;
    }

    Node* next = curr->next;
    curr->next = NULL;

    if (curr->val <= pivot)
    {
        if (smaller == NULL)
        {
            smaller = curr;
            smallerTail = curr;
        }
        else
        {
            smallerTail->next = curr;
            smallerTail = curr;
        }
    }
    else
    {
        if (larger == NULL)
        {
            larger = curr;
            largerTail = curr;
        }
        else
        {
            largerTail->next = curr;
            largerTail = curr;
        }
    }

    llpivotHelper(next, pivot, smaller, smallerTail, larger, largerTail);
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    smaller = NULL;
    larger = NULL;

    Node* smallerTail = NULL;
    Node* largerTail = NULL;

    llpivotHelper(head, pivot, smaller, smallerTail, larger, largerTail);

    head = NULL;
}