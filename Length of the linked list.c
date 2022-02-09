#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int a;
    struct _Node* next;
}Node;

void Add2List(Node** Headptr, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if(*Headptr == NULL)
    {
        new_node->a = data;
        new_node->next = NULL;
    
        *Headptr = new_node;
    }else{
        Node* Prev_node = *Headptr;
        
        while(Prev_node->next != NULL)
        {
            Prev_node = Prev_node->next;
        }
        
        Prev_node->next = new_node;
        new_node->a = data;
        new_node->next = NULL;
        
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
    Print(&Head);
    printf("\n The lenth of the linked list is \n");
    getlength(&Head);
}
