#include<stdio.h>
#include<stdlib.h>
#define qsize 5
int item,f=0,r=-1,q[qsize],count=0,ch;
void insertrear()
{
    if(count==qsize)
    {
        printf("Queue overflow\n");
        return;
    }
    r=(r+1)%qsize;
    q[r]=item;
    count++;
}
int deletefront()
{
    if(count==0) return -1;
    item=q[f];
    f=(f+1)%qsize;
    count=count-1;
    return item;
}
void displayQ()
{
    int i,front;
    if(count==0)
    {
        printf("Queue is empty\n");
        return;
    }
    front=f;
    printf("Contents of queue\n");
    for(i=1;i<=count;i++)
    {
        printf("%d\n",q[front]);
        front=(front+1)%qsize;
    }
}
int main()
{
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
