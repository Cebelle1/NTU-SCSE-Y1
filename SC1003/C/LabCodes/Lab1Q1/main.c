//Lab 1
#include <stdio.h>
#include <stdlib.h>




int main()
{
    //qn_2();
    //qn_3();
    qn_4();
    return 0;
}

void qn_2(){
    int line;
    float total =0;
    float numb;
    int counter =0;
    float avg;

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

void qn_3(){
    int height;
    int outp=1;

    printf("Enter the height: ");
    scanf("%d",&height);
    for (int h=1; h<=height; h++){

        outp = (outp%4==0)?1:outp;

        for(int r=0; r<h; r++){
            printf("%d",outp);
        }

        outp+=1;

    printf("\n");
    }
}

void qn_4(){
    float outp = 1;
    float sum_fact=1;
    float x;
    printf("%s", "Enter x:");
    scanf("%f", &x);


    for (int exp=1; exp<=10; exp++){
        //Factorial each loop
        for (int fact=0; fact<x; fact++){
            sum_fact += sum_fact*fact;

        }
        printf("%f \n", sum_fact);
        outp += x/sum_fact;
    }
    printf("%s %f","Result: ",outp);
}
