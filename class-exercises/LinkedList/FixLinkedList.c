//Create a linked list and display the contents
//Update this program

//  1.  Rewrite the recursive functions to be nonrecursive
//  2.  Create a double linked list or a circular linked list
//  3.  Display the contents in reverse order

#include<stdio.h>
#include<stdlib.h>

typedef struct IntNode {
  int dataVal;
  struct IntNode* nextNodePtr;
} IntNode;

//prototypes
IntNode* IntNode_GetNext(IntNode*);
IntNode* CreateNode(int);
void IntNode_InsertAfter(IntNode*, IntNode*);
void IntNode_PrintData(IntNode*);
void PrintLinkedList(IntNode*);

//main
int main(void) {
  int size;
  int value;

  printf("Enter the size: ");
  scanf("%d", &size);

  printf("Enter the value: ");
  scanf("%d", &value);

  IntNode* headNode = CreateNode(value); //make head as the first node
  IntNode* lastNode = headNode;          //node to add after
  IntNode* newNode = NULL;

  //Insert the second and the rest of the nodes
  for(int i = 0; i < size - 1; ++i) {
    printf("Enter a value: ");
    scanf("%d", &value);
    newNode = CreateNode(value);
    IntNode_InsertAfter(lastNode, newNode);
    lastNode = newNode;
  } //end for

  //call printLinkedList() 
    PrintLinkedList(headNode);
    return 0;
} //end main


//print the linked list
void PrintLinkedList(IntNode* node) {
   if (node != NULL) {  //nothing to do if NULL
      IntNode_PrintData(node);
      PrintLinkedList(IntNode_GetNext(node));
   }
   printf("\n");
}//end PrintLinkedList


//Create a new node
IntNode* CreateNode(int v) {
   IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
   newNode->dataVal = v;
   newNode->nextNodePtr = NULL;

   return newNode;
} //end CreateNode



//Insert a new node after the current node
void IntNode_InsertAfter(IntNode* thisNode, IntNode* newNode) {
   IntNode* tmpNext = NULL;

   tmpNext = thisNode->nextNodePtr;
   thisNode->nextNodePtr = newNode;
   newNode->nextNodePtr = tmpNext;
} //end InsertAfter


//get location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode) {
   return thisNode->nextNodePtr;
} //end GetNext


//Print node's data
void IntNode_PrintData(IntNode* thisNode) {
   printf("%d, ", thisNode->dataVal);
}


