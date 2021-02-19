#include <stdio.h>


int graph[8][8]={0,1,0,0,0,1,1,0
                ,1,0,1,1,0,0,0,0,
                0,1,0,0,0,0,0,0,
                0,1,0,1,0,0,0,0,
                0,0,0,1,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,1,
                0,0,0,0,0,0,1,0};

char alpha[8]={'A','B','C','D','E','F','G','H'};
int visit[8];

void dfs(int x)
{
        visit[x]=1;
        printf("[%c] ",alpha[x]);
        for(int i=0;i<8;i++)
        {
                if(graph[x][i]==1&&!visit[i])
                        dfs(i);
        }


}

int main()
{
    printf("dfs result: ");
    dfs(0);
    printf("\n");
    return 0;
}







