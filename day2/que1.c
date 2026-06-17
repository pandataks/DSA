#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode dummy;
    struct ListNode *tail = &dummy;

    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {

        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;

    return dummy.next;
}

void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {

    struct ListNode *a1 = malloc(sizeof(struct ListNode));
    struct ListNode *a2 = malloc(sizeof(struct ListNode));
    struct ListNode *a3 = malloc(sizeof(struct ListNode));

    a1->val = 1;
    a2->val = 2;
    a3->val = 4;

    a1->next = a2;
    a2->next = a3;
    a3->next = NULL;

    struct ListNode *b1 = malloc(sizeof(struct ListNode));
    struct ListNode *b2 = malloc(sizeof(struct ListNode));
    struct ListNode *b3 = malloc(sizeof(struct ListNode));

    b1->val = 1;
    b2->val = 3;
    b3->val = 4;

    b1->next = b2;
    b2->next = b3;
    b3->next = NULL;

    struct ListNode *result = mergeTwoLists(a1, b1);

    printList(result);

    return 0;
}