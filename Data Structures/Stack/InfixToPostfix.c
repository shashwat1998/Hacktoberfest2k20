#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#define max 1001
struct stack{
int arr[max];
int top;
};
typedef struct stack STACK;

void push(STACK *s,char x){
   if(s->top == max-1)
    printf("stack full\n");
   else
    s->arr[++s->top]=x;
}

int isempty(STACK *s){
return s->top==-1;
}
char pop(STACK *s){
  if(s->top == -1){
    printf("Stack is empty\n");
    return '$';
  }
  return s->arr[s->top--];
}
char peek(STACK *s){
return s->arr[s->top];
}


int isoperand(char c){
return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}


int precidence(char c){
switch(c){
case '+':
case '-':
    return 1;
case '*':
case '/':
    return 2;
case '^':
    return 3;
}
return -1;
}


int inf_to_post(char inf[]){
STACK stk;
stk.top=-1;
int i,k=0;
char c,post[100];
while(inf[i]!='\0'){
    if(isoperand(inf[i]))
        post[k++]=inf[i++];
    else if(inf[i]=='(')
      push(&stk,inf[i++]);
    else if(inf[i]==')'){
       while(stk.top!=-1&&stk.arr[stk.top]!='(')
                post[k++]=pop(&stk);
       if(stk.top==-1||stk.arr[stk.top]=='('){
        return -1;
       }
      else
        pop(&stk);
       i++;
     }
    else{
        while(isempty(&stk)&&precidence(peek(&stk))>=precidence(inf[i]))
             post[k++]=pop(&stk);
           push(&stk,inf[i++]);
        }
     }
while(!isempty(&stk))
post[k++]=pop(&stk);
post[k++]='\0';
puts(post);
return 1;
}



int main(){
char infix[]="f^a+b*(c-d)/e";
inf_to_post(infix);
return 0;
}

