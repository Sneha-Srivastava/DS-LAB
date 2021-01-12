#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[100];
    struct node *next;
};

typedef struct node* Node;

Node push(char ele[], Node top)
{
    if (top == NULL)
    {
        top =(Node)malloc(sizeof(struct node));
        top->next = NULL;
        strcpy(top->data,ele);
    return top;
    }
    else
    {
        Node temp =(Node)malloc(sizeof(struct node));
        temp->next = top;
        strcpy(temp->data,ele);
    return top;
    }
}
Node pop(Node top)
{
    Node t = top;

    if (t == NULL)
    {
        printf("\nNOT AVAILABLE");
        return top;
    }
    else
        t = t->next;
    printf("\n PREVIOUS URL ON CLICKING BACK BUTTON : %s", top->data);
    free(top);
    top = t;
    return top;
}

int main()
{
    int ch;
    char no[100];
    Node top = NULL;
    while (1)
    {
        printf("\n 1.CURRENT URL\n 2.PREVIOUS URL\n 3.QUIT\n");
        printf("\n Enter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:printf("CURRENT URL: ");
                   scanf("%s", no);
                   top = push(no, top);
                   break;
            case 2:top = pop(top);
                   break;
            case 3:exit(0);
            default :printf("INVALID INPUT\n");
                 break;
        }
    }   
    return 0;
}

