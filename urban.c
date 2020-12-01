#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,n,num,min,max;
    printf("Enter no of cities :");
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Dist between %d and %d : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter k value :");
    scanf("%d",&k);
    int f[k];
    int c[n];
    int s[n];
    for(i=0;i<n;i++)
        s[i]=0;
    for(i=0;i<k;i++)
        f[i]=0;
    for(i=0;i<n;i++)
        c[i]=0;
    printf("Enter start city :");
    scanf("%d",&num);
    f[k-1]=num;
    s[num]=1;
    k=k-1;
    printf("Cities in which the infrastructure can be built are: \n");
    printf("City %d\n",num);
    while(k!=0)
    {

        for(i=0;i<n;i++)
        {
            min=9999;
            for(j=0;j<n;j++)
            {
                if(s[i]==1)
                {
                    if(a[i][j]<min)
                        min=a[i][j];
                }
            }
            c[i]=min;
        }
        max=0;
        for(i=0;i<n;i++)
        {
            if(c[i]>c[max])
                max=i;
        }
        s[max]=1;
        f[k]=max;
        printf("City %d\n",max);
        k=k-1;
    }
    for(i=0;i<k;i++)
        printf("\n cities %d",f[i]);
}
