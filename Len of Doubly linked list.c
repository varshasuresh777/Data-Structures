#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int a;
    struct Node* next;
    struct Node* prev; 
}Node;

void Add2List(Node** Headptr, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if(*Headptr == NULL)
    {
        new_node->a = data;
        new_node->next = NULL;
        new_node->prev = NULL; 
        *Headptr = new_node;
    }else{
        Node* Curr_Node = *Headptr;
        
        while(Curr_Node->next != NULL)
        {
            Curr_Node = Curr_Node->next;
        }
        
        Curr_Node->next = new_node;
        new_node->a = data;
        new_node->prev = Curr_Node;
        
    }
    
}
void Print(Node** Head)
{
    Node* Curr_Node = *Head;
    
    while(Curr_Node != NULL)
    {
        printf("%d\t", Curr_Node->a);
        Curr_Node = Curr_Node->next;
    }
}

int getlength(Node** Head)
{
    int count=0;
    Node* Curr_Node = *Head;
    while(Curr_Node != NULL){
         count++; 
        Curr_Node = Curr_Node->next; 
    }
    printf("%d", count); 
}

void main()
{
    Node* Head = NULL;
    printf("linked list is\n");
    Add2List(&Head,6);
    Add2List(&Head,8);
    Add2List(&Head,10);
    Add2List(&Head,22);
    Add2List(&Head,35);

    Print(&Head);
    printf("\n The lenth of the doubly linked list is \n");
    getlength(&Head);
}
