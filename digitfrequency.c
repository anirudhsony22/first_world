#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int res[10]={0},j=0;
    char num[1000];
    scanf("%s",num);
    for(int i=0;i<strlen(num);i++){
        if(num[i]>='0' && num[i]<='9'){
            char b=num[i];
            //printf("%c\n",b);
            j=atoi(&b);
            printf("%d\n",j);
            res[j]+=1;
            j = 0;

        }
    }
    for(int i=0;i<10;i++){
    printf("%d ",&res[i]);
    }
    return 0;
}