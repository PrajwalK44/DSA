#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>



int top=-1;


void push(char);
char pop();

int main(){
    int i;
    
    char exp[100];
    char temp;
    int n=0;
    scanf("%d",&n);
    while(n--){
        int flag=1;
        top=-1;
        char *exp=(char*)malloc(10240*sizeof(char));
        scanf("%s",exp);
        for(i=0; i<strlen(exp); i++){
            if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
                push(exp[i]);
            }
            if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
                if(top==-1){
                    flag=0;
                }
                else{
                    temp=pop();

                    if((exp[i]==')') && (temp=='{'|| temp=='[')){
                        flag=0;
                    }
                    if((exp[i]=='}') && (temp=='('|| temp=='[')){
                        flag=0;
                    }
                    if((exp[i]==']') && (temp=='('|| temp=='{')){
                        flag=0;
                    }
                }
            }
        }
        if(top>=0){
            flag=0;
        }
        if(flag==1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }  
    }
    
    return 0;
}

void push(char r){
    
    
        top++;
        st[top]=r;
    
}

char pop(){
    if(top==-1){
        printf("\nUnderflow");
        exit(1);
    }
    else{
        char val;
        val=st[top];
        top--;
        return val;
    }
}