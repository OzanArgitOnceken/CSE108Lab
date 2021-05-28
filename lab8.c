#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    int n=rand()%40+10;
    int *arr=(int* )malloc(sizeof(int));
    int i=1;
    while(i<n)
    {
        int flag=1;
        arr=(int *)realloc(arr,sizeof(int)*i);
        int j=0;
        int temp=rand()%100;
        while (j<=i)
        {
            if(temp>arr[j])
            {
                flag = 0;
				break;
            }
            j++;

        }
        if (flag)
        {
            for (int k = i; k > 0; k--)
            {
                arr[k+1]=arr[k];
            }
            arr[0]=temp;
        }
        else
        {
            int* t=(int* )malloc(sizeof(arr));
            for (int k = 0; k < i; k++)
            {
                t[k]=arr[k];
                arr[k]=-1;
            }
            arr[0]=temp;

            for (int k = 0; k < i; k++)
            {
                arr[k+1]=t[k];
            }
        }
        
        
        i++;
        
        
    }
    int c=0;
    while (c<i)
    {
        printf("%d\n",arr[c]);
        c++;
    }
    

}
