#include <stdio.h> // Basic library for input and output
#include <stdlib.h> // Library for using rand()
#include <time.h> // Library for the use of time()
#include "craps.h" // Necessary functions
FILE * Casino; // Archive

// Offset functions
int lanzadado();
int saldo_inicial();
int apuesta();
int usuario();

// Enumeration constants that represent game status
enum status{CONTINUA, GANA, PIERDE};

// Ask for the opening balance
int saldo_inicial(){
    long saldo;

    printf("\n WELCOME TO THE GAME CRAPS!! \n");
    printf("\n");
    printf("\n Desired initial balance: $");
    scanf("%ld", &saldo);
    return saldo;
}

// Read file with initial casino balance Casino.txt
int saldo_casino_total(){
    long saldo_casino;
        Casino = fopen("Casino.txt","r"); // Open archive
     if (Casino==NULL) {
        printf("\n Error de archivo \n"); // If the program can't find the file 
     }
     else {
        while (feof(Casino)==0){
            fscanf(Casino, " %ld\n", &saldo_casino);
        }
     }
     fclose(Casino); // Close archive 
     return saldo_casino;
}

// Determine the money you want to bet
int apuesta(){
    int apuesta;
    int saldo;
    
    //It will ask the bet before starting to play
    printf("\n How much money do you want to bet?: \n");
    scanf("%d", &apuesta);
}

// Roll the dice, calculate the sum and display the results 
int lanzadado(void){
    int dado1, dado2, suma_tirada;
    dado1 = 1 + (rand() % 6); // Take random for dice1 
    dado2 = 1 + (rand() % 6); // Take random for dice2
    suma_tirada = dado1 + dado2; // Add dice1 and dice2 * /
    
    // Displays the results of this shot 
    printf("\n The player has obtained a score of %d + %d = %d ", dado1, dado2, suma_tirada);
    return suma_tirada; // Returns the sum of the dice 
}

int saldo_casino_final(int saldo_casino){ // Update the casino balance Casino.txt
    Casino = fopen ("Casino.txt", "a");
    if (Casino == NULL){
        printf("\n Error de archivo \n"); // If the program can't find the file 
    }else{
        fprintf(Casino,"%d\n", saldo_casino);
        printf("%d", saldo_casino);
    }
    fclose(Casino);
    return 0;
}

// The main function starts the execution of the program 
int main(void){
    int suma, mispuntos, apuesta, opcion; // Variables 
    int saldo_apostado;
    int estado_juego;
    long casino_saldo;
    long saldo;
    opcion = 1;
    
    casino_saldo = saldo_casino_total();
    saldo = saldo_inicial();
    
    printf("\n How much money do you want to bet?: $");
    scanf ("%d", &apuesta);
    srand (time (NULL)); // Randomizes the random number generator by using the time function
    
    if (apuesta > saldo){ // If the bet is less than the balance
        
        printf ("\n You don't have enough money \n"); // You place a bet greater than the balance
        printf ("\n Re-enter the bet: $"); // You have to bet again according to the balance
        scanf ("%d", &apuesta);
        suma = lanzadado ();
        saldo_apostado = apuesta;
        
        // Determines the status of the game based on the sum of the dice 
        switch(suma){
            
            // Wins on first roll 
            case 7: case 11: estado_juego = GANA;
            break;
            
            // Lose on first shot 
            case 2: case 3: case 12: estado_juego = PIERDE;
            break;
 
            // Remember the period 
            default: 
            estado_juego = CONTINUA; // Keep rolling the dices
            mispuntos = suma;
            printf("\n Your point is %d ", mispuntos); // Message of your point
            break; 
        }
        
        // As long as the game does not complete 
        while (estado_juego == CONTINUA){
            suma = lanzadado ();
            
            // Determines the status of the game 
            if(suma == mispuntos){ // Win by point 
                estado_juego = GANA; // Player wins 
            
            }else{
                if(suma == 7){ // Loses on rolling 7 
                    estado_juego = PIERDE; // Player loses
                }
            }
        }
        
        if(estado_juego == GANA){
            
            printf("\n"); // Space 
            printf("\n Congratulations!!! The player WINS \n"); // If you win
            printf("\n");
            saldo = saldo + apuesta; // The bet is added to the balance
            casino_saldo = casino_saldo - apuesta; //The house wins, the bet is subtracted
            printf("\n Your new balance is "); // It is the new balance when winning 
            printf("%ld\n", saldo);
            
        }else{
            
            // Shows the message of the winner or loser 
            printf("\n");
            printf("\n Sorry, the player LOSES ");
            printf("\n");
            saldo = saldo - apuesta; // The balance is subtracted from the bet
            casino_saldo = casino_saldo + apuesta; // The house wins, the bet is added
            printf("\n Your new balance is ");
            printf("%ld\n", saldo);
        }
        return 0;
    }
    else if(apuesta == 0){// If you bet zero
        
        printf ("\n ERROR: You have not placed your bet \n"); // Message ERROR
        printf ("\n Enter the bet again: $"); // Re-place bet
        scanf ("%d", &apuesta);
        
    }else(0 <= saldo); // If the bet is greater than or equal to the balance
        suma = lanzadado ();
        
        switch(suma){
            case 7: case 11: estado_juego = GANA;
            break;
            
            case 2: case 3: case 12: estado_juego = PIERDE;
            break;
 
            default: 
            estado_juego = CONTINUA;
            mispuntos = suma; // Roll the dice again 
            printf("\n Your point is %d ", mispuntos);
            break;
        }
        
        while (estado_juego == CONTINUA){
            suma = lanzadado ();
            // Determines the status of the game 
            if(suma == mispuntos){ // Win by point 
                estado_juego = GANA; // Player wins
            
            }else{ 
                if(suma == 7){ // Loses on rolling 7 
                    estado_juego = PIERDE; // Player loses
                }
            }
        }
        
        // Displays the message of the winner or loser
        if(estado_juego == GANA){
            
            printf("\n"); // Space 
            printf("\n Congratulations!!! The player WINS \n"); // If you win
            printf("\n");
            saldo = saldo + apuesta; // The bet is added to the balance
            casino_saldo = casino_saldo - apuesta; //The house wins, the bet is subtracted
            printf("\n Your new balance is "); // It is the new balance when winning 
            printf("%ld\n", saldo);
            
        }else{
            
            // Shows the message of the winner or loser 
            printf("\n");
            printf("\n Sorry, the player LOSES ");
            printf("\n");
            saldo = saldo - apuesta; // The balance is subtracted from the bet
            casino_saldo = casino_saldo + apuesta; // The house wins, the bet is added
            printf("\n Your new balance is ");
            printf("%ld\n", saldo);
        }
        printf("\n\n");
        saldo_casino_final(casino_saldo); // Casino balance
    }
    
/* 
Name: Angela Monserrat García Olvera
Career: Mechatronic Engineering
ID: 1970247
PIA: CRAPS 
*/