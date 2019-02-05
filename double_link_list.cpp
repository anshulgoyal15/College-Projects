#include<iostream>
using namespace std;

// structure of node for link list
struct node {
  int data;
  struct node * next;
  struct node * prev;
  node( int val){
    data= val;
    next=NULL;
    prev=NULL;
  }
};

// create link list from array<int>
struct node * create_link_list(int arr[],int n){
  struct node * head=new node(arr[0]);
  struct node * prev=head;
  for(int i=1;i<n;i++){
    struct node * current=new node(arr[i]);
    prev->next=current;
    current->prev=prev;
    prev=current;
  }
  return head;
}

// search an element from link list
int search_link_list(struct node * head,int query){
  struct node * current=head;
  int counter=0;
  while(current){
    if(current->data==query){
      return counter;
    }
    current=current->next;
    counter++;
  }
}

// insert a new element at any position
struct node * insert_link_list(struct node * head,int position,int value){
  struct node * new_node=new node(value);
  if(position==0){
    new_node->next=head;
    head=new_node;
  }
  else{
    struct node * current=head;
    for(int i=0;i<position;i++){
      current=current->next;
    }
    new_node->next=current->next;
    new_node->prev=current;
    current->next=new_node;
  }
  return head;
}

// delete a node at any point in node
struct node * delete_node(struct node * head,int position){
  if(position==0){
    head=head->next;
  }
  else{
    struct node * current=head;
    struct node * prev=head;
    for(int i=0;i<position;i++){
      prev=current;
      current=current->next;
    }
    prev->next=current->next;
    current->next->prev=prev;
  }
  return head;
}

// traverse a link list
void transvers_link_list(struct node * head){
  struct node * current=head;
  while(current){
    cout<<current->data<<"->";
    current=current->next;
  }
}

// traverse a link list in reverse
void transvers_reverse_link_list(struct node * head){
  struct node * current=head;
  while(current->next){
    current=current->next;
  }
  while(current){
    cout<<current->data;
    current=current->prev;
  }
}


int main(){
  int arr[]={1,2,3,4,5};
  struct node * head=create_link_list(arr,5);
  transvers_reverse_link_list(head);
 //insert_link_list(head,3,4);
  head=delete_node(head,3);
  transvers_reverse_link_list(head);
  return 0;
}
