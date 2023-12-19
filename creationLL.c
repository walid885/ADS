#include <stdio.h>  
#include <stdlib.h>  
  
struct Node {  
    int data;  
    struct Node* next;  
};  
  
struct LinkedList {  
    struct Node* head;  
    int size;  
};  
  
void init(struct LinkedList* list) {  
    list->head = NULL;  
    list->size = 0;  
}  
  
void insert(struct LinkedList* list, int value) {  
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));  
    newNode->data = value;  
    newNode->next = list->head;  
    list->head = newNode;  
    list->size++;  
}  
  
void deleteNode(struct LinkedList* list, int pos) {  
    if (pos < 0 || pos >= list->size) {  
        printf("Invalid position!\n");  
        return;  
    }  
    if (pos == 0) {  
        struct Node* temp = list->head;  
        list->head = list->head->next;  
        free(temp);  
    } else {  
        struct Node* current = list->head;  
        for (int i = 0; i < pos-1; i++) {  
            current = current->next;  
        }  
        struct Node* temp = current->next;  
        current->next = temp->next;  
        free(temp);  
    }  
    list->size--;  
}  
  
void printList(struct LinkedList* list) {  
    struct Node* current = list->head;  
    while (current != NULL) {  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
  
int getSize(struct LinkedList* list) {  
    return list->size;  
}  
  
int main() {  
    struct LinkedList list;  
    init(&list);  
    insert(&list, 5);  
    insert(&list, 10);  
    insert(&list, 15);  
    printList(&list); // Output: 15 10 5  
    deleteNode(&list, 1);  
    printList(&list); // Output: 15 5  
    printf("Number of elements: %d\n", getSize(&list)); // Output: 2  
    return 0;  
}  
