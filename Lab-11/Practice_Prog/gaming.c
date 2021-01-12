#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
  char info;
  struct node *link;
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
NODE insert_rear(NODE first,char item)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
 return temp;
cur=first;
while(cur->link!=NULL)
 cur=cur->link;
cur->link=temp;
return first;
}
void display(NODE first)
{
 NODE temp;
 if(first==NULL)
 printf("list empty cannot display items\n");
 for(temp=first;temp!=NULL;temp=temp->link)
  {
  printf("%c",temp->info);
  }
  printf("\n");
}
NODE reverse(NODE first)
  {
    NODE cur,temp;  
    cur=NULL;
    while(first!=NULL)
    {
        temp=first;
        first=first->link;
        temp->link=cur;
        cur=temp;
    }
    return cur;
}
int main()
{
char item[50];
NODE first=NULL;
NODE second=NULL;
printf("\n--GAMING CENTRE--\n");
printf("\nEnter name in reverse order\n");
scanf("%s",item);
for(int i=0;i<strlen(item);i++)
{
    first=insert_rear(first,item[i]);
}
second=reverse(first);
printf("Welcome Customer ");
display(second);
}
