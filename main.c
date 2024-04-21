#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node* next;
};


void traverseLinkedList(struct Node* head) {
    struct Node* current = NULL;
    current = head;

    while (current != NULL){
        printf("node = %d\n", current->val);
        current = current->next;
    }
}


void insertAtEnd(struct Node* head, struct Node* newNode) {
    if (head == NULL){
        head = newNode;
        return;
    }

    struct Node* current = NULL;
    current = head;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}


void insertAtBeginning(struct Node** head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = *head;

    *head = newNode;

}


void insertAtPosition(struct Node** head, int val, int pos){
    if (pos == 1){
        insertAtBeginning(head, val);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    int currPos = 1;
    struct Node* currNode = NULL, *prev = NULL;
    currNode = *head;

    while (currNode != NULL && currPos != pos){
        prev = currNode;
        currNode = currNode->next;
        ++currPos;
    }

    if (currNode == NULL){
        insertAtEnd(*head, newNode);
        return;
    }

    newNode->next = currNode;
    prev->next = newNode;
}


void deleteFirstNode(struct Node** head){
    if (*head == NULL){
        return;
    }

    struct Node* tmp = *head;

    *head = (*head)->next;

    free(tmp);
}

void deleteLastNode(struct Node** head){
    if (*head == NULL){
        return;
    }

    if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* curr = NULL;
    curr = *head;

    while (curr->next->next != NULL){
        curr = curr->next;
    }

    free(curr->next);
    curr->next = NULL;
}


void deleteAtPosition(struct Node** head, int pos){
    if (*head == NULL){
        return;
    }

    if (pos == 1){
        deleteFirstNode(head);
        return;
    }

    struct Node* curr = NULL, *prev = NULL;
    curr = *head;

    while (curr != NULL && pos != 1){
        prev = curr;
        curr = curr->next;
        --pos;
    }

    if (curr == NULL || curr->next == NULL){
        deleteLastNode(head);
        return;
    }

    prev->next = curr->next;
    free(curr);
}


void clear(struct Node** head){
    struct Node* curr = NULL, *prev = NULL;
    curr = *head;

    while (curr != NULL){
        prev = curr;
        curr = curr->next;

        free(prev);
        prev = NULL;
    }

    *head = NULL;
}


int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->val = 45;
    head->next = NULL;

    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    current->val = 98;
    current->next = NULL;

    head->next = current;

    current = (struct Node*)malloc(sizeof(struct Node));
    (*current).val = 123;
    (*current).next = NULL;

    head->next->next = current;


    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = 42;
    newNode->next = NULL;
    insertAtEnd(head, newNode);

    insertAtBeginning(&head, 111);
    insertAtBeginning(&head, 122);

    insertAtPosition(&head, 5, 5);

    // deleteFirstNode(&head);
    // deleteFirstNode(&head);

    // deleteLastNode(&head);
    // deleteLastNode(&head);

    // deleteAtPosition(&head, 2);

    clear(&head);

    insertAtBeginning(&head, 69);

    traverseLinkedList(head);
    printf("%d\n", head->val);
    return 0;
}