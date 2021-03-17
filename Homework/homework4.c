#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MVAL 100
#define NUMBER '0' 
double  Atof(char *pstr);
double pop();
void push();
int getop(char *cNumber);
 
int main(){
    char cNumber[MVAL];
    int nPos = 0;
    char type;
    while( (type = getop(cNumber)) != EOF ){
        switch(type){
            case NUMBER:{
                push(Atof(cNumber));
                break;
            }
            case '+':
            {
                push(pop() + pop());
                break;
            }
            case '*':
            {
                push(pop() * pop());
                break;
            }
            case '-':
            {
                double nTmp = pop();
                push(pop() - nTmp);
                break;
            }
            case '/':
            {
                double nTmp = pop();
                push(pop() / pop());
                break;
            }
            case '\n':
            {
                printf("%lf", pop());
                break;
            }
            default:
            {
                printf("THIS IS NOT A NUMBER OR OPERATOR");
                break;
            }
        }
    }
    return 0;
}
double  Atof(char *pstr)
{
    int i = 0;
    int j = 0;
    double dNumber = 0;
    int sign = 0;
    double power = 1;
 
    for(; isspace(pstr[i]);i++);
         sign = (pstr [i] == '-')? -1: 1; 
 
    if(pstr[i] == '-' || pstr[i] == '+'){
        i++;
    }
 
    for(; pstr[i] != '.' && pstr[i] != '\0'; i++){
        dNumber = (pstr[i] - '0') + dNumber * 10;
 
    }
    if(pstr[i] == '.'){
        i++;
    }else{
        return sign * dNumber;
    }
    for(; pstr[i] != '\0'; i++){
        dNumber = (pstr[i] - '0') + dNumber * 10;
        power *= 10;
    }
    dNumber = dNumber / power;
    return sign * dNumber;
}
#define MAXVAL 100
 double val [MAXVAL]; 
 int valpos = 0; 
 
void push(double number){
    if(valpos >= 100){
        printf("THE VAL CAN'T PUSH");
    }else{
        val[valpos++] = number;
    }
}
 
double pop(){
    if(valpos <= 0){
        printf("THE VAL HAVEN'T ANY NUMBER");
    }else{
        return val[--valpos];
    }
}
char getch();
void ungetch(char c);

int getop(char *cNumber){
         int nPos = 0;
    char c = '0';
    while( (cNumber[0] = c = getch()) == ' ' || c ==  '\t' );
    if( !isdigit(c))
        return c;
    if(isdigit(c)){
        while(isdigit(cNumber[++nPos] = c = getch( )));
        }
    if(cNumber[nPos] == '.'){
        while(isdigit(cNumber[++nPos] = c = getch()));
    }
    cNumber[nPos] = '\0';
    return NUMBER;
}
#define MAXBUFSIZE 100
 
int strpos = 0;
char str [MAXBUFSIZE];
char getch(){
    if(strpos <= 0){
        return getchar();
    }else{
        return str[--strpos];
    }
}
void ungetch(char c){
    if(strpos >= 100){
        printf("THE STRPOS IS FULL");
    }else{
        str[strpos++] = c;
    }
}
