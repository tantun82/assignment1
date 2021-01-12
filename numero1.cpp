#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 

struct Node { 
    int number; 
    struct Node* next; 
}; 

void Movenode(struct Node** dest, struct Node** source) { 
    struct Node* newNode = *source; 
    assert(newNode != NULL); 
    *source = newNode->next; 
    newNode->next = *dest; 
    *dest = newNode; 
} 

struct Node* SortnMerge(struct Node* First, struct Node* Second) { 
    struct Node temp; 
    struct Node* tail = &temp; 
    temp.next = NULL; 
    while (1) { 
        if (First == NULL) { 
            tail->next = Second; 
            break; 
        } 
        else if (Second == NULL) { 
            tail->next = First; 
            break; 
        } 
        if (First->number <= Second->number) 
            Movenode(&(tail->next), &First); 
        else
            Movenode(&(tail->next), &Second); 
        tail = tail->next; 
    } 
    return(temp.next); 
} 



void push(struct Node** head_ref, int new_number) { 

    struct Node* new_node = 
        (struct Node*) malloc(sizeof(struct Node)); 

    new_node->number  = new_number; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 

void printList(struct Node *node) { 
    while (node!=NULL) { 
        printf("%d ", node->number); 
        node = node->next; 
    } 
} 

int main() { 

    struct Node* res = NULL; 
    struct Node* First = NULL; 
    struct Node* Second = NULL; 

    push(&First, 20); 
    push(&First, 15); 
    push(&First, 10); 
  
    push(&Second, 5); 
    push(&Second, 3); 
    push(&Second, 2); 
    res = SortnMerge(First, Second); 
    printf("Result: \n"); 
    printList(res); 
  
    return 0; 
} 