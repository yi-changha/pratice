// enum

#include <stdio.h>

enum EGameState {
	GAMESTATE_MAINMENU,
	GAMESTATE_PLAYING,
	GAMESTATE_PAUSED,
	GAMESTATE_GAMEOVER
};

int main() {
	int currState = GAMESTATE_MAINMENU;
	
	while (true) {
		switch (currState) {
		case GAMESTATE_MAINMENU:
			break;

		case GAMESTATE_PLAYING:
			break;

		case GAMESTATE_PAUSED:
			break;
		case GAMESTATE_GAMEOVER:
			break;
		}
	}
}