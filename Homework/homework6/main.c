/* Instructions to compile the code: 
First place this file main.c in the compiler.
Then another "leaf" is added for an additional file that is in this same folder called binarytree.h */

#include <stdio.h>
#include <string.h> // strstr
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower
#include "binarytree.h"

node* insert(char* u, char* p, node* pos, int d) {
  node* temp;
  if (pos == NULL) {
    pos = (node*)malloc(sizeof(node));
    pos->user = u;
    pos->password = p;
    pos->depth = d;
    printf ("User <%s> has been registered with password <%s>\n\n", u, p);

  } else {
    if (strcmp(pos->user, u) == 0) {
      if (pos->password!=NULL){
      printf("This user was already registered\n\n");
      }
      else{
          pos->password = p;
          printf ("User <%s> has been registered with password <%s>\n\n", u, p);
      }
    } else if (strcmp(pos->user, u)>0) { 
      temp = insert(u, p, pos->leftChild, d + 1);
      if (pos->leftChild == NULL) {
	pos->leftChild = temp;
      }
    } else if (strcmp(pos->user, u)<0){
      temp = insert(u, p, pos->rightChild, d + 1); 
      if (pos->rightChild == NULL) {
	pos->rightChild = temp;
      }
    }
  }
  return pos;
}

void alpha(node* position) {
  if (position != NULL) {
    alpha(position->leftChild);
    if (position->password!=NULL){
    printf("%s ", position->user);
    }
    alpha(position->rightChild);
  }
}

void delete(node* position, char* u, char* p, int* n){
    if (position != NULL) {
        
        delete (position->leftChild, u, p, n);
        delete (position->rightChild, u, p, n);
        if (strcmp(position->user, u) == 0 && strcmp(position->password, p) == 0){
            position->password=NULL;
            printf("Usuario %s eliminado\n\n", u);
            *n = 1;
        }
    }
}

int main() {
  extern char linea[];
  node* n = NULL;
  node* tree = NULL; 
  int i;
  int l = 0;
  char* u;
  char* p;
  int indicador=0;
  int contadorespacios =0; 
  int j;
  printf("To add a user use: add user password\n");
  printf("To delete a user use: user password\n");
  printf("To see the names of the users arranged alphabetically use: view\n");
  printf("Make sure your input is correct before hitting enter\n\n");
  while ((l = saca()) == 0) {
      contadorespacios=0;
    for (j=0; j<MAX; j++){
        if (linea[j]==' '||linea[j]=='\t'){
            contadorespacios++;
        }
    }
    if (strstr(linea, "del") != NULL && strlen(linea) >= 7 && contadorespacios ==2) { 
      get(linea, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++){
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++){
          p[i]=password[i];
      }
      
      indicador=0;
      delete(tree, u, p, &indicador);
      if (indicador==0){
          printf("It was not removed\n\n");
      }

      indicador=0;
      contadorespacios=0;
      
    }
    
    else if (strstr(linea, "add") != NULL&&strlen(linea)>=7&&contadorespacios==2) { 
      get(linea, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++){
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++){
          p[i]=password[i];
      }
      
      if (strlen(password) >0 && strlen(user) >0){
      n = insert(u,p, tree, 0); 
	  if (tree == NULL) {
	    tree = n; 
	    }
	   contadorespacios=0;
      }
      else if (strlen(password)<=0||strlen(user)<=0){
          printf ("Check your entry\n\n");
      }
    }
      
    else if (strstr(linea, "view") != NULL&&strlen(linea)==4) {
      alpha(tree);
      printf("\n\n");
      contadorespacios=0;
    }
    else{
        printf("Check your entry\n\n");
        contadorespacios=0;
    }
  }
  return 0;
}

int saca() { 
          
  extern char linea[];
  int c, i = 0;

  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) {

        linea[i++] = c;
  }
  
  linea[i] = '\0'; 
  return c == EOF;
}

void get (char l[MAX],char p[MAX],char u[MAX]){
    int a = 4, b = 0, c=0;
    while (l[a]!=' '&&l[a]!='\t'){
        u[b]=l[a];
        b++;
        a++;
    }
    u[b]='\0';
    int longitud = strlen(u);
    a++;
    while (l[a]!=' '&&l[a]!='\t'&&l[a]!='\0'){
       p[c]=l[a];
       c++;
       a++;
    }
    p[c]='\0';
    int longitud2 = strlen(p);
}

/* This program was made with the help of https://github.com/satuelisa/C/tree/main/Ch6, Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988) and
with the help of rulgamer07 */
