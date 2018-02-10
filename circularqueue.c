#include<stdio.h>
#define max 50
int cq[max],front=-1,rear=-1;


void insert(int val)
{  if(rear==max-1&&front==0)
       printf("\n OVERFLOW");
   else 
      {
         if(front==-1&&rear==-1)
             front=0,rear=0;
         else if(front!=0&&rear==max-1)
                 rear=0;
         else 
           rear++; 
       cq[rear]=val;
       }
printf("\nf=%d r=%d\n",front,rear);} 

void delete()
{    if(front==-1&&rear==-1)
       {    printf("\nUNDERFLOW"); }
      
     if(front==rear)
           { front=rear=-1;printf("hey this is f=r");}  //queue having value only at last
       else 
          {   if( front==max-1)  //queue with some starting value gap and last value
               {front=0;printf("this is f=0");}
             else
              { front++;printf("this is f++");}
          }
printf("\nf=%d r=%d\n",front,rear);
}

void display()
{   if(front==-1&&rear==-1)
        printf("\n EMPTY QUEUE");
    else 
       { if(rear>=front)
             {for(int i=front;i<=rear;i++)
              printf("\n%d",cq[i]);}
         else 
             {
              for(int i=front;i<max;i++)
              printf("\n%d",cq[i]);
              for(int i=0;i<=rear;i++)
              printf("\n%d",cq[i]);  
             }
 
 }
} 


int main()
{  int op,val;
  do{ printf("\nMENU\n1:for insert\n2:for deletion\n3:for display\n4:exit");
       scanf("%d",&op);
  switch(op)
  { 
   case 1:{printf("\nenter the value");
           scanf("%d",&val);
           insert(val);}
      break;
   case 2:delete();
      break;
   case 3:display();
      break;

  }

  }while(op!=4);

return 0;}
