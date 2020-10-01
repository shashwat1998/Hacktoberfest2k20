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
	if(Q->rear==Q->size-1)
	   printf("Queue Over flow\n");
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
	if(Q->front==-1||Q->rear<Q->front)
	   printf("Queue Empty\n");
	else{
	 printf("%d removed from queue\n",Q->arr[Q->front++]);
		 }
	}
void display(struct queue* Q){
	int f,r;
	f=Q->front;
	r=Q->rear;
	while(f<=r){
		printf("%d ",Q->arr[f++]);
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















