#include<stdio.h>
#include<stdlib.h>
int size = 5;
int top = -1;
int *arr;

void config()
{
arr = (int *)malloc(size * sizeof(int));

if (arr == NULL)
{
printf("Memory Allocation Failed\n");
exit(1);
}
}
void push(int value)
{
int *np;
int i;
if (top>=size -1)
{
np = (int *)malloc(size*2*sizeof(int));
if(np == NULL)
{
printf("Stack Overflow - Heap space is over!\n");
return;
}
for (i=0; i<size; i++)
{
np[i] = arr[i];
}
free(arr);
arr = np;
size = size*2;
}
top++;
arr[top] = value;
printf("%d is updated at %d\n",value,top);
}
int main()
{
config();
while (top<19)
{
push(1);
}
free(arr);
return 0;
}