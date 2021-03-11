#include <stdio.h>  
#include <ctype.h> 

#define OUT 0
#define IN 1

int main() {
	int c;
	int parenthesis, brackets, braces, single_q, double_q;
	int last_digit = OUT;
	parenthesis = brackets = braces = single_q = double_q = 0;
	int ignore = 0;

	while((c = getchar()) != EOF) {
		ignore = 0;
		switch (c) {
			case '(':
				parenthesis++;
				break;
			case '[':
				brackets++;
				break;
			case '{':
				braces++;
				break;
			case ')':
				parenthesis--;
				break;
			case ']':
				brackets--;
				break;
			case '}':
				braces--;
				break;
			case '\'':
				single_q = !single_q;
				break;
			case '\"':
				double_q = !double_q;
				break;
			case '.':
				ignore = 1;
				break;
			case ',':
				ignore = 1;
				break;
			case ';':
				ignore = 1;
				break;
		}
		if (ignore) {
			continue;
		}
		if ((!parenthesis) && (!brackets) && (!braces) && (!single_q) && (!double_q)) {
			if (!isdigit(c) && last_digit == IN) {
				putchar('X');
				last_digit = OUT;
			}
			isdigit(c) ? last_digit = IN : putchar(c);
		}
		else {
			putchar(c);
		}
	}
}

/* INPUT:
(HOLA)123d
[HOLA]123d
{HOLA}123d
'HOLA'123d
"HOLA"123d
H.O.L.A
H,O,L,A
H;O;L;A

OUTPUT: 
(HOLA)Xd
[HOLA]Xd
{HOLA}Xd
'HOLA'Xd
"HOLA"Xd
HOLA
HOLA
HOLA */

/* Task carried out with the help of Hector Mauricio Flores Martinez 
Brian W. Kernighan & Dennis M. Ritchie. (1988). 
The programming language C. United States of America : PRENTICE HALL .*/