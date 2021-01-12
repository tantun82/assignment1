#include<stdio.h> 
#include<stdlib.h> 

struct Node{ 
    int number; 
    struct Node* next; 
};  

void push(struct Node** headref, int newnumber) { 
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
    newnode->number  = newnumber; 
    newnode->next = (*headref);      
    (*headref)    = newnode; 
} 

void upgrade(struct Node* head) { 
    struct Node* current = head; 
    struct Node* nextnext;  
    if (current == NULL)  
       return;  
    while (current->next != NULL) { 
       if (current->number == current->next->number) {   
           nextnext = current->next->next; 
           free(current->next); 
           current->next = nextnext;   
        } 
       else { 
          current = current->next;  
        } 
    } 
}

void printList(struct Node *node) { 
    while (node!=NULL) { 
       printf("%d ", node->number); 
       node = node->next; 
    } 
}  

int main() { 
    struct Node* head = NULL;
    push(&head, 10); 
    push(&head, 5); 
    push(&head, 5);   
    push(&head, 3); 
    push(&head, 1); 
    push(&head, 1);                                     
    printf("\n Before  "); 
    printList(head);  
    upgrade(head);  
    printf("\n After ");          
    printList(head);             
    return 0; 
} 