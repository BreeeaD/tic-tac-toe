CC = g++ #numele compilatorului
CXXFLAGS = -O2 -std=c++20 #optiuni de compilare

SRC = tic-tac-toe.exe #fisierul executabil
OBJ = board.o player.o cell.o gameEngine.o point.o main.o #lista de obiecte 

all: $(SRC)

$(SRC): $(OBJ) #SRC care ii tic-tac-toe depinde de OBJ care sunt toate obiectele pentru crearea fisierelor.o
	$(CC) -o$(SRC) $(OBJ) 

%.o: %.cpp #compilarea fisierelor .cpp in cele .o
	$(CC) $(CXXFLAGS) -o $@ -c $<

clean: 
	rm -f *.o $(SRC)

