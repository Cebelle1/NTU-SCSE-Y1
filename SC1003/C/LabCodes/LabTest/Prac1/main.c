#include <stdio.h>
#include <string.h>
void extractFirstChar(char *str1, char *str2);
int main()
{
 char str1[80], str2[80], *p;

 printf("Enter a string: \n");
 fgets(str1, 80, stdin);
 if (p=strchr(str1,'\n')) *p = '\0';
 extractFirstChar(str1, str2);
printf("extractFirstChar(): %s\n", str2);
 return 0;
}
void extractFirstChar(char *str1, char *str2)
{
    int x = 0;
    for (int i=0; i<strlen(str1);i++){

        if (i == 0 || str1[i-1]==' '){
            *(str2+x)=str1[i];
            x++;
        }
        str2[x]='\0';
    }
}
