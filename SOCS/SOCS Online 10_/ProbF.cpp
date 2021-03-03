#include <stdio.h>
#include <string.h>

struct data{
    long long int ID;
    char judul[12], pembuat[12];
    int punya;
};

int main(){
    int t;
    scanf("%d", &t);
    int n = t;
    while(t-- > 0){
        long long int l, b, i=0, j=0, k=0;

        scanf("%lld", &l);
        struct data li[l]; 
        for(int i=0;i<l;i++){
            scanf("%lld %s %s", &li[i].ID, li[i].judul, li[i].pembuat);
            li[i].punya=0;
        }
        scanf("%lld", &b);
        struct data bi[b]; 
        for(int i=0;i<b;i++){
            scanf("%lld %s %s", &bi[i].ID, bi[i].judul, bi[i].pembuat);
            bi[i].punya=1;
        }

        struct data shelf[l+b];

        while(i<l && j<b){
            if(li[i].ID < bi[j].ID)
                shelf[k++] = li[i++];
            else if(li[i].ID > bi[j].ID)
                shelf[k++] = bi[j++];
            else if(li[i].ID == bi[j].ID){
                int total=strcmp(li[i].judul, bi[j].judul);
                if(total > 0)
                    shelf[k++]=bi[j++];
                else
                    shelf[k++]=li[i++];
            }
        }

        while(i<l){
            shelf[k++]=li[i++];
		}
        while(j<b){
            shelf[k++]=bi[j++];
		}
        printf("Case #%d:\n", n-t);
        for(i=0;i<l+b;i++){
            if(shelf[i].punya==1)
                printf("%d\n", i+1);
        }
    }
    return 0;
}
