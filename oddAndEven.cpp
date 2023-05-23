/*

You have to put all the odd numbered nodes to left and even to right
Input - 
2 
1 2 3 -4 5 6 -1    
1 2 3  4 5 6  7
-3 -1 

output - 
1 3 5 2 -4 6 -1
-3 -1 

*/



Node *oddEvenLinkedList(Node *head) {
    // Write your code here.
    if(head == NULL) return head;

    Node *odd = head;
    Node *even = head->next;
    Node *evenS = even;

    // you just have to traverse and make some new connections
    while(!even && !even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        // same for even
        even->next = odd->next;
        even = even->next;       
    }
    odd->next = evenS;


    return head;
    
}