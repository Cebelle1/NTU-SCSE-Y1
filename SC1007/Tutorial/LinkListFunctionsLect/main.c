#include <stdio.h>
#include <stdlib.h>

int choice;
int index;
int insert_index;
int value;
int remove_index;

typedef struct listNode{
        int item;
        struct listNode *next;
} ListNode;

void printList(ListNode *head);
ListNode *findNode(ListNode *head, int index);
int insertNode(ListNode **head, int insert_index, int value);
int removeNode(ListNode **head, int index);

int main()
{
    ListNode *head = NULL;
    //printf("Pointer:%p\n",&head);
    while(1){
        printf("Select: \n1)Print List\n2)Find Node\n3)Insert Node\n4)Remove Node\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printList(head);      //passes in the content of head (address of the list itself, excluding the head)
                break;
            case 2:
                index = 1;
                ListNode *rHead = NULL;
                rHead = findNode(&head, index);
                break;
            case 3:
                insert_index=0;     //insert at next empty link
                value = 1;
                int retVal;
                retVal = insertNode(&head,insert_index,value);      //passes in the head address itself
                insert_index=1;
                value=2;
                retVal = insertNode(&head,insert_index,value);
                insert_index=2;
                value=3;
                retVal = insertNode(&head,insert_index,value);
                break;
            case 4:
                remove_index = 1;
                removeNode(&head,remove_index);
                break;
        }
    }

    return 0;
}

void printList(ListNode *head){
    printf("Head pointing to:%p\n", head);
    //printf("Pointer:%p\n",head);
    if (head == NULL){
        printf("Empty Node");
        return;
    }

    while(head != NULL){
        printf("Addresses:%p \n",head);
        head = head->next;
    }

    printf("End of List\n");

}

ListNode *findNode(ListNode *head, int index){

    if(head == NULL){
        printf("Empty Node");
        return;
    }

    while(index !=0 ){
        head = head->next;
        index--;
    }
    //printf("Item at: %d",head->item);      //or return head for non-void func
    return head;
}

int insertNode(ListNode **head, int insert_index, int value){

    ListNode *pre, *cur, *newNode;
    if(insert_index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->item = value;
        newNode->next = *head;  //Points to what the head was pointing to, releasing head for changes (value of what dtr points to, basically the ListNode start excl header)
        *head = newNode;        //Now the pointer head, points to newNode. Shifts infront.
        return 1;
    }   //If the prev node isnt null (out of index, eg cur list have 2 but want to put at index 5)
    else if ((pre = findNode(*head, insert_index-1)) != NULL){
                newNode = malloc(sizeof(ListNode));
                newNode->item = value;
                newNode->next = pre->next;
                pre->next = newNode;
                //printf("Inserted!\n");
                return 1;
    }
    return 0;
}


int removeNode(ListNode **head, int remove_index){
    printf("At Pointer:%p\n", *head);
    ListNode *temp, *cur, *pre;
    if (*head == NULL){
        printf("Empty list\n");
        return -1;
    }

    if (index = 0){
        //deleting the first node, have to change the address of what the head pointer is pointing to
        temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Freed first node\n");

    } else {
        cur = *head;
        printf("%d",remove_index);

        pre = findNode(*head, remove_index-1);
        printf("Pre node: %p\n", pre);

        temp = pre->next;   //Node to be removed

        printf("Changing %p to next next %p\n",pre->next,pre->next->next);
        pre->next = pre->next->next;
        
        printf("Freed: %p\n", temp);
        free(temp);
        printf("At Pointer:%p\n", *head);
    }

}
