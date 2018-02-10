#include<stdio.h>
#include<malloc.h>

struct node {
int data;
struct node *next;
};

struct node *start=NULL;

void create()
{   struct node *ptr,*newnode;
    int val;
    printf("enter the value ");
    scanf("%d",&val);
    
 while(val!=-1)
 {
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->next=NULL;
  newnode->data=val;
  ptr=start;
  if(ptr==NULL)
   {  start=newnode;}
  else 
   { 
    while(ptr->next!=NULL)
           ptr=ptr->next;
           ptr->next=newnode;}
  printf("enter the value");
  scanf("%d",&val);
 }
}

void display()
{  struct node *ptr;
   ptr=start;
   if(ptr==NULL)
    printf("\n linked list is empty");
   else 
  {  printf("\nthe elements are: ");
    while(ptr!=NULL)
      { printf("%d ",ptr->data);
        ptr=ptr->next;}
  }
}

void insert_at_beg()
{struct node *newnode;
  int val;
  printf("\nenter the value to placed in beginning");
  scanf("%d",&val);
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->next=start;
  start=newnode;
}


void insert_at_end()
{ struct node *ptr,*newnode;
  int val;
  ptr=start;
  printf("\nenter the value to enter at the last ");
  scanf("%d",&val);
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->next=NULL;
  while(ptr->next!=NULL)
     ptr=ptr->next;
     ptr->next=newnode;
}

void insert_at_position()
{ struct node *ptr,*newnode;
  int val,num;
  printf("\nenter the number after which number to be enter and the value to be added ");
  scanf("%d %d",&num,&val);
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=val;
  ptr=start;
  while(ptr->data!=num)
           ptr=ptr->next;
  newnode->next=ptr->next;  
  ptr->next=newnode;
    
}


void delete_beg()
{struct node *ptr;
  ptr=start;
  start=start->next;
  free(ptr);
}

void delete_last()
{  struct node *ptr;
   ptr=start;
  while(ptr->next->next!=NULL)
    ptr=ptr->next;
   free(ptr->next);
   ptr->next=NULL;
}


void delete_at_position()
{   struct node *ptr;
     ptr=start; int val; 
    printf("\n enter the value to delete");
    scanf("%d",&val);
    while(ptr->next->data!=val)
        ptr=ptr->next;
    ptr->next=ptr->next->next;
}

void search()
{  struct node *ptr;
   ptr=start;
   int val,f=0;
   printf("\nenter value to search");
   scanf("%d",&val);
   while(ptr->next!=NULL)
     {  if(ptr->data==val)
         {      f=1;
           break;}
        else 
          ptr=ptr->next;
     }
 if(f==1)
  printf("\nfound\n");
 else
  printf("\n-1\n");
}

void reverse(struct node *ptr)
{
  if(ptr==NULL)
   return ;
  else 
    reverse(ptr->next);
    printf(" %d",ptr->data);
}














int main()
{   int m;
   
do{
    printf("\nMENU\n1:for creating a linked list\n2:for dispaly a linked list\n3:for insert at the beginning\n4:for insert at the last\n5:for insert at given position\n6:for delete at beginning\n7:for delete from last\n8:for delete a value\n9:to search for an element\n10:for traverse forward\n11:to traverse reverse\n12:to exit");
   scanf("%d",&m);
  switch(m){
  case 1:create();
     break;
  case 2:display();
     break;
  case 3:insert_at_beg();
    break;
  case 4:insert_at_end();
    break;
  case 5:insert_at_position();
    break;
  case 6:delete_beg();
   break;
  case 7:delete_last();
   break;
  case 8:delete_at_position();
   break;
   case 9:search();
   break;
   case 10:display();
    break;
   case 11:reverse(start);
    break;
           }
  }while(m!=12);
return 0;}
