#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_
#include "GameController.h"

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include <vector>


class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir)
		: GameWorld(assetDir)
	{

	}

	virtual int init();

	virtual int move();

	virtual void cleanUp();
	Ice*  getIceArr() {
		return iceArr[0];
	}
	void setIceArr(Ice* ice) {
		iceArr[0] = ice;
	}
	IceMan* getPlayer() {
		return player;
	}
	void setPlayer(IceMan* pl) {
		player = pl;
	}
	StudentWorld* getWorld() { return this; }
	int getString() { return 555; }
private:
	std::vector<Actor*>  actors;
	Ice* iceArr[4000];
	IceMan* player;
	
};

#endif  STUDENTWORLD_H_
