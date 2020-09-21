#include<stdio.h>
struct Student
{
char name[20];
char ID[20];
int age;
 struct marks
 { int m1;
 }m;
 }s;
int main()

 {
     int i,n;
     printf("ENTER THE NO. OF STUDENTS:\n ");
     scanf("%d",&n);
      for(i=0;i<n;i++)
     {
        printf("ENTER STUDENT'S NAME\n");
        scanf("%s",s.name);
        printf("ENTER ID:\n");
        scanf("%s",s.ID);
        printf("ENTER THE AGE:\n");
        scanf("%d",&s.age);
        printf("ENTER THE MARKS:\n");
        scanf("%d",&s.m.m1);
        printf("NAME:%s",s.name);
        printf("\nID:%s",s.ID);
        printf("\nAGE:%d",s.age);
        printf("\nMARKS:%d\n",s.m.m1);
        if(s.age>20 && s.m.m1>=65)
        printf("\nEligible for admission\n");
        else
        printf("\nNot Eligible for admission\n");
     }
return 0;
 }
