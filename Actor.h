#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
class StudentWorld;
class Actor: public GraphObject{
public:
	Actor(int imageID, int startX, int startY, Direction dir, double size, unsigned int depth = 0)
	: GraphObject(imageID, startX, startY, dir, size, depth)
	{
		
	}
	int getMX() {
		return m_x;
	}
	virtual void doSomething() = 0;
	StudentWorld* getWorld() {

		return sw;
	}
private:
	int m_imageID;
	int m_x;
	int m_y;
	double m_size;
	int m_depth;
	int m_health;
	StudentWorld* sw;
};


class Person : public Actor {
public:
	Person(int imageID, int startX, int startY, Direction dir, double size, unsigned int depth = 0) 
	: Actor(imageID, startX, startY, dir, size, depth){
	}
	void movePersonLeft();
private:
	int m_imageID;
	int m_x;
	int m_y;
	double m_size;
	int m_depth;
	int m_health;
};
class IceMan : public Person {
public:
	IceMan(int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0)
		: Person(IID_PLAYER, 30, 30, right, 1.0, 0), m_x(30), m_y(30),
		m_size(1.0), m_depth(0), m_imageID(IID_PLAYER)
	{
	
	}
	~IceMan(){}
	IceMan(int x, int y, StudentWorld* thisWorld) 
		: Person(IID_PLAYER, x, y, right, 1.0, 0), sw(thisWorld)
		{
		this->setVisible(true);

		}
	void doSomething();
	bool playerFinishedLevel() { return false; }
private:
	int m_imageID;
	int m_x;
	int m_y;
	double m_size;
	int m_depth;
	StudentWorld* sw;

};
class Protestor : public Person {
private:
	int m_imageID = IID_PROTESTER;
};
class HardCoreProtestor : public Protestor {

private:
	int m_imageID = IID_HARD_CORE_PROTESTER;
};
class Ice : public Actor {
public:
	Ice(int x, int y, StudentWorld* thisWorld)
		: Actor(IID_ICE, x, y, right, .25, 3), sw(thisWorld) {
		this->setVisible(true);
	}

	void doSomething();
private:
	int m_imageID = IID_ICE;
	int m_x;
	int m_y;
	double m_size = .25;
	int m_depth = 3;
	StudentWorld* sw;

};
#endif ACTOR_H_
