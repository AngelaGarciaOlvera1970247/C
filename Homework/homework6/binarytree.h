#define MAX 80
typedef struct treenode {
  char* user;
  char* password; 

  struct treenode* leftChild;
  struct treenode* rightChild;
  unsigned int depth;
} node;

char linea[MAX], password[MAX], user[MAX];
int saca(); 
void get (char l[MAX],char p[MAX],char u[MAX]); 
node* insert(char* u, char* p, node* pos, int d);
void alpha(node* position); 
void delete(node* position, char* u, char* p, int* n); 

/* This program was made with the help of https://github.com/satuelisa/C/tree/main/Ch6, Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988) and
with the help of rulgamer07 */