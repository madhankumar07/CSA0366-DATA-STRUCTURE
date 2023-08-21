#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
} *LLOne, *LLTwo, *mergedLL;
 
void initialize(){
    LLOne = LLTwo = mergedLL = NULL;
}

void insert(struct node **head, int num) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted Element : %d\n", num);
}
 
struct node* mergeLinkedList(struct node* LLOne, struct node* LLTwo){
    struct node *resultHead, *resultTail, *temp;
    resultHead = resultTail = NULL;
    while(1) 
	{
    	
        if(LLOne == NULL){
            resultTail->next = LLTwo;
            break;
        }
         
        if(LLTwo == NULL) {
            resultTail->next = LLOne;
            break;
        }
        if(LLOne->data <= LLTwo->data){
            temp = LLOne;
            LLOne = LLOne->next;
        } else {
            temp = LLTwo;
            LLTwo = LLTwo->next;
        }
        /*Add smaller node to result linked list  */
        if(resultHead == NULL){
            resultHead = resultTail = temp;
        } else {
            resultTail->next = temp;
            resultTail = temp;
        }
        resultTail->next = NULL;
    }
     
    return resultHead;
}
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    initialize();
    insert(&LLOne, 9);  
    insert(&LLOne, 6); 
    insert(&LLOne, 3); 
    insert(&LLOne, 1);
    printLinkedList(LLOne);
    printf("\n");
    insert(&LLTwo, 10);  
    insert(&LLTwo, 6); 
    insert(&LLTwo, 5); 
    insert(&LLTwo, 2);
    printLinkedList(LLTwo);
    mergedLL = mergeLinkedList(LLOne, LLTwo); 
    printf("\nMerged Linked List\n");
    printLinkedList(mergedLL);
     
    return 0;
}
