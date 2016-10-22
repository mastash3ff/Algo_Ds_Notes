#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  int key;
  struct node *next;
};

struct node *head = NULL;
struct node *curr = NULL;

//prints out each node in the list
void printList() {
  struct node *ptr = head;

//start from the beginning
while(ptr != NULL) {
  printf("(%d,%d) ",ptr->key,ptr->data);
  ptr = ptr->next;
}
}

//is list empty
bool isEmpty() {
  return head == NULL;
}

//counts the length of the linked list
int length() {
  int length = 0;
  struct node *curr;
  
  for(curr = head; curr != NULL; curr = curr->next) {
    length++;
  }
  
  return length;
}

//insert link at the first location
void insertFirst(int key, int data) {
  //create a link
  struct node *link = (struct node*) malloc(sizeof(struct node));

  link->key = key;
  link->data = data;

  //point it to old first node
  link->next = head;

  //point first to new first node
  head = link;
}

//delete first item
struct node* deleteFirst() {

  //save reference to first link
  struct node *tempLink = head;

  //mark next to first link as first
  head = head->next;
  
  //return the deleted link
  return tempLink;
}

int main(){
  insertFirst(1,3);
  insertFirst(2,6);
  insertFirst(3,9);
  printList();
  printf("\nLength of List: %d\n",length());
  deleteFirst();
  printf("Deleted one node\n");
  printf("New length of List: %d\n",length());
    
  return 0;

}

/* Output
   (3,9) (2,6) (1,3) 
   Length of List: 3
   Deleted one node
   New length of List: 2
*/
