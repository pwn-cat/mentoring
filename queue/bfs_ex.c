#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define True 1
#define False 0
#define Max_Size 1000

int is_empty();
int is_full();
void bfs(int y,int x);
void enqueue(int n);
int dequeue();


int queue[Max_Size],front,rear;
int N,M;
int arr[500][500];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int main()
{
        scanf("%d %d",&N,&M); //N=sero M=garo

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                    scanf("%d",&arr[i][j]);
        /*#####check arr##########
         *
        printf("result==:\n\n");
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                    printf("%d ",arr[i][j]);
            printf("\n");
        }
        */
        bfs(0,0);

        //printf("result==:\n\n");
        /*for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                    printf("%d ",arr[i][j]);
            printf("\n");
        }
        */
        printf("%d",arr[N-1][M-1]);
        return 0;
}

int is_empty(){return front==rear;}
int is_full(){return (rear+1)%Max_Size==front;}

void bfs(int y,int x)
{
        enqueue(y);
        enqueue(x);
        //printf("hihi\n\n");
        while(!is_empty())
        {
            int Qy=dequeue();
            int Qx=dequeue();
    
            for(int i=0;i<4;i++)
            {
                    int nx=Qx+dx[i];
                    int ny=Qy+dy[i];
                    if(arr[ny][nx]==1)
                    {
                        if(ny>=N || ny <0 || nx>=M||nx <0) continue;
                        arr[ny][nx]=arr[Qy][Qx]+1;
                        enqueue(ny);
                        enqueue(nx);
                    }
                            
            }
        }
}

void enqueue(int n)
{
        if(is_full())   err(EXIT_FAILURE,"queue is fulled");
        rear=(rear+1)%Max_Size;
        queue[rear]=n;
}

int dequeue()
{
        if(is_empty())  err(EXIT_FAILURE,"queue is empty");
        front =(front+1)%Max_Size;
        return queue[front];
}

        
