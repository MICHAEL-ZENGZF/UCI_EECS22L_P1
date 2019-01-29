//Linked list will be used to implement this stack
//#include<stdlib.h>
//#include<stdio.h>
//check that these above include statements are necessary
struct Node
{
    char* log;
    struct Node *next;
    struct Node *prev;
}
void stack_push(struct Node** head_ref, char* new_log, size_t data_size)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->log = malloc(data_size);
    new_node->next = (*head_ref);
    (*head_ref)->prev = new_node;
    new_node->prev = NULL;

    // Copy contents of new_log to newly allocated memory. 
    // Assumption: char takes 1 byte. 
    int i;
    for(i=0; i<data_size; i++)
    {
        *(char *)(new_node->log + i) = *(char *)(new_log + i);
    }
    // Change head pointer as new node is added at the beginning 
    (*head_ref)    = new_node; 
}
char* stack_pop()
{
    //will write when Michael confirms current design
}
int stack_get_size()
{
    //will write when Michael confirms current design
}
