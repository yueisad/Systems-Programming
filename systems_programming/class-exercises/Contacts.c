#include <stdio.h>
#include <string.h>

typedef struct ContactNode_struct {
   char contactName[100];
   char contactPhoneNumber[100];
   struct ContactNode_struct* nextContactNodePtr;
} ContactNode;

// Initialization
void InitializeContactNode(ContactNode* thisNode, char* initialName, char* initialPhoneNumber) {
   strcpy(thisNode->contactName, initialName);
   strcpy(thisNode->contactPhoneNumber, initialPhoneNumber);
   thisNode->nextContactNodePtr = NULL;
}

void InsertAfter(ContactNode* thisNode, ContactNode* newContactNode) {
   ContactNode* tempNext = thisNode->nextContactNodePtr;
   thisNode->nextContactNodePtr = newContactNode;
   newContactNode->nextContactNodePtr = tempNext;
}

char* GetName(ContactNode* thisNode) {
   return thisNode->contactName;
}

char* GetPhoneNumber(ContactNode* thisNode) {
   return thisNode->contactPhoneNumber;
}

   ContactNode* GetNext(ContactNode* thisNode) {
   return thisNode->nextContactNodePtr;
}

void PrintContactNode(ContactNode* thisNode) {
   printf("Name: %s\n", thisNode->contactName);
   printf("Phone number: %s\n", thisNode->contactPhoneNumber);
}

void prompt(char fullName[], char phoneNumber[], const int TEXT_LIMIT) {
   printf("Enter contact name: ");
   fgets(fullName, TEXT_LIMIT, stdin);    // Reads a full line
   fullName[strlen(fullName) - 1] = '\0';  // Replaces the newline character

   printf("Enter phone number :");
   fgets(phoneNumber, TEXT_LIMIT, stdin);
   phoneNumber[strlen(phoneNumber) - 1] = '\0';
}


int main(void) {
   const int TEXT_LIMIT = 100;
   char fullName[TEXT_LIMIT];
   char phoneNumber[TEXT_LIMIT];
   ContactNode contactEntry1;
   ContactNode contactEntry2;
   ContactNode contactEntry3;
   ContactNode* currContactEntry;

   //prompt contact 1
   prompt(fullName, phoneNumber, TEXT_LIMIT);
   printf("Person 1: %s, %s\n", fullName, phoneNumber);

   // First contact node (head of list)
   InitializeContactNode(&contactEntry1, fullName, phoneNumber);

   prompt(fullName, phoneNumber, TEXT_LIMIT);
   printf("Person 2: %s, %s\n", fullName, phoneNumber);
   // Second contact node
   InitializeContactNode(&contactEntry2, fullName, phoneNumber);
   InsertAfter(&contactEntry1, &contactEntry2);

   prompt(fullName, phoneNumber, TEXT_LIMIT);
   printf("Person 3: %s, %s\n", fullName, phoneNumber);
   // Third contact node
   InitializeContactNode(&contactEntry3, fullName, phoneNumber);
   InsertAfter(&contactEntry2, &contactEntry3);

   // Print contact list
   printf("\nCONTACT LIST\n");
   currContactEntry = &contactEntry1;

   while (currContactEntry != NULL) {
      PrintContactNode(currContactEntry);
      printf("\n");
      currContactEntry = GetNext(currContactEntry);
   }

   return 0;
}
