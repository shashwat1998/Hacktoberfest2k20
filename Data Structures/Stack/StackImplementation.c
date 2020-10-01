#include <stdio.h>
#include <stdlib.h>
#define max 1001
struct Stack{
int arr[max];
int top;
};

typedef struct Stack STACK;

void push(STACK *s,int x){
if(s->top==max-1){
    printf("Stack overflow\n");
}
else{
        s->top=s->top+1;
    s->arr[s->top]=x;
}
}

void pop(STACK *s){
if(s->top==-1){
    printf("Stack empty\n");
}
else
    printf("%d popped from stack\n",s->arr[s->top--]);
}

void display(STACK *s){
int i;
for(i=s->top;i>=0;i--){
    printf("%d\n",s->arr[i]);
}
}
int main(){
    STACK s;
    s.top=-1;
    push(&s,1);
    push(&s,2);
    display(&s);
    pop(&s);
    display(&s);
return 0;
}
