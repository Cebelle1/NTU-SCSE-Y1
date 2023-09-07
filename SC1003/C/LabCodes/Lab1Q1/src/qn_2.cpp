//Lab 1 Qn2
#include "qn_2.h"

qn_2::qn_2()
{

    int line;
    float total =0;
    float numb;
    int counter =0;
    float avg;
}

qn_2::~qn_2()
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
}


