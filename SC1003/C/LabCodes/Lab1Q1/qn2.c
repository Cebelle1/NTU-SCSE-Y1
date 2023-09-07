//Lab 1 Qn2
#include <stdio.h>
#include <stdlib.h>

int line;
float total =0;
float numb;
int counter =0;
float avg;

int main()
{
    printf("Enter number of lines: ");
    scanf("%d", &line);

    for (int i=0; i<line; i++){
            printf("%s %d %s", "Enter line", i+1, "(end with -1):");
            while(numb != -1){
                scanf("%f", &numb);
                if (numb != -1){
                    total += numb;
                    counter += 1;
                }
            }
        avg = total/counter;
        printf("%s %.2f \n", "Average = ", avg);
        numb =0;
    }
    return 0;
}
