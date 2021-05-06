#include "StudentWorld.h"
#include "GraphObject.h"
#include <string>
#include <iostream>
using namespace std;

int StudentWorld::init() {

	IceMan* player = new IceMan(30, 30, this);
	setPlayer(player);
	//Loop to create and store Ice*
	Ice* iceArr[4000] = { nullptr };
	Ice* iceArray = getIceArr();
	int k = 0;
	for (int i = 0; i < VIEW_WIDTH; i++) {
		for (int j = 0; j < VIEW_WIDTH - 4; j++) {
			if ((i<30 || i > 33) || (j<4)) {
				Ice* iceV = new Ice(i, j, this);
				iceArr[k] = iceV;
				k++;
			}
		}
	}


	return GWSTATUS_CONTINUE_GAME;
	
}
int StudentWorld::move(){
	setGameStatText("wo");
	int key;
	// player->doSomething();
	//if (player->getWorld()->getKey(key) == true) {
	//	switch (key) {
	//	case KEY_PRESS_LEFT:
	//		player->movePersonLeft();
	//		break;
	//	}
	//}
	 cout << player->getWorld()->getInt() << endl;

	cout << "GOOO" << endl;
	//player->doSomething();
	if (player->playerFinishedLevel())
		return GWSTATUS_FINISHED_LEVEL;
	
}
void StudentWorld::cleanUp() {

}


GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}


// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
void Initialize_the_game_world(){
}