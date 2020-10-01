#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max 1001
struct stack{
int arr[max];
int top;
};
typedef struct stack STACK;
//PUSH
void push(STACK *s,char x){
   if(s->top==max-1)
    printf("stack full");
   else
    s->arr[++s->top]=x;
}
//IsEMPTY
int isempty(STACK *s){
return s->top==-1;
}
//POP
char pop(STACK *s){
  if(isempty(s)){
    printf("Stack is empty");
    return '$';
  }
  return s->arr[s->top--];
}
//PEEK
char peek(STACK *s){
return s->arr[s->top];
}

int isoperand(char c){
return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}

int isoperator(char c){
return c == '+'||'-'||'*'||'^'||'/';
}

void post_to_infix(char post[],char infix[]){
    STACK s;
    s.top=-1;
  int i,k=1;
  char op[k],c[2];
  for(i=0;i<strlen(post);i++){
    if(isoperand(post[i]))
        push(&s,post[i]);
    else if(isoperator(post[i])){
        while(k>-1){
            op[k--]=pop(&s);
        }
        c[2]=op[0];
        strcat(post[i],c);
        push(&s,strcat(op[1],c));
    }
  }
  peek(&s);
}
int main()
{
    char post[]="abcd^*+";
    char infix[100];
    post_to_infix(post,infix);
    return 0;
}
