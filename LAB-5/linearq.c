#include<stdio.h>
#include<stdlib.h>
#define qsize 5
int item,front=0,rear=-1,q[10];
void insertrear()
{
    if(rear==qsize-1)
    {
        printf("Queue overflow\n");
        return;
    }
    rear=rear+1;
    q[rear]=item;
}
int deletefront()
{
    if(front>rear)
    {
        front=0;
        rear=-1;
        return -1;
    }
    return q[front++];
}
void displayQ()
{
    int i;
    if(front>rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of queue\n");
    for(i=-front;i<=rear;i++)
    {
        printf("%d\n",q[i]);
    }
}
int main()
{
    int ch;
  for(;;)
   {
	    printf("\n1.insert_rear\n2.delete_front\n3.display\n4.exit\n");
	    printf("enter choice\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	        case 1:printf("enter the item to be inserted\n");
			    scanf("%d",&item);
			    insertrear();
			    break;
	        case 2:item=deletefront();
                if(item==-1)
                 printf("Queue is empty\n");
                 else
                printf("Item deleted=%d\n",item);
			     break;
	        case 3:displayQ();
			    break;
	        default:exit(0);
	    }
	}
    return 0;
}
