#include <stdio.h>
#include <stdlib.h>
#define INIT_VALUE -1000
#define SIZE 3

int findAr1D(int size, int ar[], int target);

void swap2Rows(int ar[][SIZE], int r1, int r2);
void swap2Cols(int ar[][SIZE], int c1, int c2);
void display(int ar[][SIZE]);


int main()
{
    //qn_1();
    qn_2();
    return 0;
}

void qn_1(){
    int ar[20];
    int size, i, target, result = INIT_VALUE;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<=size-1; i++)
        scanf("%d", &ar[i]);

    printf("Enter the target number: \n");
    scanf("%d", &target);
    result = findAr1D(size, ar, target);
    if (result == -1)
        printf("findAr1D(): Not found\n");
    else
        printf("findAr1D(): %d", result);
}

int findAr1D(int size, int ar[], int target){
    for (int i=0; i<size; i++){
        if (ar[i] == target){
            return i;
        }
    }
    return -1;
}

void qn_2(){
    int array[SIZE][SIZE];
    int row1, row2, col1, col2;
    int i,j; int choice;

    printf("Select one of the following options: \n");
    printf("1: getInput()\n");
    printf("2: swap2Rows()\n");
    printf("3: swap2Cols()\n");
    printf("4: display()\n");
    printf("5: exit()\n");

    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the matrix (3x3): \n");
                for (i=0; i<SIZE; i++)
                    for (j=0; j<SIZE; j++)
                    scanf("%d", &array[i][j]);
                break;
            case 2:
                printf("Enter two rows for swapping: \n");
                scanf("%d %d", &row1, &row2);
                swap2Rows(array, row1, row2);
                printf("The new array is: \n");
                display(array);
                break;
            case 3:
                printf("Enter two columns for swapping: \n");
                scanf("%d %d", &col1, &col2);
                swap2Cols(array, col1, col2);
                printf("The new array is: \n");
                display(array);
                break;
            case 4:
                display(array);
                break;
        }
    } while (choice < 5);
}

void display(int ar[][SIZE]) {
    int l,m;
    for (l = 0; l < SIZE; l++) {
        for (m = 0; m < SIZE; m++)
            printf("%d ", ar[l][m]);
        printf("\n");
    }
}

void swap2Rows(int ar[][SIZE], int r1, int r2) {
    int temp1[3];
    int temp2[3];

    for (int i=0; i<SIZE; i++){
        temp1[i] = ar[r1][i];
        temp2[i] = ar[r2][i];
    }

    for (int i =0; i<SIZE; i++){
        ar[r1][i] = temp2[i];
        ar[r2][i] = temp1[i];
    }

}
void swap2Cols(int ar[][SIZE], int c1, int c2) {
    int temp1[3];
    int temp2[3];

    for (int i=0; i<SIZE; i++){
        temp1[i] = ar[i][c1];
        temp2[i] = ar[i][c2];
    }

    for (int i=0; i<SIZE; i++){
        ar[i][c1] = temp2[i];
        ar[i][c2] = temp1[i];
    }

}

