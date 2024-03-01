#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int newData) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Assign data to new node
    newNode->data = newData;
    // Link the new node to the current head
    newNode->next = *head;
    // Update the head to point to the new node
    *head = newNode;
}

// Function to print all elements of the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

typedef struct Real{
    double number;
}REAL_t;

typedef double REAL;
