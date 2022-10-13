//There are several syntax and logic errors within this program.
//The program should prompt the user for the number of integer values to enter.
//The program should store each value within a linked list.  Each value that
//is entered is stored at the end of the linked list.
//Hint: there are 5 areas within this program that need attention.

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
void IntNode_PrintData(Intnode*);
void PrintLinkedList(Intnode*);

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
   IntNode* newNode = NULL;
   newNode->dataVal = v;
   newNode->nextNodePtr = NULL;

   return newNode;
} //end CreateNode


void IntNode_InsertAfter(IntNode* thisNode, IntNode* newNode) {
   IntNode* tmpNext = NULL;

   tmpNext = thisNode->newNode;
   thisNode->nextNodePtr = tmpNext;
   newNode->nextNodePtr = nextNodePtr;
} //end InsertAfter


//get location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode) {
   return thisNode.nextNodePtr;
} //end GetNext


//Print node's data
void IntNode_PrintData(IntNode thisNode) {
   printf("%d, ", thisNode.dataVal);
}

