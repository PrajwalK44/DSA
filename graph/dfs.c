#include<stdio.h>
#define MAX 10

void DFS(int adj[][MAX], int visited[], int start){
    int st[MAX];
    int top=-1;
    st[top++]=start;
    printf("%d",start);
    visited[start]=1;
    while(top!=-1){
        start=st[top];
        for(int i=0; i<MAX; i++){
            if(adj[start][i]==1 && visited[start]=0){
                st[top++]=i;
                printf("%d",start);
                visited[i]=1;
                break;
            }
        }
        if(i==MAX){
            top--;
        }

    }
}


int main(){
    int adj[MAX][MAX];
    int visited[MAX]={0};
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            scanf("%d",&adj[i][j]);
        }
    }
    DFS(adj, visited, 0);
}