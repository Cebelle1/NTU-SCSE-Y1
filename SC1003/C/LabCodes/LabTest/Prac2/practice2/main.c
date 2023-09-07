#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int dec;
    int rem;
    int i=0;
    int ans[3];
    printf("Enter a decimal number:\n");
    scanf("%d",&dec);

    while (rem != dec){
        rem = dec%8;
        dec = dec/8;
        ans[i] = rem;
        i+=1;
    }
    printf("The equivalent octal number: ");
    for (int x=2;x>=0;x--){
        if (ans[x]!=0){
             printf("%d",ans[x]);
        }
    }

    return 0;
}
