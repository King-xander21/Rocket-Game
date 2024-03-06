#include "Asteriod.h"

using namespace sf;
using namespace std;

//Asteriod::Asteriod(Texture& texture)
//{
//	rock.setTexture(texture);
//}

void Asteriod::setRockTexture(Texture& texture)
{
	rock.setTexture(texture);
}

void Asteriod::setSize(float sizeX, float sizeY)
{
	Vector2f targetSize(sizeX, sizeY);
	rock.setScale(targetSize.x / rock.getLocalBounds().width, targetSize.y / rock.getLocalBounds().height);

}

FloatRect Asteriod::getPosition() 
{
	return rock.getGlobalBounds();
}

void Asteriod::DrawAsteriod(RenderWindow& window)
{
	window.draw(rock);
}

void Asteriod::setPosition(float startX, float startY)
{
	Rock_position.x = startX;
	Rock_position.y = startY;
	rock.setPosition(Rock_position);
}

void Asteriod::setSpeed(float speedX)
{
	speed = speedX;
}

void Asteriod::moveLeft()
{
	movingleft = true;
}
bool Asteriod::findRockPos_x()
{
	return rock.getPosition().x;
}

bool Asteriod::findRockPos_y()
{
	return rock.getPosition().y;
}

bool Asteriod::getRockStatus()
{
	return movingleft;
}

void Asteriod::setRockStatus()
{
	movingleft = false;
}

float Asteriod::getx_Pos()
{
	return Rock_position.x;
}

float Asteriod::gety_Pos()
{
	return Rock_position.y;
}

int genRand()
{
	int value;
	value = rand() % 600;
	return value;
}

void Asteriod::update(Time dt)
{
	if (Asteriod::getx_Pos() > -70)
	{ 
		Rock_position.x -= speed * dt.asSeconds();
		rock.setPosition(Rock_position);
	}
	else
	{
		int randPos = genRand();
		Asteriod::setPosition(900, randPos-100);
	}
}

