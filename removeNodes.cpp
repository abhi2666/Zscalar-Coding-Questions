/*

Remove all the nodes with with value = k from list..

*/

Node *removeNodes(Node *head, int k)
{

    if (head == NULL)
    {
        return head;
    }

    // check if it is the head itself
    while(head && head->data == k)
    {
        head = head->next;
    }

    Node *p = head, *q = NULL
    ;
    while (p)
    {
        if (p->data == k)
        {
            q->next = p->next;
            p = q;
        }
        // if not then just move the pointers
        q = p;
        p = p->next;
    }

    return head;
}
