#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100
void method(char s1[],char s2[]);
void reverse(char temp[],char po[]);
char st[max],top=-1;



int main()
{ char in[100],po[100];
   scanf("%s",in);
  strcpy(po,"");
   reverse(in,po);
    //making string null
   strcpy(in,"");
   method(po,in);
   strcpy(po,"");
   reverse(in,po);
   printf("%s",po);
 return 0;}






void push(char val)
{  if(top==max-1)
   {printf("\nstack overflow");}
 top++;
 st[top]=val;

}


char pop(char st[])
{  char val; 
  if(top==-1)
      printf("\n stack underflow");  
  else 
      val=st[top];
      top--;
   return val;
 }







int getp(char op)
{  if((op=='/')||(op=='*')||(op=='%'))
      return 1;
   else if(op=='+'||op=='-')
     return 0;
}


void method(char s1[],char s2[])  //s1=infix,s2=postfix
  {    int i=0;                     //for s1
       int j=0;                     //for s2
       char temp;                 //only for pop method 
   strcpy(s2,"");                  //making s2 empty removing garbage value
  
   while(s1[i]!='\0')                    //treversing the expression
   {
        if(s1[i]=='(')
           {  push(s1[i]);            // push these ( sign into stack
                  i++;
           }
        else if(s1[i]==')')                   
           {           while((top!=-1)&&(st[top]!='('))
                                 {    (s2[j]=pop(st));
                                       j++;
                                 }
                 
                       if(top==-1)
                            {  printf("INVLID EXPRESSION");  return ;}   //if stack is empty then its an invalid expression
                                   

                                     temp=pop(st);        //if ( this is there in stack then remove it 
                                     i++;
           }
       else if(isdigit(s1[i])||isalpha(s1[i]))          //if any alpha numeric term is came then add it to postfix expression
               {       s2[j]=s1[i];
                      i++;
                      j++;
                }   
       else if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='%')               
             {  
                 while( top!=-1 && st[top]!='('&& (getp(st[top]>getp(s1[i]))))
                          {  s2[j]=pop(st);
                                j++;
                          }
                       push(s1[i]);
                            i++;
              }
       else 
               {printf("\n incorrect element in expression ");}
          

   }
   
  while(  top!=-1 && st[top]!='(' )
          {      s2[j]=pop(st);
                     j++;
          }


        s2[j]='\0';
}









void reverse(char str[],char temp[])
{  int j=0,i=0;
   j=strlen(str)-1;
   while(j>=0)
   {    
    if(str[i]=='(')
          temp[j]=')';
    else if(str[i]==')')
          temp[j]='(';
    else 
         temp[j]=str[i];


  j--;i++;}   
   temp[i]='\0';
}
