// 1 2 3 4  k = 2 
node *findKthFromLast(node *head, int k)
{
	node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    temp = head;
    int val = count-k-1;
    while(val--){
        temp = temp->next;
    }
    return temp;

}