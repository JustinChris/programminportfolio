#include<stdio.h>
void fibo(int n,char s[])
{
    if(n==0 || n==1)
    {
        printf("%c",s[n]);
    }
    else
    {
        fibo(n-1,s),fibo(n-2,s);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=1;i<=t;i++)
    {
        int n;
        char s[2];
        scanf("%d %c %c",&n,&s[0],&s[1]);
        printf("Case #%d: ",i);
        fibo(n,s);
        printf("\n");
    }
    return 0;
}
