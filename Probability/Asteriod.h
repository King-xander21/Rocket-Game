#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Asteriod
{
public:
	//Asteriod(Texture& texture);
	FloatRect getPosition();
	void setRockTexture(Texture& texture);
	void DrawAsteriod(RenderWindow& window);
	void setPosition(float startX, float startY);
	void setSize(float sizeX, float sizeY);
	void setSpeed(float speedX);
	void moveLeft();
	void update(Time dt);
	bool findRockPos_x();
	bool findRockPos_y();
	bool getRockStatus();
	void setRockStatus();
	float getx_Pos();
	float gety_Pos();
private:
	Vector2f Rock_position;
	Sprite rock;
	// at this point, the rock is not moving.
	bool movingleft = false; // bool movingleft = 0
	float speed =0;
};