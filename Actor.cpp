#include "Actor.h"
#include "StudentWorld.h"
void Person::movePersonLeft() {
	m_x--;
}
void Ice::doSomething() {

}
void IceMan::doSomething() {
	int in;

	if (getWorld()->getKey(in) == true) {
		switch (in) {
		case KEY_PRESS_LEFT:
			movePersonLeft();
			break;
		}
	}
}