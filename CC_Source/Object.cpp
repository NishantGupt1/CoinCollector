#include "Object.h"
#include <SDL.h>

bool Object::collidesWith(Object* other)
{

	if(other->x + other->sizeX < x)	return false;	//just checking if their
	if(other->x > x+sizeX)	return false;	//bounding boxes even touch

	if(other->y + other->sizeY < y)	return false;
	if(other->y > y + sizeY)	return false;

	return true;
}