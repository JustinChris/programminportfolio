#include<stdio.h>
void fibonacci(int n,char a[])
{
    if(n==0 || n==1)
    {
        printf("%c",a[n]);
    }
    else
    {
        fibonacci(n-1,a),fibonacci(n-2,a);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        char a[2];
        scanf("%d %c %c",&n,&a[0],&a[1]);
        
        printf("Case #%d: ",i+1);
        fibonacci(n,a);
        printf("\n");
    }
    return 0;
}
