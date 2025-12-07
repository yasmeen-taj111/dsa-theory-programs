#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} *NODE;

NODE createNode(int x) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

NODE insertEnd(NODE head, int x) {
    NODE newNode = createNode(x);

    if (head == NULL)
        return newNode;

    NODE temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int findSmallest(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    int min = head->data;
    NODE temp = head->next;

    while (temp != NULL) {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }

    return min;
}

int main() {
    NODE head = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    int smallest = findSmallest(head);
    if (smallest != -1)
        printf("Smallest value in the list = %d\n", smallest);

    return 0;
}
