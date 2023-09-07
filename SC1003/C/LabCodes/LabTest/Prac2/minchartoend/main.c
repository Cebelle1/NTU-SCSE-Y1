#include <stdio.h>
#include <string.h>
void minCharToEnd(char *str);
int main()
{
 char str[80];

 printf("Enter a string: \n");
 scanf("%s",str);
 minCharToEnd(str);
 printf("minCharToEnd(): %s",str);
 return 0;
}
void minCharToEnd(char *str)
{

    char smallest;
    int index;
    smallest = str[0];
    for (int i=0; str[i]!='\0';i++){
        if (smallest > str[i]){
            smallest = str[i];
            printf("%f",i);
            index = i;
        }
       // printf("%d",index);
    }
}
