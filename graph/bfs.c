#include<stdio.h>
#define MAX 10

void BFS(int adj[][MAX], int visited[], int start){
    int q[MAX];
    int r=-1;
    int f=-1;
    q[++r]=start;
    visited[start]=1;
    while(r!=f){
        start=q[++f];
        printf("%d",start);
        for(int i=0; i<MAX; i++){
            if(adj[start][i]==1 && visited[i]==0){
                q[++r]=i;
                visited[i]=1;
            }
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
    BFS(adj, visited, 0);
}