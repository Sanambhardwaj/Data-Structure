#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;

void push(int n);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

int main()
{
        int choice,n;
        while(1)
        {
                printf("\n1.Push\n");
                printf("2.Pop\n");
                printf("3.Display the top element\n");
                printf("4.Display all stack elements\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                 case 1 :
                        printf("\nEnter the Number to be pushed : ");
                        scanf("%d",&n);
                        push(n);
                        break;
                 case 2:
                        n = pop();
                        printf("\nNumber To Be Poped Is : %d\n",n );
                        break;
                 case 3:
                        printf("\nThe Number At Top Is is : %d\n", peek() );
                        break;
                 case 4:
                        display();
                        break;
                 case 5:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }
        }

        return 0;

}

void push(int n)
{
        if( isFull() )
        {
                printf("\nStack Overflow\n");
                return;
        }
        top = top+1;
        stack_arr[top] = n;
}

int pop()
{
        int n;
        if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        n = stack_arr[top];
        top = top-1;
        return n;
}

int peek()
{
        if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        return stack_arr[top];
}

int isEmpty()
{
        if( top == -1 )
                return 1;
        else
                return 0;
}

int isFull()
{
        if( top == MAX-1 )
                return 1;
        else
                return 0;
}

void display()
{
        int i;
        if( isEmpty() )
        {
                printf("\nStack is empty\n");
                return;
        }
    printf("\nStack elements :\n\n");
        for(i=top;i>=0;i--)
                printf(" %d\n", stack_arr[i] );
        printf("\n");
}