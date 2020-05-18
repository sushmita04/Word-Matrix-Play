#include <iostream>
#include <string.h>
const int T_S = 256;                                  //hash table size
using namespace std;

struct Node {
    int key;
    Node *next; 
};

struct Node *ht[T_S]; 
void InitializeHT() {                                   //initialization of hash table
    for(int i = 0; i < T_S; i++)
        ht[i] = NULL;
}

int HashFunc(int key) {                                 //hash function
    return key % T_S;
}
      
void InsertInHashTable(struct Node** head, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *temp = *head;                          //temp is to traverse
    new_node->key  = new_data; 
    new_node->next = NULL; 
  
    if(*head == NULL) { 
       *head = new_node; 
       return; 
    }   
    while(temp->next != NULL) 
        temp = temp->next; 
    temp->next = new_node; 
    return;     
}

int main() {
   int index, i=0;
   string str;
   cout<<"Enter the word ";
   cin>>str;
   InitializeHT();
   while(str[i]!='\0') {
        index=HashFunc(str[i]);
        InsertInHashTable(ht[index], i);          //check the error
   }
   return 0;
}
