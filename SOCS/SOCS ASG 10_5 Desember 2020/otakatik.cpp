#include<stdio.h>
#include<stdlib.h>
#include<string.h>// For functions like strcpy() and strcmp()

struct Employee
{
char Name[20];
char gender[10];
char division[15];
};
// Driver program
int main()
{
int n;// number of processes
scanf("%d",&n);
struct Employee *data=(struct Employee*)malloc((n+1) * sizeof(struct Employee));// dynamic memory allocation
int position[n+1];// position of array
for(int i=1;i<=n;i++)
{
position[i]=0;// initially all places are vacant
}
  
for(int i=1;i<=n;i++)
{
   int pNumber;// process Number
   scanf("%d",&pNumber);
   if(pNumber==1)
   {
   //Add Employee
   char CurName[20];
char Curgender[6];
char Curdivision[15];
scanf("%s",CurName);
scanf("%s",Curgender);
scanf("%s",Curdivision);
int flag=0;// flag variable for checking the existance of current user
  
  
// To check whether user with same name exist or not
for(int j=1;j<=n;j++){
if(position[j]>0&&strcmp(CurName,data[j].Name)==0){
flag=1;
break;// user with same name exist
}
}
if(flag)continue;// No need to add the user
  
  
//If user doesn't exist
   for(int j=1;j<=n;j++)
{
if(position[j]==0)// leftmost vacant position
{
position[j]=i;
strcpy(data[i].Name,CurName);
strcpy(data[i].gender,Curgender);
strcpy(data[i].division,Curdivision);
break;
}
}
   }
   else if(pNumber==2)
   {
   //Change position
   int x,y,temp;
   scanf("%d %d",&x,&y);
   temp=position[x];
   position[x]=position[y];
   position[y]=temp;
   }
   else if(pNumber==3)
   {
   //Resign
   int x;
   scanf("%d",&x);
   position[x]=0;// can be used again
   strcpy(data[i].Name,"");
strcpy(data[i].gender,"");
strcpy(data[i].division,"");
  
   }
   else if(pNumber==4)
   {
   //Retire
   int x;
   scanf("%d",&x);
   position[x]=-1;// can not be used again
   strcpy(data[i].Name,"");
strcpy(data[i].gender,"");
strcpy(data[i].division,"");
   }
   }
   //List of active employees
   for(int i=1;i<=n;i++)
   {
   if(position[i]>0)
   {
   printf("%s\n",data[position[i]].Name);
   }
  
   }
   return 0;
}
