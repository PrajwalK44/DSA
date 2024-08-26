#include<stdio.h>
#include<malloc.h>

struct maxStack{
  int el;
  int max;  
};

// typedef struct maxStack maxStack;

int main(){
    int n=0, q=0, top=-1, max=0, el=0;
    scanf("%d",&n); //total queries
    struct maxStack* ptr;
    ptr=(struct maxStack*)malloc(n*sizeof(struct maxStack)); 
    while (n--){
        scanf("%d",&q); //each query
        if(q==1){
            //push
            scanf("%d",&el);
            ptr[++top].el=el;
            if (el>max) {
                max=el;
            }
            ptr[top].max=max;
        }
        else if(q==2){
            //pop;
            ptr[top].el=NULL;
            ptr[top].max=NULL;
            max=ptr[--top].max;
        }
        else if(q==3){
            //max
            printf("%d",ptr[top].max);
            printf("\n");
        }
    }
}