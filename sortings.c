#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble(int h[1000],int x);
void insertion(int arr[1000],int x);
void selection(int arr[1000],int x);
void quick(int arr[1000],int lb,int ub);
int partition(int arr[1000],int lb,int ub);
void merges(int arr[1000],int lb,int ub);
void merge(int arr[1000],int lb,int mid,int ub);
int main()
{
    int n,p,q,i,num,x,a,h[1000];
    FILE *s,*l;
    printf("enter the range in which N random numbers are to be generated in order [lower,upper]\n");
    scanf("%d%d",&p,&q);
    printf("number of random numbers to be generated\n");
    scanf("%d",&n);
    s=fopen("input.txt","w");
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
       num=(rand()%(q-p+1))+p;//(UPPER-LOWER+1)+LOWER;
       printf("%d\t",num);
       //putw(num,s);
       fprintf(s,"%d\n",num);
    }
    fclose(s);
    s=fopen("input.txt","r");
    //c=fopen("output.txt","w");
    printf("\nenter the number of numbers to be sorted\n");
    scanf("%d",&x);
    l=fopen("log.txt","w");
    fprintf(l,"%d\n",x);
    fclose(l);
    for(i=0;i<x;i++)
    {
      fscanf(s,"%d",&a);
       h[i]=a;
      //fprintf(c,"%d\n",a);
      printf("%d\t",h[i]);
    }
    fclose(s);
    l=fopen("log.txt","a");
    clock_t start_t,end_t;
    double total_t;

    start_t=clock();
    bubble(h,x);
    end_t=clock();
    fprintf(l,"\ntime taken by bubble sort=%lf",total_t);

    start_t=clock();
    selection(h,x);
    end_t=clock();
    fprintf(l,"\ntime taken by selection sort=%lf",total_t);

    start_t=clock();
    insertion(h,x);
    end_t=clock();
    fprintf(l,"\ntime taken by insertion sort=%lf",total_t);

     //clock_t start_t,end_t;
    //double total_t;
    FILE *c;
   c=fopen("output.txt","a");
   fprintf(c,"\nquick sort\n");
   //l=fopen("log.txt","a");
   fprintf(l,"\n");
 //  fprintf(l,"quick sort\n");

    start_t=clock();
     printf("\n%f",start_t);

    quick(h,0,x-1);

    end_t=clock();
    printf("\n%f",end_t);
    total_t=(double)((end_t-start_t))/CLOCKS_PER_SEC;
    printf("\ntime taken=%lf\n",total_t);
    fprintf(l,"\ntime taken by quick sort=%lf",total_t);
     /*printf("the final array is\n"); for(i=0;i<x;i++) printf("\n %d\t",arr[i]);*/
   fprintf(c,"\n");
    for(i=0;i<x;i++)
    {
        printf("%d ",h[i]);
        fprintf(c,"%d\t",h[i]);
    }
    fclose(c);
    //fclose(l);
   // FILE *c;
   c=fopen("output.txt","a");
   fprintf(c,"\nmerge sort\n");
  // l=fopen("log.txt","a+");
   //fprintf(l,"\n");
   //fprintf(l,"merge sort\n");
//    clock_t start_t,end_t;
    start_t=clock();
    printf("\n%f",start_t);

    merges(h,0,x-1);

    end_t=clock();
    printf("\n%f",end_t);
     total_t=((double)(end_t-start_t))/CLOCKS_PER_SEC;
    printf("\ntime taken=%lf\n",total_t);
     fprintf(l,"\ntime taken by merge sort=%lf",total_t);
    /*printf("the final array is\n"); for(i=0;i<x;i++) printf("\n %d\t",arr[i]);*/
     fprintf(c,"\n");
    for(i=0;i<x;i++)
    {
        printf("%d ",h[i]);
        fprintf(c,"%d\t",h[i]);
    }
    fclose(c);
     fclose(l);
    return 0;
}
void bubble(int h[1000],int x)
{
    FILE *c,*l;
   c=fopen("output.txt","w");
   fprintf(c,"bubble sort\n");
   l=fopen("log.txt","a");
   fprintf(l,"\n");
   //fprintf(l,"bubble sort\n");
    int i,j,temp;
   // time_t start,end; // start=time(NULL); //time(&start);
   printf("bubble sort\n");
   //clock_t start_t,end_t;start_t=clock();
   // double s= (double)(start_t);
   //  printf("\n%f",s);
    //struct timespec start,end; //clock_gettime(CLOCK_MONOTONIC,&start);
    for(i=0;i<x-1;i++)
    {
       for(j=0;j<x-i-1;j++)
       {
           if(h[j]>h[j+1])
           {
               temp=h[j];
               h[j]=h[j+1];
               h[j+1]=temp;
           }
       }
    }
   /* for(int cs=0;cs<10000000;cs++){}*/
    //end=time(NULL);//double time_taken=(double)(end-start);

   // clock_gettime(CLOCK_MONOTONIC,&end);//double time_taken=(end.tv_sec-start.tv_sec)+(end.tv_nsec-start.tv_nsec)/1000000000.0;

  // //end_t=clock();double e= (double)(end_t);printf("\n%f",e); double total_t=((double)(end_t-start_t))/CLOCKS_PER_SEC;
   //double time_taken=((double)(e-s))/CLOCKS_PER_SEC;// time(&end);//double time_taken=difftime(end,start);
    //printf("\ntime taken=%lf\n",total_t); // fprintf(l,"\ntime taken by bubble sort=%lf",total_t);
    for(i=0;i<x;i++)
    {
        printf("%d ",h[i]);
        fprintf(c,"%d\t",h[i]);
    }
    fclose(c);
     fclose(l);
}
void selection(int arr[1000],int x)
{
    FILE *c,*l;
   c=fopen("output.txt","a");
   fprintf(c,"\nselection sort\n");
   l=fopen("log.txt","a");
   fprintf(l,"\n");
  // fprintf(l,"\nselection sort\n");
   int i,j,min,temp;
    //clock_t start_t,end_t;start_t=clock();printf("\n%f",start_t);
   for(i=0;i<x-1;i++)
   {
       min=i;
       for(j=i+1;j<x;j++)
       {
           if(arr[j]<arr[min])
           {
               min=j;
           }
       }
       if(min!=i)
       {
           temp=arr[i];
           arr[i]=arr[min];
           arr[min]=temp;
       }
   }
   // end_t=clock();printf("\n%f",end_t);double total_t=((double)(end_t-start_t))/CLOCKS_PER_SEC;printf("\ntime taken=%lf\n",total_t);fprintf(l,"\ntime taken by selection sort=%lf",total_t);
   /*printf("the final array is\n"); for(i=0;i<x;i++) printf("\n %d\t",arr[i]);*/
   fprintf(c,"\n");
    for(i=0;i<x;i++)
    {
        printf("%d ",arr[i]);
        fprintf(c,"%d\t",arr[i]);
    }
    fclose(c);
     fclose(l);
}

void insertion(int arr[1000],int x)
{
    FILE *c,*l;
   c=fopen("output.txt","a");
  fprintf(c,"\ninsertion sort\n");
  l=fopen("log.txt","a");
   fprintf(l,"\n");
//   fprintf(l,"insertion sort\n");
   int i,j,temp;
    clock_t start_t,end_t;
    start_t=clock();
     printf("\n%f",start_t);

    for(i=1;i<x;i++)
    {
       temp=arr[i];
       j=i-1;
       while(j>=0 && arr[j]>temp)
       {
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=temp;
    }

    //end_t=clock();printf("\n%f",end_t);double total_t=((double)(end_t-start_t))/CLOCKS_PER_SEC;printf("\ntime taken=%lf\n",total_t);fprintf(l,"\ntime taken by insertion sort=%lf",total_t);
   /*printf("the final array is\n"); for(i=0;i<x;i++) printf("\n %d\t",arr[i]);*/
   fprintf(c,"\n");
    for(i=0;i<x;i++)
    {
        printf("%d ",arr[i]);
        fprintf(c,"%d\t",arr[i]);
    }
    fclose(c);
     fclose(l);
}

void quick(int arr[1000],int lb,int ub)
{
    if(lb<ub)
     {
         int a=partition(arr,lb,ub);
         quick(arr,lb,a-1);
         quick(arr,a+1,ub);
     }
}

int partition(int arr[1000],int lb,int ub)
{
    int start,end,p,temp;
    p=arr[lb];
    start=lb;
    end=ub;
    while(start<end)
    {
        while(arr[start]<=p)
        {
            start++;
        }
         while(arr[end]>p)
        {
            end--;
        }
        if(start<end)
        {
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
            temp=arr[lb];
            arr[lb]=arr[end];
            arr[end]=temp;
    return end;
}

void merges(int arr[1000],int lb,int ub)
{
    // printf("%d %d\n",lb,ub);
   if(lb<ub)
   {
       int m;
       m=(lb+ub)/2;
      // printf("%d %d %d\n",lb,m,ub);
       merges(arr,lb,m);
       merges(arr,m+1,ub);
       merge(arr,lb,m,ub);
   }
}

void merge(int arr[1000],int lb,int mid,int ub)
{
    int i,j,k,b[1000];
    i=lb;
    j=mid+1;
    k=lb;
    while((i<=mid) && (j<=ub))
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }
        k++;
    }
   while(i<=mid)
     b[k++]=arr[i++];
   while(j<=ub)
     b[k++]=arr[j++];
    for(k=lb;k<=ub;k++)
    {
        arr[k]=b[k];
    }
    printf("\n");
    for(k=lb;k<ub;k++)
    {
        printf("%d ",arr[k]);
    }
}
