
//TO IMPLEMENT QUEUE USING STACK
#include<stdio.h>
#include<stdlib.h>
struct qstack{
int top;
unsigned size;
int* arr;
};

typedef struct qstack QSTACK;

QSTACK* initialise(unsigned size){
QSTACK* s=(QSTACK*)malloc(sizeof(QSTACK));
s->top=-1;
s->size=size;
s->arr=(int*)malloc(s->size*sizeof(int));
}
//ENQUEUE
void enqueue(QSTACK* s,int x){
if(s->top==s->size-1)
printf("Queue is full\n");
else{
 s->arr[++s->top]=x;
}
}
//DEQUEUE
void dequeue(QSTACK* s){
if(s->top==-1)
printf("Queue is empty\n");
else{
int i=0,j;
printf("%d removed from queue\n",s->arr[i]);
while(i!=s->top){
s->arr[i]=s->arr[i+1];
i++;
}
s->top=i-1;
}
}
//DISPLAY
void display(QSTACK* s){
int i=0;
while(i<=s->top)
printf("%d ",s->arr[i++]);
}
//MAIN
int main(){
QSTACK* s=initialise(10000);
int n;
while(1){
printf("Choose your option:\n");
printf("1.To insert\n2.To remove\n3.To display\n4.To exit\n");
scanf("%d",&n);
switch(n){
case 1:printf("Enter element to insert\n");
       int a;
       scanf("%d",&a);
       enqueue(s,a);
break;
case 2:dequeue(s);
break;
case 3:display(s);
break;
case 4:printf("Out of queue\n");
exit(1);
default:printf("Enter valid option\n");
}
}
return 0;
}
