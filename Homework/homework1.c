#include <stdio.h>

int main(){

    int c;
    int state = 0;
    int s;
    int i = 0;
    char strong[7]={"strong"};

    while((c = getchar()) != EOF){
        if(c == '<'){
        do{
           c = getchar();
        }
        while(c != EOF && c != '>');
    }else{
        putchar(c);
        }
    }
}