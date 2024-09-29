#include "gameEngine.hpp"
#include "player.hpp"
#include "board.hpp"

int main() {
	Player player1(X);
	Player player2(O);
	GameEngine gameEngine(player1, player2);

	gameEngine.Start();

	return 0;
}