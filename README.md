# tic-tac-toe

## Ce reprezintă proiectul.
Pune bazele pentru un joc tic-tac-toe.

## Care sunt regulile jocului.
Sunt doi jucători, care plasează X și O pe rând, pe o tabla (3x3). Sunt 2 cazuri de finisarea jocului: 

1. Unul din jucători câștigă dacă plasează într-o linie (verticală, orizontală sau diagonală) simbolul său.
2. Alt caz este dacă jucătorii nu plasează simbolurile într-o linie, atunci va fi remiză.

## Enumerarea tipurilor de date
'struct point' - reprezintă o coordonată pe tablă.

'enum Cell' - enumerația reprezintă starea unei celule (Goală, X, O).

'class Board' - clasa care reprezintă tabla de joc și conține logica de gestionare a jocului.

'class Player' - clasa care reprezintă jucătorul având un mark (X sau O).

'class GameEngine' - clasa care reprezintă logica jocului, mutările jucătorului și verificarea condițiilor de finalizare a jocului.
