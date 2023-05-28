#include<stdio.h>
#include<stdlib.h>
#define row 3
#define col 3
void read(int mat[row][col]);
void print(int mat[row][col]);
void mult(int matrix1[row][col],int matrix2[row][col]);

void main()
{
    int matrix1[row][col],matrix2[row][col];
    printf("enter the elements for 1st matrix\n");
    read(matrix1);
    print(matrix1);
     printf("enter the elements for 2nd matrix\n");
    read(matrix2);
    print(matrix2);
    mult(matrix1,matrix2);
  printf("\n************\n****nullbite****\n*************\n");
}
void read(int mat[row][col])
{
   int x,y;
   for(x=0;x<row;x++)
   {
       for(y=0;y<col;y++)
       {
           scanf("%d",(*(mat+x)+y));
       }
   }
}
 void print(int mat[row][col])
 {
     int x,y;
   for(x=0;x<row;x++)
   {
       for(y=0;y<col;y++)
       {
           printf("%d ",*(*(mat+x)+y));
       }
       printf("\n");
   }
}
void mult(int matrix1[row][col],int matrix2[row][col])
{
   int x,y,k,sum=0,res[row][col];
   for(x=0;x<row;x++)
   {
       for(y=0;y<col;y++)
       {
          for(k=0;k<col;k++)
           {
             //printf("numbers= %d\t %d\n",(*(*(matrix1+x)+k)),(*(*(matrix2+k)+y)));
             sum=sum+((*(*(matrix1+x)+k)) * (*(*(matrix2+k)+y)));

           }
           //printf("%d\t",sum);
           *(*(res+x)+y)=sum;
           sum=0;
       }
   }
   printf("\n");
   print(res);
}
//1 2 3 4 5 6 7 8 9
