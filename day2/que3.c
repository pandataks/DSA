#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL;

    while (head != NULL) {
        struct ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *secondHalf = reverse(slow->next);

    struct ListNode *p1 = head;
    struct ListNode *p2 = secondHalf;

    while (p2 != NULL) {
        if (p1->val != p2->val)
            return false;

        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

int main() {
    struct ListNode *n1 = malloc(sizeof(struct ListNode));
    struct ListNode *n2 = malloc(sizeof(struct ListNode));
    struct ListNode *n3 = malloc(sizeof(struct ListNode));
    struct ListNode *n4 = malloc(sizeof(struct ListNode));

    n1->val = 1;
    n2->val = 2;
    n3->val = 2;
    n4->val = 1;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    if (isPalindrome(n1))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}