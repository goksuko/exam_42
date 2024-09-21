#include <stdio.h>
#include <stdlib.h>

typedef struct s_linked
{
    int value;
    struct s_linked *next;
} t_linked;

t_linked *add_to_end_node(t_linked *head, int value)
{
    t_linked *new_node;
    t_linked *temp;

    new_node = malloc(sizeof(t_linked));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    if (head == NULL)
        return(new_node);
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    return (head);
}

t_linked * reverse_list(t_linked *head)
{
    t_linked *curr;
    t_linked *prev;
    t_linked *foll;

    curr = head;
    prev = NULL;
    while (curr != NULL)
    {
        
        foll = curr->next;
        curr->next = prev;
        prev = curr;
        curr = foll;
    }
    return (prev);
}

void print_linked(t_linked *head)
{
    t_linked *temp;

    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

int main()
{
    t_linked *head;

    head = NULL;
    head = add_to_end_node(head, 1);
    head = add_to_end_node(head, 2);
    head = add_to_end_node(head, 3);
    head = add_to_end_node(head, 4);
    head = add_to_end_node(head, 6);
    print_linked(head);
    head = reverse_list(head);
    print_linked(head);
    return(0);
    

}