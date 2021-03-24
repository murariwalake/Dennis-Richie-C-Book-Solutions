/*asending priority queue*/

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};
typedef struct node* NODE;
NODE getNode();
NODE push(NODE, int);
NODE pop(NODE);
void display(NODE);

int main() {
   int choice, item;

   NODE head = getNode();
   head->data = 0;
   head->link = head;

   while(1){
     printf("1.push\t2.pop\n3.display\t4.exit\nEnter your choice\n" );
     scanf("%d", &choice );
     switch (choice) {
       case 1:
       printf("Enter the value to insert\n");
       scanf("%d", &item);
       head =  push(head, item); break;

       case 2: head = pop(head); break;
       case 3: display(head); break;
       case 4: exit(0);
       default: printf("Wrong choice\n");
     }
   }
   return 0;
}

NODE getNode(){
  NODE temp = (NODE)malloc(sizeof(NODE));
  temp->link = NULL;
  return temp;
}

NODE push(NODE head, int item){
  NODE temp = getNode();
  temp->data = item;
  head->data++;

 /*list is empty*/
  if(head->link == head){
    head->link = temp;
    temp->link = head;
    return head;
  }

  NODE cur = head->link;
  NODE prev = head;
  /*move the cur untill to get  correct position of item*/
  while(item > cur->data && cur->link != head ){
    prev = cur;
    cur = cur->link;
  }
  /*if the item is less than existing nodes*/
  if(item <= cur->data){
    prev->link = temp;
    temp->link = cur;
    return head;
  }
  /*if the item is greater than existing nodes*/
  if(cur->link == head){
    temp->link = cur->link;
    cur->link = temp;
    return head;
  }


}

NODE pop(NODE head){
  if(head->link == head){
    printf("ERROR: list is empty, cannot delete any node\n");
    return head;
  }
 /*delete first node*/
 NODE temp = head->link;
 head->link = temp->link;
 free(temp);
 return head;
}

void display(NODE head){
   if(head->link == head){
    printf("ERROR:Cannot display, list is empty\n");
      return;
  }
  NODE cur = head->link;
 while(cur != head){
   printf("%d%s", cur->data, cur->link == head?"\n":"-> " );
   cur = cur->link;
 }
}
