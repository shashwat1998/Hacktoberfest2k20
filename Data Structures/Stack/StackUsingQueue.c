
//TO IMPLEMENT STACK USING QUEUE
#include<stdio.h>
#include<stdlib.h>
struct squeue{
int front,rear;
unsigned size;
int* arr;
};

typedef struct squeue SQUEUE;
SQUEUE* initialise(unsigned size){
SQUEUE* q=(SQUEUE*)malloc(sizeof(SQUEUE));
q->front=-1;
q->rear=-1;
q->size=size;
q->arr=(int*)malloc(q->size*sizeof(int));
}

//POP
void pop(SQUEUE* q){
if(q->front==-1)
 printf("Stack is empty\n");
else{
 if(q->rear==q->front){
   printf("%d popped from stack\n",q->arr[q->rear]);
   q->rear=-1;
    q->front=-1;
}
else{
int i,j,k=1;
j=q->rear;
i=q->front;
while(i!=j){
q->arr[j+k]=q->arr[i];
k++;
i++;
if(j+k==q->size-1){
printf("Can't perform operation stack is full\n");
return;
}
}
printf("%d removed from stack\n",q->arr[q->rear]);
q->rear=j+k-1;
q->front=i+1;
}
}
}
//PUSH
void push(SQUEUE* q,int x){
if(q->rear==q->size-1)
printf("Stack overflow\n");
else{
    if(q->front==-1){
      q->front=0;
       q->rear=0;
       q->arr[q->rear]=x;
}
else{
    q->arr[++q->rear]=x;
}
}
}
//DISPLAY
void display(SQUEUE* q){
int i;
i=q->front;
while(i<=q->rear){
printf("%d ",q->arr[i++]);
}
}
//MAIN
int main(){
SQUEUE* q=initialise(10000);
int n;
while(1){
printf("Choose your option:\n");
printf("1.To insert\n2.To remove\n3.To display\n4.To exit\n");
scanf("%d",&n);
switch(n){
case 1:printf("Enter element to insert\n");
       int a;
       scanf("%d",&a);
       push(q,a);
break;
case 2:pop(q);
break;
case 3:display(q);
break;
case 4:printf("Out of stack\n");
exit(1);
default:printf("Enter valid option\n");
}
}
return 0;
}


















