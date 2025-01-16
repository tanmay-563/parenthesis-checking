#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
};
int empty(struct stack *ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int full(struct stack*ptr){
    if(ptr ->top == ptr-> size-1 ){
        return 1;
    }
    else {
        return 0;
    }
}
int stacktop(struct stack*s){
    return( s-> arr[s->top]);
}
int stackbottom(struct stack*s){
    return(s->arr[0]);
}
void push(struct stack*ptr , char value){
    if(full(ptr)){
        printf("stack overflow \n");
    }
    else{
        ptr -> top ++;
        ptr -> arr[ptr->top]= value;
    }
}
char pop(struct stack*ptr){
    if(empty(ptr)){
        printf("stack underflow");
        return '\0';
    }
    else{
        char value = ptr->arr[ptr->top];
        ptr-> top--;
        return value;
    }
}
int peek(struct stack*s, char i){
    if(s->top - i+1 <0){
        printf("invalid position \n");
        return -1;
    }
    else{
        return (s-> arr[s->top - i +1]);
    }
}
int match (char a , char b){
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
    return 0;
}
int parenthesis(char*exp){
    struct stack*sp;
    sp->size= 10;
    sp->top= -1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    char popped;
    for (int i = 0; exp[i]!= '\0'; i++)
    {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp,exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']'){
            if(empty(sp)){
                free(sp->arr);
                free(sp);
                return 0;
            }
            else{
                popped = pop(sp);
                if(!match(popped, exp[i])){
                    return 0;
                }
            }
        }
    }
    if(empty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main(){
    char*exp = "8*(9-6)}][";
    if(parenthesis(exp)){
        printf("it is matching");
    }
    else{
        printf("it is not matching");
    }
    return 0;
}
