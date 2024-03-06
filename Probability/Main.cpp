#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plane.h"
#include "Asteriod.h"

using namespace sf;
using namespace std;

int i;

//int genRand();

int main()
{
	// Creating the videomode object
	VideoMode vm(800, 600);

	// Rendering the window
	RenderWindow window(vm, "Game");

	// Creating a texture for the plane Sprite
	Texture texture;
	texture.loadFromFile("resources/plane.png");

	// Creating a texture for the rock Sprite
	Texture rockTexture;
	rockTexture.loadFromFile("resources/rock.png");

	// Crating the charater objects
	plane MyPlane(60, 300, texture); 
	//Asteriod rock(rockTexture);
	//Asteriod rock;

	////// Defining the rock properties
	//rock.setSize(692, 644); // Scaled size from the original by 10
	//rock.setPosition(100, 200);
	//rock.setRockTexture(texture);

	Asteriod rock[8];
	float x_pos = 600, y_pos = 5;

	float speed = 170.0f;

	for (int i = 0; i < 8; i++)
	{
		
		rock[i].setRockTexture(rockTexture);
		rock[i].setSize(192, 144);
		//rock[i].setPosition(x_pos, y_pos);
	}
	
	rock[0].setPosition(x_pos, y_pos);
	rock[1].setPosition(x_pos + 100, y_pos + 100);
	rock[2].setPosition(x_pos + 200, y_pos);
	rock[3].setPosition(x_pos + 300, y_pos);
	rock[4].setPosition(x_pos + 100, y_pos);
	rock[5].setPosition(x_pos + 150, y_pos + 130);
	rock[6].setPosition(x_pos + 200, y_pos);
	rock[7].setPosition(x_pos + 300, y_pos);
	
	cout << "rock[0] x_pos: " << rock[0].getx_Pos() << endl;
	cout << "rock[1] x_pos: " << rock[1].getx_Pos() << endl;
	cout << "rock[2] x_pos: " << rock[2].getx_Pos() << endl;
	cout << "rock[3] x_pos: " << rock[3].getx_Pos() << endl;
	cout << "rock[4] x_pos: " << rock[4].getx_Pos() << endl;
	cout << "rock[5] x_pos: " << rock[5].getx_Pos() << endl;
	cout << "rock[6] x_pos: " << rock[6].getx_Pos() << endl;
	cout << "rock[7] x_pos: " << rock[7].getx_Pos() << endl;
	

	//rock[1].setPosition(100, 250);

	// The clock variable to control all time
	Clock clock;

	// The main loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				// Quit the game when the window is closed
				window.close();
			}
		}

		MyPlane.stopDown();
		// If the arrow key is pressed down
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			MyPlane.moveDown();
			
			//MyPlane.getPosition();
			//cout << MyPlane.getPosition().y << "\n";
			//cout << "Down key is pressed \n";
		}
		else
		{
			MyPlane.stopDown();
		}

		MyPlane.stopUp();
		// If the arrow key is pressed up
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			MyPlane.moveUp();
		}
		else
		{
			MyPlane.stopUp();
		}

		// Rock movement algorithm
		/* The Rocks spawn at a random point in the LHS of the window, then moves to the 
		RHS of the window*/

		// Quite Simple innit 
		/*
			</>
				1> Spawn Rock at random point in the LHS 
				2> Move Rock to the -x axis of the window CHECKED
				3> If the Rock position == the starting x-axis of the window, Repeat 1.
			</>
		*/
		//rock[0].setSpeed(170);
		//cout << "\n rock Status " << rock[0].getRockStatus() << "\n";
		//cout << " rock2 Status " << rock[1].getRockStatus() << "\n";
		/*
		*
		* 
		* MOVING THE ROCK
		*
		*
		*/
		rock[0].setSpeed(speed);
		rock[1].setSpeed(speed);
		rock[2].setSpeed(speed);
		rock[3].setSpeed(speed);
		rock[4].setSpeed(speed);
		rock[5].setSpeed(speed);
		rock[6].setSpeed(speed);
		rock[7].setSpeed(speed);

		rock[0].setRockStatus();
		if (rock[0].getx_Pos() > 0)
			{
				rock[0].moveLeft();
			    //cout << "rock[0] x_pos: " << rock[0].getx_Pos() << endl;
				//cout << " rock Status after "<< rock[0].getRockStatus()<< endl;
				//cout << "rock[0] position " << rock[0].getx_Pos();
			}
		else if (rock[0].getx_Pos() <= -70)
			{
				//cout << "rock[0] position " << rock[0].getx_Pos();
				rock[0].setRockStatus();
				//cout << " rock Status after " << rock[0].getRockStatus() << endl;
			}

		//rock[1].setSpeed(170);
			//cout << "\n rock Status " << rock[0].getRockStatus() << "\n";
			//cout << " rock2 Status " << rock[1].getRockStatus() << "\n";

		rock[1].setRockStatus();
		if (rock[1].getx_Pos() > 0)
		{
			rock[1].moveLeft();
			//cout << " rock Status after "<< rock[0].getRockStatus()<< endl;
			//cout << "rock[0] position " << rock[1].getx_Pos();

		}
		else if (rock[1].getx_Pos() <= -70)
		{
			//cout << "rock[1] position " << rock[1].getx_Pos();
			rock[1].setRockStatus();
			//cout << " rock Status after " << rock[1].getRockStatus() << endl;
		}

		rock[2].setRockStatus();
		if (rock[2].getx_Pos() > 0)
		{
			rock[2].moveLeft();
			//cout << " rock Status after "<< rock[0].getRockStatus()<< endl;
			//cout << "rock[0] position " << rock[0].getx_Pos();

		}
		else if (rock[2].getx_Pos() <= -70)
		{
			//cout << "rock[0] position " << rock[0].getx_Pos();
			rock[2].setRockStatus();
			//cout << " rock Status after " << rock[0].getRockStatus() << endl;
		}

		rock[3].setRockStatus();
		if (rock[3].getx_Pos() > 0)
		{
			rock[3].moveLeft();
			//cout << " rock Status after "<< rock[0].getRockStatus()<< endl;
			//cout << "rock[0] position " << rock[0].getx_Pos();

		}
		else if (rock[3].getx_Pos() <= -70)
		{
			//cout << "rock[0] position " << rock[0].getx_Pos();
			rock[3].setRockStatus();
			//cout << " rock Status after " << rock[0].getRockStatus() << endl;
		}

		rock[4].setRockStatus();
		if (rock[4].getx_Pos() > 0)
		{
			rock[4].moveLeft();
			//cout << " rock Status after "<< rock[0].getRockStatus()<< endl;
			//cout << "rock[0] position " << rock[0].getx_Pos();

		}
		else if (rock[4].getx_Pos() <= -70)
		{
			//cout << "rock[0] position " << rock[0].getx_Pos();
			rock[4].setRockStatus();
			//cout << " rock Status after " << rock[0].getRockStatus() << endl;
		}

		rock[5].setRockStatus();
		if (rock[5].getx_Pos() > 0)
		{
			rock[5].moveLeft();
			//cout << " rock Status after "<< rock[0].getRockStatus()<< endl;
			//cout << "rock[0] position " << rock[0].getx_Pos();
		}
		else if (rock[5].getx_Pos() <= -70)
		{
			//cout << "rock[0] position " << rock[0].getx_Pos();
			rock[5].setRockStatus();
			//cout << " rock Status after " << rock[0].getRockStatus() << endl;
		}

		rock[6].setRockStatus();
		if (rock[6].getx_Pos() > 0)
		{
			rock[6].moveLeft();
			//cout << " rock Status after "<< rock[0].getRockStatus()<< endl;
			//cout << "rock[0] position " << rock[0].getx_Pos();
		}
		else if (rock[6].getx_Pos() <= -70)
		{
			//cout << "rock[0] position " << rock[0].getx_Pos();
			rock[6].setRockStatus();
			//cout << " rock Status after " << rock[0].getRockStatus() << endl;
		}

		rock[7].setRockStatus();
		if (rock[7].getx_Pos() > 0)
		{
			rock[7].moveLeft();
			//cout << " rock Status after "<< rock[0].getRockStatus()<< endl;
			//cout << "rock[0] position " << rock[0].getx_Pos();
		}
		else if (rock[7].getx_Pos() <= -70)
		{
			//cout << "rock[0] position " << rock[0].getx_Pos();
			rock[7].setRockStatus();
			//cout << " rock Status after " << rock[0].getRockStatus() << endl;
		}
	
		speed = speed + 0.00020;
		cout << "Speed: " << speed<<"\n";
		
		/*
		*
		* MOVING THE ROCK
		*/
		
		

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		Time dt = clock.restart();
		MyPlane.Update(dt);
		/*for (i = 0; i < 8; i++)
		{
			rock[i].update(dt);
		}*/
		rock[0].update(dt);
		rock[1].update(dt);
		rock[2].update(dt);
		rock[3].update(dt);
		rock[4].update(dt);
		rock[5].update(dt);
		rock[6].update(dt);
		rock[7].update(dt);
		window.clear();
		// Drawing the characters
		MyPlane.DrawSprite(window);
		/*for (int i = 0; i<8; i++)
		{ 
			rock[i].DrawAsteriod(window);
		}*/
		rock[0].DrawAsteriod(window);
		rock[1].DrawAsteriod(window);
		rock[2].DrawAsteriod(window);
		rock[3].DrawAsteriod(window);
		rock[4].DrawAsteriod(window);
		rock[5].DrawAsteriod(window);
		rock[6].DrawAsteriod(window);
		rock[7].DrawAsteriod(window);

		// Displaying the window
		window.display();
	}
	return 0;
}
