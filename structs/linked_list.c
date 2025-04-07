#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;  // Memory allocation failed
    newNode->next = *head;  // Link the new node to the current head
    *head = newNode;        // Update the head to the new node
}

// Function to insert a new node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;  // Memory allocation failed
    
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, the new node becomes the head
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to the last node
    }
    temp->next = newNode;  // Link the new node at the end
}

// Function to delete a node with a specific value
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = *head;
    
    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Move head to the next node
        free(temp);          // Free the old head node
        return;
    }
    
    // Search for the node to be deleted
    Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    // If the node was not found
    if (temp == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }
    
    prev->next = temp->next;  // Unlink the node from the list
    free(temp);               // Free the memory occupied by the node
}

// Function to search for a node with a specific value
Node* search(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;  // Node found
        }
        temp = temp->next;
    }
    return NULL;  // Node not found
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list operations
int main() {
    Node* head = NULL;  // Start with an empty linked list

    // Inserting elements at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    
    printf("Linked List after inserting at the beginning:\n");
    printList(head);

    // Inserting elements at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("\nLinked List after inserting at the end:\n");
    printList(head);

    // Searching for an element
    int searchValue = 40;
    Node* result = search(head, searchValue);
    if (result != NULL) {
        printf("\nNode with value %d found in the list\n", searchValue);
    } else {
        printf("\nNode with value %d not found in the list\n", searchValue);
    }

    // Deleting an element
    deleteNode(&head, 30);
    printf("\nLinked List after deleting node with value 30:\n");
    printList(head);

    // Deleting an element that doesn't exist
    deleteNode(&head, 100);  // This node is not present

    // Final list print
    printf("\nFinal Linked List:\n");
    printList(head);

    return 0;
}
