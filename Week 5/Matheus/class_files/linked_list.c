#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;  

int main(void)
{
    node *list = NULL; //It is best to initialize every pointer to a NULL value
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n -> number = 1;
    n -> next = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n -> number = 2;
    n -> next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n -> number = 3;
    n -> next = NULL;
    list->next->next = n;

    for (node *tmp = list; tmp != NULL; tmp = tmp->next) //This for loop is strange as fuck.. First you create a node variable, then
                                                         //iterate over all next values printing the number field. This yields the list
                                                         //contained in the list variable
    {
        printf("%i\n", tmp -> number);
    }
    
    while (list !=NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}