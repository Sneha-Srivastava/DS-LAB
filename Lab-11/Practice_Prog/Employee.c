#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
 
struct node
{
    char empid[100];
    char empName[100];
    char mobilenum[100];
    int hrs;

    
    struct  node *next;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
  printf("mem full\n");
  exit(0);
 }
 return x;
}

NODE insert_rear(NODE last, char empid[],char empName[],char mobilenum[100],int hrs)
{
    NODE new_node;
    new_node=getnode();
    strcpy(new_node->empid,empid);
    strcpy(new_node->empName,empName);
    strcpy(new_node->mobilenum,mobilenum);
    new_node->hrs=hrs;
    if(last==NULL)
    {
        new_node->next=new_node;
        return new_node;
    }
    else
    {
        new_node->next=last->next;
        last->next=new_node;
        last=new_node;
        return last;
    }
    
}

void display(NODE last)
{
    int flag=0;
    NODE i;
    printf("\n--DISPLAYING EMPLOYEE DETAILS--\n");
    if(last==NULL)
    {
        printf("LIST EMPTY\n");
        return;
    }
    for (i=last->next;i!=last;i=i->next)
    {
        if(i->hrs>=8)
        {
            flag=1;
            printf("ID: %s \n",i->empid);
            printf("NAME: %s \n",i->empName);
            printf("MOBILE NUMBER: %s \n",i->mobilenum);
            printf("HOURS WORKED: %d \n",i->hrs);
        }    
        else 
         printf("EMPLOYEES WORKED LESS THAN 8 HOURS\n");
    }
}
int main()
{
    int i=0;
    NODE last=NULL;
    int choice;
    char name[50];
    char mob[50];
    char id[50];
    int hrs;
    for(;;)
    {
    printf("\n --EMPLOYEE LIST--\n");
    printf("\n1.ENTER EMPLOYEE DETAILS\n2.DISPLAY EMPLOYEE DETAILS\n3.QUIT\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    printf("\n");
    
    
        switch(choice)
        {
            case 1:
            printf("Enter the Employee ID: ");
            scanf("%s",id);
            printf("Enter the Employee name: ");
            scanf("%s",name);
            printf("Enter the Employee mobile number : ");
            scanf("%s",mob);
            printf("Enter no. of hours worked : ");
            scanf("%d", &hrs);
            last=insert_rear(last,id,name,mob,hrs);
            break;
            case 2:
            if (last== NULL)
            {
                printf("\n List empty.");
                break;
            }
            display(last);
            break;
            case 3: exit(0);
            break;
            default: printf("Invalid choice");
        }
    }
    return 0;
}
