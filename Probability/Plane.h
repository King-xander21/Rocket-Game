#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class plane
{
public:
	plane(float startX, float startY, Texture& texture);
	//void setPlaneTexture();
	Vector2f getPosition();
	void DrawSprite(RenderWindow& window);
	void moveUp();
	void moveDown();
	void stopUp();
	void stopDown();
	void Update(Time dt);
	bool getPlaneStatusUp();
	bool getPlaneStatusDown();

private:
	float speed = 300.0f;
	bool movingUp = false; // Craft not moving up
	bool movingDown = false; // Craft not moving down
	Vector2f Position;
	//RectangleShape R_shape;
	Sprite Plane;
	//Texture planeTexture;
};