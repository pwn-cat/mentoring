#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
        char file_name[31];
        int file_size;
};
void find_node(struct node *arr,int pos,char *name);
int flag;
int pos=1;
int main()
{
    char search_name[31];
    struct node arr[100]={//need to find how to define struct array
            {0,},
            {"Document",0},
            {"Music",50},
            {"Picture",100},
            {"K-Pop",200},
            {"Photo",200},
            {"Movie",500},
            {0,0},
            {0,0},
            {"2020",1000},
            {"2021",50}
    };

    scanf("%s",search_name);
    find_node(arr,pos,search_name);
    return 0;
}
void find_node(struct node *arr,int pos,char *name)
{
       if(!strlen(arr[pos].file_name))    return;

       if(!strcmp(arr[pos].file_name,name)){
               printf("%d\n",arr[pos].file_size);
               exit(1);
       }

       find_node(arr,pos*2,name);
       find_node(arr,pos*2+1,name);

}
