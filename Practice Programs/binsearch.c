#include <stdio.h>
void binary_search(int [], int, int, int);
void bubble_sort(int [], int); 
int main()
{
   int key, size, i;
   int list[25];
   printf("ENTER LIMIT: ");
   scanf("%d", &size);
   printf("ENTER ELEMENTS:\n");
   for(i = 0; i < size; i++)
   {
      scanf("%d",&list[i]);
   }
   bubble_sort(list, size);
   printf("\n");
   printf("ENTER ELEMENT TO SEARCH:\n");
   scanf("%d", &key);
   binary_search(list, 0, size, key);
   return 0;
}
void bubble_sort(int list[], int size)
{
   int temp, i, j;
   for(i = 0; i < size; i++)
   {
      for (j = i; j < size; j++)
      {
         if (list[i] > list[j])
         {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
         }
      }
   }
}
void binary_search(int list[], int lo, int hi, int key)
{
   int mid;
 
   if(lo > hi)
   {
      printf("ELEMENT NOT FOUND\n");
      return;
   }
   mid = (lo + hi) / 2;
   if(list[mid] == key)
   printf("ELEMENT FOUND\n");
   else if (list[mid] > key)
   binary_search(list, lo, mid - 1, key);
   else if (list[mid] < key)
   binary_search(list, mid + 1, hi, key);
}
