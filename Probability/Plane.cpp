#include "Plane.h"

using namespace sf;
using namespace std;

//void plane::setPlaneTexture()
//{
//	planeTexture.loadFromFile("resources/plane.png");
//	Plane.setTexture(planeTexture);
//}

plane::plane(float startX, float startY, Texture& texture)
{
	Plane.setTexture(texture);
	Position.x = startX;
	Position.y = startY;
	Plane.setPosition(Position);
	Vector2f targetSize(44.0f, 34.0f);
	Plane.setScale(targetSize.x / Plane.getLocalBounds().width, targetSize.y / Plane.getLocalBounds().height);
}

Vector2f plane::getPosition()
{
	//return Plane.getGlobalBounds();
	return Plane.getPosition();
}

void plane::DrawSprite(RenderWindow& window)
{
	window.draw(Plane);
}

void plane::moveUp()
{
	movingUp = true; // Craft is moving up
}

void plane::moveDown()
{
	movingDown = true; // Craft is moving down
}

void plane::Update(Time dt)
{
	if (movingDown == true)
	{
		Position.y += speed * dt.asSeconds();
	}
	if (movingUp == true)
	{
		Position.y -= speed * dt.asSeconds();
	}
	Plane.setPosition(Position);
}

void plane::stopUp()
{
	movingUp = false;
}

void plane::stopDown()
{
	movingDown = false;
}

bool plane::getPlaneStatusUp()
{
	return movingUp;
}

bool plane::getPlaneStatusDown()
{
	return movingDown;
}