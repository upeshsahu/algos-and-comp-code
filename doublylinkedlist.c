#include<stdio.h>
#include<malloc.h>
struct node {
int data;
struct node *next;
struct node *prev;
};
struct node *start=NULL;
void create()
{  int val;
  printf("enter the value");
  scanf("%d",&val);
  while(val!=-1)
  { struct node *newnode,*ptr;
    ptr=start;
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->next=NULL;
   newnode->data=val;
   if(ptr==NULL)
    {newnode->prev=NULL;
     start=newnode;
    }
   else 
   {  while(ptr->next!=NULL)
      ptr=ptr->next;
      newnode->prev=ptr;
      ptr->next=newnode; 
   }
   printf("enter the value");
   scanf("%d",&val);
  }
}
void display()
{struct node *ptr;
 ptr=start;
  while(ptr!=NULL)
   {  printf("%d ",ptr->data);
      ptr=ptr->next;
   }
}
void insert_at_beg()
{
  int val;
  printf("enter the value to insert at begining");
  scanf("%d",&val);
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->next=start;
  start->prev=newnode;
  newnode->data=val;
  newnode->prev=NULL;
  start=newnode;
}
void insert_at_last()
{
 int val;
  printf("enter the value to insert at last");
  scanf("%d",&val);
  struct node *newnode,*ptr;
  ptr=start;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->next=NULL;
  newnode->data=val;
  while(ptr->next!=NULL)
    ptr=ptr->next;
  newnode->prev=ptr;
  ptr->next=newnode;
}
void insert_at_position()
{ int val,num;
  printf("enter the value after which new node to be insert and  insert the  value of new node");
  scanf("%d %d",&num,&val);
  struct node *newnode,*ptr;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=val;
  while(ptr->data!=num)
     ptr=ptr->next;
  newnode->prev=ptr;
  newnode->next=ptr->next;
  ptr->next->prev=newnode;
  ptr->next=newnode;
  
}
void delete_at_beg()
{ struct node *ptr;
  ptr=start;
   ptr->next->prev=NULL;
  start=ptr->next; 
   free(ptr);}
void delete_at_end()
{  struct node *ptr;
   ptr=start;
   while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->prev->next=NULL; 
   free(ptr);
      
}
void delete_at_position()
{  struct node *ptr;
   ptr=start;
   int val;
   printf("\nenter the value to delete");
   scanf("%d",&val);
   while(ptr->data!=val)
           ptr=ptr->next;
   ptr->prev->next=ptr->next; 
   free(ptr);
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
{  int option;
   do{  printf("\nMENU\n1:to create\n2:to dispaly\n3:ti insert at beginning\n4:for insert at last\n5:for insert atfer a given position\n6:to delete the fisrt element \n7:to delete the last element\n8:to delete the given element\n9:to search an element\n10:to traverse\n11:to trverse reverse\n12:to EXIT");
        scanf("%d",&option);
 switch(option)
{  case 1:create();
    break;
  case 2:display();
    break;
  case 3:insert_at_beg();
   break;
  case 4:insert_at_last();
  break;
  case 5:insert_at_position();
  break;
  case 6:delete_at_beg();
  break;
  case 7:delete_at_end();
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
    }while(option!=12);
return 0;}
