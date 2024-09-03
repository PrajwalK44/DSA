#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main(){
    int t,top=-1,i,flag,a0;
    char stack[100],temp;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        char* s = (char *)malloc(10240 * sizeof(char));
        scanf("%s",s);
        flag=1;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i] == '('||s[i]=='{'||s[i]=='[')
                stack[++top]=s[i];                 
            if(s[i] == ')'||s[i]=='}'||s[i]==']')
            {
                  if(top == -1)
      {
       flag=0;      
       break;
      }
                   
                  else
                      {
                        temp=stack[top--];
                                             
                      if((s[i] == ')' &&temp != '(') ||(s[i] == '}' && temp!='{')||(s[i] == ']' && temp!='['))
                          flag=0;
                    }
            }
        }
        if(top>=0)
        {
         while(top >= 0)
             temp=stack[top--];
         flag=0;
        }
         
        if(flag == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
