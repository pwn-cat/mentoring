#include <stdio.h>

char arr[100]={0,'A','B','C','D','E','F'};
int flag_1;
int flag_2;
int flag_3;
void inOrder(char x,int pos)
{
        if(!x){flag_1=1;return;}
        inOrder(arr[2*pos],2*pos);
        printf("%c ",x);
        inOrder(arr[2*pos+1],2*pos+1);
}

void preOrder(char x, int pos)
{
        if(!x){flag_2=1;return;}
        printf("%c ",x);
        preOrder(arr[2*pos],2*pos);
        preOrder(arr[2*pos+1],2*pos+1);
        
}

void postOrder(char x ,int pos)
{
        if(!x){flag_3=1;return;}
        postOrder(arr[2*pos],2*pos);
        postOrder(arr[2*pos+1],2*pos+1);
        if(flag_3)printf("%c ",x);
}

int main()
{
        //mid
        printf("inOrder : ");
        inOrder(arr[1],1);
        printf("\n");
        
        
        //pre
        printf("preOrder : ");
        preOrder(arr[1],1);
        printf("\n");
        
        //post
        printf("postOrder : ");
        postOrder(arr[1],1);
        printf("\n");
        return 0;
}
