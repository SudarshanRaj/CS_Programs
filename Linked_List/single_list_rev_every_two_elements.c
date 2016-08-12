#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node
{
  uint32_t val;
  struct node* next;  
  
}node;


void list_print(node* root)
{
  /* NULL pointer checking */
  assert(root != NULL); 
  
  if( root->next == NULL )  //Root is the only node
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

void list_insert(node* root, uint32_t val)  //Equivalent to node append 
{
 
  /* NULL pointer checking */
  assert(root != NULL); 
  
  while(root->next != NULL)  //Traverse till the end
    root = root->next;
  
  
  node* new = malloc(sizeof(node));  //Allocate memory for our new node
  
  new->next = NULL;
  new->val  = val;
  
  root->next = new;  
}

void list_rev_every_two_elements(node** root_ref)
{
  /* NULL pointer checking */
  assert(root_ref != NULL); 
  
  node* current = *root_ref;
  
  if( current->next == NULL )  //if only one node, then return.
    return;                    //nothing else to do
  
  node* next = current->next->next;
  node* prev = current;
  current = current->next;
    
  *root_ref = current;
  
  while(prev)
  {
   
    current->next= prev;
    prev->next = next;    
    
    if(next == NULL)
      break;
    
    if(next->next == NULL)
      break;
    
    prev->next = next->next;
    
    prev = next;
    current = next->next;
    next = current->next;
    
  }  
}


int main()
{
 
  node* root = NULL;  //root or head node
  
  root = malloc( sizeof(node) );
  assert( root != NULL );
  
  root->next = NULL;  
  root->val = 1;
  
  list_insert(root, 2);
  list_insert(root, 3);
  list_insert(root, 4);
  list_insert(root, 5);
  //list_insert(root, 6);

  printf("Original list:\n");
  list_print(root);
  
  list_rev_every_two_elements(&root);
  
  printf("\n\nModified list:\n");
  list_print(root);
  
  return 0;
  
}