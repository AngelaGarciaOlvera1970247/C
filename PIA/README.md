# Final project (PIA): CRAPS 
The most popular game of chance in casinos is the dice game known as "Craps", which consists of placing different bets on the result found by rolling two dice in the next roll or in an entire round.

## DEMO
To access to the demo (YouTube video) of the previously described program:

Link to the video [here](https://youtu.be/aG55-E5CS5g)

### EVALUATION 
Final evaluation criteria from my perspective, are the following:

1.- Complexity (2 pts): The program is not entirely complex but it is not trivial either, it contains the necessary notebooks as is postulated in the C Reference Card (ANSI).

2.- Functionality (3 pts): It is executed in a careful way, it is practical and comfortable to use; an important point is that it does not generate errors.

3.- Code (3 pts): The code is clean, it contains comments regarding the functionality corresponding to each part of its structure and is easy to view.

4.- Storage (2 pts): It is not complicated, you can generate as many values as you like while you are using it.

5.- Documentation (3 pts): Finally, the README.md contains the important points of the code and theme as a whole. Spelling is fine, the video is not of the best quality but it does its job.

CF 13 of 15

## HOW TO PLAY?
A player rolls 2 dice with 6 faces each and the faces contain 1, 2, 3, 4, 5, and 6 points. Once the dice have stopped, the sum of the points on the two upper faces is calculated to establish whether it has been won or lost according to the following:

### There are two ways to win:
- Obtaining a score of 7 or 11 on the first throw.
- Obtaining a score of 4, 5, 6, 8, 9 or 10 in the first thrown, then said sum becomes the "point" or the "Compulsory shot", and the player must continue rolling the dice to achieve the same "point" again, before getting a 7 on a later roll.

### There are also two ways to lose:
- Roll the dice once and get 2, 3 or 12 (known as "Craps"), that is, the house "wins".
- Roll 4, 5, 6, 8, 9 or 10 on the first throw and roll a 7 on the subsequent throw before repeating the original “point”.

## COMPILER 
You can make use of the compiler [OnlineGDB](https://www.onlinegdb.com/) to execute the project code. 

## PLAY
- Once you run the program, the welcome will appear, in the same way it will ask you to enter the initial balance you want before starting the game. 

<img src="screens/1.png">

- Then you must enter the bet based on the initial balance that you first placed and automatically the program will start the game "Craps". 

<img src="screens/2.png">

If the bet is less than the initial balance, this will start the game "Craps".

<img src="screens/3.png">

If the bet is greater than the initial balance, the message will be displayed where it will ask you again the amount you are going to bet according to the limit imposed by the initial balance, and automatically the program will start the game "Craps". 

<img src="screens/4.png">

- And at the end of it, the new balance will appear depending on whether you win or lose based on the aforementioned rules.

<img src="screens/5.png">

## STRUCTURE OF COMPILING 
Place the files in the aforementioned compile as follows:
- craps.c
- craps.h 
- casino.txt 

NOTE: In the file "Casino.txt" we completely place, is to create a new file by pressing ctrl + m and place the name of it as is.

## ARCHIVE "Casino.txt"
It will contain all the balances obtained in each of the games, and it will also add up as you go from game to game. If you no longer like to play; In the file you will be able to see how much is the lost balance, which later you will want to decrease based on all the games won or that you plan to win to reach zero.

## REFERENCES
1.- Kernighan, B. W., & Ritchie, D. M. (1973). The C Programming Language (2.a ed.) [Electronic Book]. Prentice Hall. http://cslabcms.nju.edu.cn/problem_solving/images/c/cc/The_C_Programming_Language_%282nd_Edition_Ritchie_Kernighan%29.pdf

2.- Silverman, J. H. (2007, 15 Jan). The C Reference Card (ANSI). CRefCardVolume2. https://www.math.brown.edu/johsilve/ReferenceCards/CRefCard.v2.2.pdf

3.- Archivos de texto en Lenguaje C - Abrir, cerrar, leer y agregar ficheros txt (2020, 11 November). https://www.youtube.com/watch?v=RfNxPF8rlWI&t=231s

4.- Learning C Language - About Problems Error, Exception and Warning (2017, 19 November). https://www.youtube.com/watch?v=-tg2utFwjVs

5.- Programación en C - Lectura de archivos (2014, 23 June). https://www.youtube.com/watch?v=PPK28h5TmHc&t=653s


## PERSONAL DATA 
- Name: Angela Monserrat García Olvera 
- Career: Mechatronics Engineering
- Subject: Structured Programming
- ID: 1970247

## LICENSE
This project is under the License [GitHub](https://github.com/AngelaGarciaOlvera1970247)
