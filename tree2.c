#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int key;
    struct node *left, *right;
};
  

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {   printf(" %d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n",root->key);
    }
}

struct node* insert(struct node* node, int val)
{
     if (node == NULL) 
   {  struct node* newnode= (struct node *)malloc(sizeof(struct node)); 
       newnode->left=newnode->right=NULL;
       newnode->key=val;
      return newnode;
   }
 
    if (val < node->key)
        node->left  = insert(node->left,val);
    else if (val > node->key)
        node->right = insert(node->right,val);   
 
    return node;
}

void search(struct node* root, int key)
{

    if (root == NULL || root->key == key)
   {   if(root!=NULL)  
         printf("\nfound\n");
      else if(root==NULL)
         printf("\nNOt Found\n");
        
         return ;}

    if (root->key < key)
        search(root->right, key);
    else
        search(root->left, key);
}



struct node* deleteNode(struct node* root, int key)
{
   
    if (root == NULL) 
       return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children
        struct node* temp = root->right;

       while (temp->left != NULL)
          temp=temp->left;
   
       root->key = temp->key;
       // Delete the inorder successor
       root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
  

int main()
{
   
    struct node *root = NULL;
    int val=0,choice;
    do{ printf("Enter The Choice\n1:For insertion\n2:for deletion\n3:for searching\n4:for inorder traversal\n5:for postorder traversal\n6:for preorder Traversal\n");
     scanf("%d",&choice);
     switch(choice)
    {
      case 1:{  scanf("%d",&val);
                root = insert(root,val);
             }
              break;
      case 2:{  scanf("%d",&val);
                root=deleteNode(root,val);
             }
              break;
      case 3:{
               scanf("%d",&val);
               search(root,val);
          
             }
              break; 
      case 4:{ printf("\nIn order Traversal is\n"); 
              inorder(root); 
             }
             break;
      case 5:{  printf("\nPost Order Traversal Is\n");
                postorder(root);
             }
              break;
      case 6:{  printf("\nPreorder Traversal is \n");
                 preorder(root);
             }
              break;
     }
      }while(choice!=-1);
   
   return 0;
}

