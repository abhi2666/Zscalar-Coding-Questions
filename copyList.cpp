class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // step 1 --> create dup nodes in b/w org nodes
        Node* temp = head;
        while(temp){
            Node * newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        // step 2 --> make random pointer points in the right direction
        temp = head;
        while(temp){
            if(temp->random != NULL){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        // step 3 --> your both lists are ready.. now detach them 
        
        Node* dummy = new Node(0);
        Node*slow = head;
        temp = dummy;
        Node* fast;
        while(slow){
            fast = slow->next->next;
            temp->next = slow->next;
            slow->next = fast;
            temp = temp->next;
            slow = fast;
            
        }

        return dummy->next;

    }
};