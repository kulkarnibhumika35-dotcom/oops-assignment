#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class Stack
{
private:
int arr[10];
int minArr[10];
int top;

public:
Stack()
{
top = 0;
}
void push(int x)
{
if(top == 10)
{
cout<<"Stack Overflow";
return ;
}
arr[top] = x;
if(top == 0)
minArr[top] = x;
else
{
if(x < minArr[top-1])
minArr[top] =x;
else

minArr[top] = minArr[top-1];
}
top++;
}
int pop()
{
if(top == 0)
{
cout<<"Stack Underflow";
return -1;
}
top--;
return arr[top];
}
int peek()
{
if (top == 0)
{
cout<<"Stack is empty";
return -1;
}
return arr[top-1];
}
int min()
{
if(top == 0)
{
cout<<"Stack is empty";
return -1;
}
return minArr[top-1];
}
};
void main()
{
Stack st;
int n,x,i;
clrscr();
cout<<"Enter number of elements: ";
cin>>n;
cout<<"Enter elements: "<<endl;
for(i=0;i<n;i++)
{
cin>>x;
st.push(x);
}
cout<<"\nMinimum element: "<<st.min();
cout<<"\nTop element: "<<st.peek();
cout<<"\nPopped element: "<<st.pop();
cout<<"\nTop element after pop: "<<st.peek();
cout<<"\nMinimum element after pop: "<<st.min();
getch();
}