#include<stdio.h>
#include<stdlib.h>
struct queue{
	int front,rear;
	unsigned size;
	int* arr;
};
struct queue* construct(unsigned size){
	struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
	queue->front=-1;
	queue->rear=-1;
	queue->size=size;
	queue->arr=(int*)malloc(sizeof(queue->size*sizeof(int)));
	return queue;
}
void enqueue(struct queue* Q,int x){
	if(Q->rear==Q->size-1&&Q->front==0||Q->front==Q->rear+1){
		printf("Queue is full\n");
	}
	else if(Q->rear==Q->size-1&&Q->front>0){
		Q->rear=0;
		Q->arr[Q->rear]=x;
	}
	else{
	    if(Q->front==-1){
	    	Q->front=0;
	    	Q->rear=0;
	    	Q->arr[Q->rear]=x;
		}
		else
		  Q->arr[++Q->rear]=x;
}
}
void dequeue(struct queue* Q){
	if(Q->front==-1){
	   printf("Queue Empty\n");
}
	else{
		printf("%d removed from queue\n",	Q->arr[Q->front]);
	     if(Q->front==Q->rear){
	     	Q->front=-1;
	     	Q->rear=-1;
		 }
		else if(Q->front==Q->size-1)
		   Q->front=-1;
		else
		   Q->front=Q->front+1;
	}
}
void display(struct queue* Q){
	int f,r;
	f=Q->front;
	r=Q->rear;
	if(f<r){
		while(f<=r)
		printf("%d ",Q->arr[f++]);
     	}
	else{
		while(f<Q->size)
		printf("%d ",Q->arr[f++]);
		int i=0;
		while(i<=r)
		printf("%d ",Q->arr[i++]);
	}
}
int main(){
	struct queue* Q=construct(4);
	
	int n;
	while(1){
	printf("Enter digit:\n1.To enqueue a no in queue\n2.To dequeue a number from queue\n3.To display queue\n4.To exit queue\n");
    scanf("%d",&n);
    switch(n){
    	case 1: printf("Enter a no to enqueue\n");
    	        int n1;
				scanf("%d",&n1);
				enqueue(Q,n1);
				break;
		case 2:dequeue(Q);
		       break;
		case 3:display(Q);
		       break;
		case 4:printf("Out of queue\n");
		       exit(1);
		       break;
		default:printf("Enter a valid choice");
	}
}
return 0;
}

