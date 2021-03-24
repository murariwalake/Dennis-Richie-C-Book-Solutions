/*all functions of linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};
typedef struct node* NODE;
NODE first = NULL;

NODE getNode();
NODE insertFront(NODE,int);
NODE deleteFront(NODE);
NODE insertRare(NODE, int);
NODE deleteRare(NODE);
NODE insertPos(NODE, int, int);
NODE delatePos(NODE, int);
NODE deleteSpecifiedData(NODE, int);

void display(NODE);

int main(){
  int choice, item,pos;

  while(1){
    printf("1.insert front\t2.insert rare\t3.delete front\n4.delete rare\t5.insert at position\t6.delete at position\n7.delite specified data\n");
    printf("8.display\t9.Exit\nEnter your choice\n");
    scanf("%d", &choice);
    /*call for respective function*/
    switch (choice) {
      case 1:
      printf("Enter the item to be iserted\n");
      scanf("%d", &item);
      first = insertFront(first, item);
       break;

      case 2:
      printf("Enter the item to be iserted\n");
      scanf("%d", &item);
      first = insertRare(first, item);
       break;

      case 3: first = deleteFront(first); break;
      case 4: first = deleteRare(first); break;
      case 5:
      printf("enter the node and its position NOTE: position start from zero\n");
      scanf("%d %d", &item, &pos );
      first = insertPos(first, item, pos); break;

      case 6:
      printf("enter the position of the node to be deleted NOTE: position start from zero\n");
      scanf("%d", &pos );
      first = delatePos(first, pos); break;

      case 7:
      printf("enter the data of the node to be deleted\n");
      scanf("%d", &item );
      first = deleteSpecifiedData(first, item); break;

      case 8: display(first);break;
      case 9:exit(0);
      default: printf("Wrong choice please enter the valid choice\n");
    }
  }

  return 0;
}
/*creat node*/
NODE getNode(){
  NODE temp = (NODE)malloc(sizeof(NODE));
  temp->link = NULL;
  return temp;
}

NODE insertFront(NODE first, int item){
  NODE temp = getNode();
  temp->data = item;

   temp->link = first;
    return temp;
}

NODE insertRare(NODE first, int item){
  NODE temp = getNode();
  temp->data = item;
 /*if list is empty*/
  if(first == NULL)
    return temp;

  NODE cur = first;
  /*move to last node*/
  while(cur->link != NULL)
    cur = cur->link;

  cur->link = temp;
    return first;
}

NODE deleteFront(NODE first){
  if(first == NULL){
    printf("ERROR:Cannot delete, list is empty\n");
    return NULL;
  }

  NODE temp = first;
  first = first->link;
  free(temp);
  return first;
}

NODE deleteRare(NODE first){
  if(first == NULL){
    printf("ERROR:Cannot delete, list is empty\n");
    return NULL;
  }
  /**if only one node exist*/
  if(first->link == NULL){
    free(first);
    return NULL;
  }

  NODE prev = NULL;
  NODE cur = first;
  /*move to last node*/
  while(cur->link != NULL){
    prev = cur;
    cur = cur->link;
  }

  prev->link = NULL;
  free(cur);
  return first;
}

void display(NODE first){
   if(first == NULL){
    printf("ERROR:Cannot display, list is empty\n");
      return;
  }
 while(first){
   printf("%d%s",first->data, first->link == NULL?"\n":"-> " );
   first = first->link;
 }
}

NODE insertPos(NODE first, int item, int pos){
  /*negative position is an error*/
  if(pos < 0){
    printf("ERROR: invalid position, insertion not possible\n");
    return first;
  }

  NODE temp = getNode();
  temp->data = item;

  /*isert first node*/
  if(pos == 0 && first == NULL){
    return temp;
  }

  /*front inserstion*/
  if(pos == 0)
    return insertFront(first, item);

  /*move cur to previous node postion to be iserted*/
  NODE cur = first;
  while(--pos && cur->link != NULL){
    cur = cur->link;
  }

  /*check for valid position*/
  if(pos == 0){
      temp->link = cur->link;
      cur->link = temp;
      return first;
  }

  /*invalid position*/
  printf("ERROR: invalid position, insertion not possible\n");
  return first;

}

NODE delatePos(NODE first, int pos){
  /*negetive position is error*/
  if(pos < 0 ){
    printf("ERROR: invalid position, deletion not possible\n");
    return first;
  }
  /*handel empty list*/
  if(first == NULL){
    printf("ERROR: List is empty cnnot be delet\n");
    return first;
  }

  /*if list contain single node and position is 0*/
  if(first->link == NULL && pos == 0){
    free(first);
    return NULL;
  }

  /*if list contin more than one node and pos is 0*/
  if(pos == 0)
    return deleteFront(first);

  /*point cur at previos nod of the node which to be deleted*/
  NODE cur = first;
  while(pos-- && cur->link->link != NULL){
    cur = cur->link;
  }

  if(pos == 0){
    NODE temp = cur->link;
    cur->link = cur->link->link;
    free(temp);
    return first;
  }

  printf("ERROR: invalid position, node cannot be deleted\n");
  return first;
}

NODE deleteSpecifiedData(NODE first, int item){
  if(first == NULL){
    printf("ERROR:list is empty, cannot be deleted any element\n");
    return NULL;
  }
  if(first->link == NULL && first->data == item){
    free(first);
    return NULL;
  }

  NODE pre = NULL;
  NODE cur = first;
  while(cur->data != item && cur->link != NULL){
    pre = cur;
    cur = cur->link;
  }

  if(cur->data == item){
    pre->link = cur->link;
    free(cur);
    return first;
  }

  printf("ERROR:specified node is not found\n");
  return first;
}
