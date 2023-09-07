#include <stdio.h>
#include <stdlib.h>

int main()
{
    int height =0;
    int row, col =0;
    int star,equal =1;
    printf("Enter the height:\n");
    scanf("%d",&height);

    row = height;
    col = height;
    printf("The pattern is:\n");
    for (int i=1; i<=col; i++){
        for (int j=1; j<=row-i; j++){
            printf("*");
        }
        for (int k=1; k<=i; k++){
            printf("=");
        }
        printf("\n");
    }
    return 0;
}
