#include <stdio.h>
#include <stdlib.h>
#define max 1001
struct stack{
int arr[max];
int top1;
int top2;
};
struct stack* initialise_s1(struct stack *s1){
s1->top1=-1;
return s1;
}
struct stack* initialise_s2(struct stack *s2){
s2->top2=max;
return s2;
}
void push1(struct stack *s1,struct stack *s2,int x){
if(s1->top1<s2->top2-1){
    s1->arr[++s1->top1]=x;
}
else
    printf("Stack is full\n");
}
void push2(struct stack *s1,struct stack *s2,int x){
if(s1->top1<s2->top2-1){
    s2->arr[--s2->top2]=x;
}
else
    printf("Stack is full\n");
}
void pop1(struct stack *s1){
if(s1->top1==-1)
    printf("Stack 1 is empty\n");
else
    printf("%d popped from stack 1\n",s1->arr[s1->top1--]);
}
void pop2(struct stack *s2){
if(s2->top2==max)
    printf("Stack 2 is empty\n");
else
    printf("%d popped from stack 2\n",s2->arr[s2->top2++]);
}
void display1(struct stack* s1){
	int i=0;
	while(i<=s1->top1)
	 printf("%d ",s1->arr[i++]);
}
void display2(struct stack* s2){
	int i=max-1;
	while(i>=s2->top2)
     printf("%d ",s2->arr[i--]);
}
int main()
{
    struct stack s1,s2;
    initialise_s1(&s1);
    initialise_s2(&s2);
    int n;
    printf("1.Push in stack1\n2.Push in stack2\n3.Pop from stack1\n4.Pop from stack2\n5.Display stack1\n6.Display stack2\n7.To exit\n");
    while(1){
    	printf("Enter your choice of 7 above options: ");
    	scanf("%d",&n);
    	switch(n){
    		case 1:printf("Enter the element to insert: ");
    		 int a1;
    		 scanf("%d",&a1);
    		 push1(&s1,&s2,a1);
    		 break; 
			case 2:printf("Enter the element to insert: ");
    		 int a2;
    		 scanf("%d",&a2);
    		 push2(&s1,&s2,a2);
    		 break;
    		case 3:pop1(&s1);
    		 break;
    		case 4:pop2(&s2);
    		break;
    		case 5:display1(&s1);
    		 break;
    		 case 6:display2(&s2);
    		  break;
    		case 7:exit(1);
    		default:printf("Enter valid choice\n");
		}
    	
	}
    return 0;
}

