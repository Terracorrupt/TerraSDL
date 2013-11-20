#include "Vector2.h"
#include "Debug.h"

Vector2::Vector2(float x2, float y2)
{
	x = x2;
	y = y2;
}

Vector2::~Vector2()
{

}

float Vector2::length()
{
	return sqrt(x * x + y * y);
}

float Vector2::getx() { return x; }
float Vector2::gety() { return y; }
void Vector2::setX(float x2) { x = x2; }
void Vector2::setY(float y2) { y = y2; }

Vector2 Vector2::addVector(Vector2* v)
{
	return Vector2(x + v->getx(), y + v->gety());
}

Vector2 Vector2::multVector(float f)
{
	return Vector2(x * f, y * f);
}






