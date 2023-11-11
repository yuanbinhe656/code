
#include <stdio.h>
 
#define MAX_VERTEX_NUM 20
 
typedef struct{
    int adj;
}VRType;
 
typedef struct{
}InfoType;
 
typedef struct ArcCell{
    VRType vrtype;
    InfoType *info;
}ArcCell, DistanceMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
 
// D的类型是 ArcCell (*)[MAX_VERTEX_NUM][MAX_VERTEX_NUM] 
void ShortestPath_FLOYD(DistanceMatrix *D){
    for (int v = 0; v < 3; ++v)
    {
        for (int w = 0; w < 3; ++w){
            printf("%p\n", D[v][w]); // v一个步长的大小是 sizeof(ArcCell)*MAX_VERTEX_NUM*MAX_VERTEX_NUM
            printf("%p\n", &D[v][w][0]); //上面等价于这个语句
            printf("%p\n", &D[0][v][w]);
            printf("\n");
        }
    }
}
 
DistanceMatrix D;
int main() {
int a[3]={1,2,3};

printf("%d",*(a+2));
    return 0;
}
