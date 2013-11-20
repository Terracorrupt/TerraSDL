#ifndef VECTOR2
#define VECTOR2

#include <math.h>

class Vector2
{
public:
	Vector2(float,float);
	~Vector2();
	float getx();
	float gety();
	void setX(float);
	void setY(float);
	float length();
	Vector2 addVector(Vector2*);
	Vector2 multVector(float);
private:
	float x;
	float y;
};
#endif