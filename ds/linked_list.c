#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) return;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = *head;
    
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }
    
    prev->next = temp->next;
    free(temp);
}

Node* search(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

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

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    
    printf("Linked List after inserting at the beginning:\n");
    printList(head);

    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("\nLinked List after inserting at the end:\n");
    printList(head);

    int searchValue = 40;
    Node* result = search(head, searchValue);
    if (result != NULL) {
        printf("\nNode with value %d found in the list\n", searchValue);
    } else {
        printf("\nNode with value %d not found in the list\n", searchValue);
    }

    deleteNode(&head, 30);
    printf("\nLinked List after deleting node with value 30:\n");
    printList(head);

    deleteNode(&head, 100);

    printf("\nFinal Linked List:\n");
    printList(head);

    return 0;
}
