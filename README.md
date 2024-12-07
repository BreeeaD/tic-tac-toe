# tic-tac-toe

## Descrierea proiectului
Tic-Tac-Toe în consolă implementată în Visual Studio în C++

## Regulile jocului
Sunt doi jucători, care plasează X și O pe rând, pe o tabla (3x3). Sunt 2 cazuri de finisarea jocului: 

1. Unul din jucători câștigă dacă plasează într-o linie (verticală, orizontală sau diagonală) simbolul său.
2. Alt caz este dacă jucătorii nu plasează simbolurile într-o linie, atunci va fi remiză.

## Dependențele:
* Mediu de dezvoltare: Proiectul a fost dezvoltat și testat folosind Visual Studio 2022, dar poate fi construit și utilizând Makefile.
* Biblioteca externă SQLite3(pentru gestionarea statisticii)
* MSVC Compiler

## Arhitectura jocului
1. Board: Reprezintă tabla de joc ca o matrice 3x3, cu funcții pentru a marca o poziție, a verifica câștigătorii și a verifica dacă tabla este plină.
2. Cell: Enumerează valorile posibile pentru celulele unei table de joc (G - gol, X - jucătorul 1, O - jucătorul 2).
3. GameEngine: Controlează logica jocului, gestionează turele jucătorilor, schimbă jucătorii și determină când jocul s-a încheiat.
4. Player: Reprezintă un jucător, inclusiv simbolul (X sau O) al acestuia și funcții pentru comparație, citire/afișare și obținerea simbolului.
5. Point: Reprezintă un punct pe tabla de joc cu coordonatele x și y, permițând comparații și operații de citire și afișare.
6. Statistic: Gestionază și stochează rezultatele jocurilor într-o bază de date SQLite, adăugând rezultate și afișând statistici.