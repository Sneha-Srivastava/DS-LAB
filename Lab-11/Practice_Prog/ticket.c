#include<stdio.h>
#include<stdlib.h>
#define qsize 5
int item,f=0,r=-1,q[qsize],count=0,ch;
void insertrear()
{
    if(count==qsize)
    {
        printf("Reservation empty..Bookings open!\n");
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
        printf("Reservation empty..Bookings open!\n");
        return;
    }
    front=f;
    printf("--Reserved Number List--\n");
    for(i=1;i<=count;i++)
    {
        printf("%d\n",q[front]);
        front=(front+1)%qsize;
    }
}
int main()
{
  for(;;)
   {     printf("\n--ONLINE TICKET RESERVATION SYSTEM--\n");
	    printf("\n1.Book a ticket\n2.Request for cancellation of the booked ticket\n3.Display Reservation List\n4.Exit\n");
	    printf("\nEnter your choice\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	        case 1:printf("Enter your registered 4-digit number for booking a ticket\n");
			    scanf("%d",&item);
			    insertrear();
			    break;
	        case 2:item=deletefront();
                if(item==-1)
                 printf("Reservation empty..Bookings open!\n");
                 else
                printf("Cancelled Ticket: %d\n",item);
			     break;
	        case 3:displayQ();
			    break;
	        default:exit(0);
	    }
	}
    return 0;
}
