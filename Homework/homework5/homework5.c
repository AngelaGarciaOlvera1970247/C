/*
This is the code you'll run, of course with the other.
Run the code and the game will start
Insert a raw and columns like A1,B4,C3 etc.
*/
#include <assert.h>                            
#include <ctype.h>   
#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  

#define mistake_founded_mine 1
#define mistake_founded_space 2
#define mistake_any 3

#define columns 10
#define rows 10

#define no_discovered_space '#'
#define yes_discovered_space ' '

#define mine '*'
#define mines_quant 15
#define debug 0  


int getCloseMines(int fila, int columna, char tablero[rows][columns]){       //**Credits to Montserrat Orozco**//
    
  int conteo = 0, filaInicio, filaFin, columnaInicio, columnaFin;
  if (fila <= 0) {
    filaInicio = 0;
  } 
  
  else {
    filaInicio = fila - 1;
  }

  if (fila + 1 >= rows){
    filaFin = rows - 1;
  }
  
  else {
    filaFin = fila + 1;
  }

  if (columna <= 0) {
    columnaInicio = 0;
  } 
  
  else {
    columnaInicio = columna - 1;
  }
  
  if (columna + 1 >= columns) {
    columnaFin = columns - 1;
  } 
  
  else{
    columnaFin = columna + 1;
  }
  
int f;
    for (f = filaInicio; f <= filaFin; f++){
      
  int c;
    for (c = columnaInicio; c <= columnaFin; c++) {
        
    if (tablero[f][c] == mine){
        conteo++;
      }
    }
  }
  
  return conteo;
}


int randomRange (int minim, int maxim){                                                                   
  return minim + rand() / (RAND_MAX / (maxim - minim + 1) + 1);
}


       void startTab(char tablero[rows][columns]){
    
int c;
  for (c = 0; c < rows; c++){
      
int f;
    for (f = 0; f < columns; f++){
      tablero[c][f] = no_discovered_space;
    }
  }
}


       void putMine(int fila, int columna, char tablero[rows][columns]) {
  tablero[fila][columna] = mine;
}


       void putMineRand(char tablero[rows][columns]){
    
int c;
  for (c = 0; c < mines_quant; c++) {
    int fila = randomRange(0, rows - 1);
    int columna = randomRange(0, columns - 1);
    putMine(fila, columna, tablero);
  }
}

        void printHeadSep(){
    
int f;
  for (f = 0; f <= columns; f++) {
    printf("----");
    if (f + 2 == columns){
      printf("-");
    }
  }
    printf("\n");
}

       void printRowsSep() {
    
int f;
  for (f = 0; f <= columns; f++){
    printf("+---");
  if (f == columns){
      printf("+");
    }
  }
    printf("\n");
}

        void printHead(){
  printHeadSep();
  printf("|   ");
  
int c;
  for (c = 0; c < columns; c++){
    printf("| %d ", c + 1);
  if (c + 1 == columns){
      printf("|");
    }
  }
      printf("\n");
}

            char wholeACharac(int numero){
  return numero + '0';
}

            void printTab(char tablero[rows][columns], int mustShowMines){
  printHead();
  printHeadSep();
  char letra = 'A';
int c;
  for (c = 0; c < rows; c++) {
int f;
    printf("| %c ", letra);
    letra++;
    for (f = 0; f < columns; f++) {
      
      char verdaderaLetra = no_discovered_space;
      char letraActual = tablero[c][f];
      
      if (letraActual == mine)
      {
        verdaderaLetra = no_discovered_space;
      } 
      
      else if (letraActual == yes_discovered_space)
      {
        int minasCercanas = getCloseMines(c, f, tablero);
        verdaderaLetra = wholeACharac(minasCercanas);
      }
      
      if (letraActual == mine && (debug || mustShowMines))
      {
        verdaderaLetra = mine;
      }
      printf("| %c ", verdaderaLetra);
      
      if (f + 1 == columns) 
      {
        printf("|");
      }
    }
    printf("\n");
    printRowsSep();
  }
}

      int openBx(char filaLetra, int columna, char tablero[rows][columns]){
  
  filaLetra = toupper(filaLetra);
  columna--;
  
int fila = filaLetra - 'A';
  assert(columna < columns && columna >= 0);
  assert(fila < rows && fila >= 0);
  
  if (tablero[fila][columna] == mine){
    return mistake_founded_mine;
  }
  
  if (tablero[fila][columna] == yes_discovered_space){
    return mistake_founded_space;
  }
  
  tablero[fila][columna] = yes_discovered_space;
  return mistake_any;
}

      int noUnopenedBxs(char tablero[rows][columns]){
  
int c;
  for (c = 0; c < rows; c++){
    int f;
    for (f = 0; f < columns; f++) {
      char actual = tablero[c][f];
      
    if (actual == no_discovered_space) {
        return 0;
      }
    }
  }
  return 1;
}

    int main(){
  printf("B U S C A M I N A S\nBUENA SUERTE EN ESTA PARTIDA!\n\n");
  char tablero[rows][columns];
  int mustShowMines = 0;
  
  srand(getpid());
  startTab(tablero);
  putMineRand(tablero);

  while (1){
    printTab(tablero, mustShowMines);
    if (mustShowMines){
      break;
    }
    
    int columna;
    char fila;
    printf("Ingresa la fila a seleccionar: ");
    scanf(" %c", &fila);
    printf("Ingresa la columna a seleccionar: ");
    scanf("%d", &columna);
    int status = openBx(fila, columna, tablero);
    
    if (noUnopenedBxs(tablero)){
      printf("¡Eres Ganador de esta gran partida!\n");
      mustShowMines = 1;
    } 
    
    else if (status == mistake_founded_space){
      printf("Ups, ya has abierto esta casilla, intentarías de nuevo, ¿por favor?\n");
    } 
    
    else if (status == mistake_founded_mine){
      printf("Perdiste esta partida:(, ¿intentas de nuevo? ¡Tu puedes!\n");
     mustShowMines = 1;
    }
  }
  return 0;
}