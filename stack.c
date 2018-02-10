#include<stdio.h>
#define max 30
int a[max],top=-1,val;

void push(int s[],int val)
{    
   if(top==max-1)
     printf("\nstack overflow");
    else 
    top++;
    s[top]=val;
}

int pop(int s[])
{ if(top==-1)
   printf("\nstack underflow");
  else
  { val=s[top];
    top--;
   return val;
  }
} 

int  peek(int s[])
{  if(top==-1)
   return -1;
   else
   return s[top];
}
void display(int s[])
{ if(top==-1)
   printf("\nSTACK UNDER FLOW");
  else 
    {for(int i=top;i>=0;i--)
     {printf("\n%d",s[i]);}}
}





int main()
{ int option;
  do{ printf("\nMENU\n1:for push\n2:for pop\n3:for peek\n4:to display\n5:Exit");
      scanf("%d",&option);
    switch(option)
   { case 1:{printf("\nenter the value to enter");
            scanf("%d",&val);
            push(a,val);}
          break;
     case 2:printf("\n the number deleted from top of stack is: %d",pop(a));
        break;
    case 3:printf("\nthe top value is :%d",peek(a));
        break;
    case 4:display(a);
       break;
   }
    
    }while(option!=5);
    
return 0;}

