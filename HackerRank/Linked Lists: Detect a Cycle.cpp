// https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
bool has_cycle(Node* head) {
    int itr = 0;
    const int MAX = 100;
    while(head != nullptr && itr <= MAX){
        itr++;
        head = head->next;
    }
    return itr > MAX;
}
