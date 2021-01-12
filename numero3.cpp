#include<stdio.h>  
#include<stdlib.h>  

struct Node  {  
    int number;  
    struct Node* next;  
};   
  
void push(struct Node** head1, int newnum) {  

    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));  

    newnode->number = newnum;  
    newnode->next = (*head1);  
    (*head1) = newnode;  
}  

void listprint(struct Node *ptr) {  
    while (ptr != NULL) {  
        printf("%d->", ptr->number);  
        ptr = ptr->next;  
    }  
    printf("NULL\n");  
}  

void middleprint(struct Node *head)  {  
    struct Node *slowptr = head;  
    struct Node *fastptr = head;  
  
    if (head!=NULL)  {  
        while (fastptr != NULL && fastptr->next != NULL) {  
            fastptr = fastptr->next->next;  
            slowptr = slowptr->next;  
        }  
        printf("The middle is [%d]\n\n", slowptr->number);  
    }  
} 

int main() {  
    struct Node* head = NULL;  
    int i;  
    for (i=5; i>0; i--)  {  
        push(&head, i);  
        listprint(head);  
        middleprint(head);  
    }  
    return 0;  
}  
