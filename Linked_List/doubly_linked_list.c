#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
  struct Node* next;
  struct Node* prev;
  int val;
}Node;



void List_print(Node* root)
{
  /* NULL pointer checking */
  if(root == NULL)
  {
    printf("Root node is NULL in List_print(). Returing...\n");
    return;
  }
  
  if( (root->next == NULL) && (root->prev == NULL) )  //Root is the only node
  {
    printf("%d ",root->val);
    return;
  }
  else
  
  /* More than one node is present. Print them all by traversing the list */
  while(root)
  {
    printf("%d ",root->val);
    root = root->next;
  }  
  
}



void List_insert(Node* root, int val)  //Equivalent to node append 
{
 
  /* NULL pointer checking */
  if(root == NULL)
  {
    printf("Root node is NULL in List_print(). Returing...\n");
    return;
  }
  
  while(root->next != NULL)  //Traverse till the end
    root = root->next;
  
  
  Node* new = malloc(sizeof(Node));  //Allocate memory for our new node
  new->next = NULL;
  new->prev = root;
  new->val  = val;
  
  root->next = new;
  
}


void List_delete_node(Node* root, int val)
{
  /* NULL pointer checking */
  if(root == NULL)
  {
    printf("Root node is NULL in List_print(). Returing...\n");
    return;
  }

    if(root->prev == NULL)  //root node
  {
    root->next->prev = NULL;
    Node* new_root = root->next;
    //free(root);
    *root = *new_root;
    return;
  }
  
  while(root->val != val && root->next != NULL)
    root = root->next;
  
  if(root->next == NULL)  //last node
  {
    
    if(root->val == val)  //check for one final time with last node
    {
      root->prev->next = NULL;
      free(root);
    }
      
    else
      printf("Node with value %d not found!!\n", val);
    
    return;
  }
  
  Node* prev_node = root->prev;
  Node* next_node  = root->next;

  
  prev_node->next = next_node;
  next_node->prev = prev_node;
  
  free(root);
  
}


int main()
{
  
  Node* root;
  
  root = malloc(sizeof(Node));
  
  root->next = NULL;  
  root->prev = NULL;
  root->val = 132;
  
  List_insert(root, 84);
  List_insert(root, 324);
  List_insert(root, 254);
  List_insert(root, 68);
  List_insert(root, 13);
  List_insert(root, 97);
  
  printf("Root = %x\n", root);
  printf("Root->next = %d\n\n", root->next->val);
  
  List_print(root);
  printf("\n");
  
  List_delete_node(root, 132);
  
  printf("Root = %x\n", root);
  printf("Root->next = %d\n\n", root->next->val);
  
  List_delete_node(root, 68);
  
  List_print(root);
  
  
  return 0;
  
}