#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int roomID;             //ID 1 to 5
    int status;             //0 - Empty | 1 - Taken
    char customerName[20];  //To be entered by user
} Room;

void checkEmpty(Room room[]);
void listOccupiedRooms(Room room[]);
void assignRoom(Room room[]);
void removeRoom(Room room[]);
void findCustomer(Room room[]);

int contLoop =1;            //to break while loop for quit
int choice;                 //scanf choice
static int emptyRm = 5;

int main()
{
    Room room[5];

    room[0].roomID = 1;
    room[1].roomID = 2;
    room[2].roomID = 3;
    room[3].roomID = 4;
    room[4].roomID = 5;

    room[0].status = 0;
    room[1].status = 0;
    room[2].status = 0;
    room[3].status = 0;
    room[4].status = 0;

    printf("NTU HOTEL ROOM RESERVATION PROGRAM: \n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom() \n");
    printf("3: removeRoom() \n");
    printf("4: findCustomer() \n");
    printf("5: quit \n");

    while (contLoop){
        checkEmpty(room);
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("listOccupiedRooms(): \n");
            listOccupiedRooms(room);
            break;

        case 2:
            printf("assignRoom(): \n");
            assignRoom(room);
            break;

        case 3:
            printf("removeRoom(): \n");
            removeRoom(room);
            break;

        case 4:
            printf("findCustomer(): \n");
            findCustomer(room);
            break;

        case 5:
            contLoop = 0;
        }
    }
    return 0;
}

void checkEmpty(Room room[]){
    emptyRm = 0;
    for (int i=0; i<5; i++){
        if (room[i].status == 0){
            emptyRm +=1;
        }
}

}
void listOccupiedRooms(Room room[]){
    for (int i =0; i<5; i++){           //loops through the struct database
        if(room[i].status == 1){        //checks for status. 1 = taken
            printf("roomID: %d \n",room[i].roomID);
            printf("customer name: %s\n", room[i].customerName);
        }
    }
    if (emptyRm == 5){
            printf("The hotel is empty \n");
    }
}

void assignRoom(Room room[]){
    int roomID =0;
    int assign = 1;
    char custName[20];

    if (emptyRm == 0){
        printf("The hotel is full\n");
        assign = 0;
    }

    while (assign){                           //True while attempting to assign (requirement not met)
        while (roomID < 1 || roomID >5){      //check input to be within 1 to 5
            printf("Enter a roomID between 1 and 5:\n");
            scanf("%d", &roomID);
        }

        if (room[roomID-1].status == 1){
            printf("Occupied! Enter another roomID\n");
            roomID =0;

        } else {
            room[roomID-1].status = 1;            //assign room with a customer name
            printf("Enter customer name:\n");
            scanf(" %[^\n]s", custName);
            strcpy(room[roomID-1].customerName,custName);
            printf("The room has been assigned successfully\n");
            assign = 0;
        }
    }
}

void removeRoom(Room room[]){
    int roomID =0;
    int removed =0;

    while (!removed){
       if (emptyRm == 5){
            printf("All the rooms are empty\n");
            removed = 1;
        } else {
            while (roomID < 1 || roomID >5){      //check input to be within 1 to 5
                printf("Enter a roomID between 1 and 5:\n");
                scanf("%d", &roomID);
            }

            if (room[roomID-1].status == 0){          //check if room is alr empty
                printf("Empty! Enter another roomID for removal \n");
                roomID =0;
            } else {
                room[roomID-1].status = 0;
                strcpy(room[roomID-1].customerName,"");
                printf("Removal is successful \n");
                removed = 1;
            }
        }
    }

}

void findCustomer(Room room[]){
    char custName[20];
    int found = 0;

    printf("Enter customer name:\n");
    scanf(" %[^\n]s", custName);

    for (int i=0; i<5; i++){
        if (strcasecmp(room[i].customerName,custName) == 0){    //strcmp returns 0 when string matches
            printf("The target customer name is found\n");
            printf("roomID: %d\n", room[i].roomID);
            printf("customer name: %s\n", room[i].customerName);
            found = 1;
            break;
        }
    }

    if (!found){
        printf("The target customer name is not found\n");
    }
}
