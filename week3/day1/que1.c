#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    struct ListNode *n1 = malloc(sizeof(struct ListNode));
    struct ListNode *n2 = malloc(sizeof(struct ListNode));
    struct ListNode *n3 = malloc(sizeof(struct ListNode));

    n1->val = 1;
    n2->val = 2;
    n3->val = 3;

    n1->next = n2;
    n2->next = n3;
    n3->next = n1; // cycle

    if (hasCycle(n1))
        printf("Cycle Found\n");
    else
        printf("No Cycle\n");

    return 0;
}