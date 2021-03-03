#include <stdio.h>



struct student{??
char name[25];
double gpa;
int age;
}??;



void swap(long int &a,long int &b){??
long int temp=a;
a=b;
b=a;
}??



void quicksort(int first,int last,long int num[1000],student stud[1000]){??
long int i,j,p;
if(first<last){??
i=first;
j=last;
p=i;
while(i<j){??
while((num[i]<=num[p])&&(i<last)){??
i++;
}??
while(num[j]>num[p]){??
j--;
}??
if(i<j){??
swap(num[i],num[j]);
student temp=stud[i];
stud[i]=stud[j];
stud[j]=temp;
}??
}??
swap(num[j],num[p]);
student temp=stud[p];
stud[p]=stud[j];
stud[j]=temp;
quicksort(first,j-1,num,stud);
quicksort(j+1,last,num,stud);
}??
}??



int main(){??
int jml;
long int id[1000]={??}??;
student stud[1000];
scanf("%d",&jml);
for(int i=0;i<jml;i++){??
scanf("%ld;%[^;];%d;%lf",&id[i],stud[i].name,&stud[i].age,&stud[i].gpa);
}??
quicksort(0, jml-1, id, stud);
// for(int i=0;i<jml;i++){??
// printf("%ld\t%s\t%d\t%lf\n",id[i],stud[i].name,stud[i].age,stud[i].gpa);
// }??
int a,b;
scanf("%d %d",&a,&b);
for(;a<=b;a++){??
printf("Name: %s\n",stud[a-1].name);
printf("ID: %ld\n",id[a-1]);
printf("Age: %d\n",stud[a-1].age);
printf("GPA: %.2lf\n",stud[a-1].gpa);
}??


return 0;
}??
