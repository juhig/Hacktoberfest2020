/* This algorithm can detect a loop in a singly Linked List with time complexity O(n)
and space complexity O(1).
*/

/* Design of a node.

struct Node {
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
}
*/
// isLoop function takes pointer to the head node as it's only argument
// and returns true if loop is detected, else return false.


bool isLoop(Node *head) {
    Node *fast, *slow;
    fast = head;
    slow = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}



