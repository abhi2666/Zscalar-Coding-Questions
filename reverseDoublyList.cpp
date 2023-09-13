Node* reverseDLL(Node* head)
{   
    Node* p1 = NULL;
    Node*p2 = head;
    while(p2){
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }   
    head = p1;
    return head;
}
