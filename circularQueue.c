#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE *front = NULL, *rear = NULL;

// Function to create a new node
NODE* createNode(int x) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Enqueue operation
void enqueue(int x) {
    NODE* newNode = createNode(x);

    if (front == NULL) {  // First node
        front = rear = newNode;
        rear->next = front;   // Circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;   // Maintain circularity
    }
    printf("Inserted %d\n", x);
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    if (front == rear) {  // Only one element
        printf("Deleted %d\n", front->data);
        free(front);
        front = rear = NULL;
    } else {
        NODE* temp = front;
        printf("Deleted %d\n", temp->data);
        front = front->next;
        rear->next = front;   // Maintain circular link
        free(temp);
    }
}

// Display operation
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    NODE* temp = front;
    printf("Circular Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}
