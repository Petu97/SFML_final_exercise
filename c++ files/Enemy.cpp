#include "Object.h"
#include "MovementHandler.h"
#include <iostream>

class Enemy : public Object
{
	using Object::Object;
	bool isMoving = false;
	float SpawnX, SpawnY;
	float DirX, DirY;
	//The number of frames this enemy is going to move before changing directions
	int value;

public:

	void MoveEnemy()
	{
		if (!isMoving)
		{
			//Reset direction values
			DirX = 0;
			DirY = 0;
			//Randomizes direction and number of frames
			int x = rand() % 4;
			value = rand() % 120;
			isMoving = true;

			switch (x)
			{
			case 0:
				DirX = 2.5f;
				break;
			case 1:
				DirX = -2.5f;
				break;
			case 2:
				DirY = 2.5f;
				break;
			case 3:
				DirY = -2.5f;
				break;
			}
		}
		else if (isMoving)
		{
			//MovementHandler
			MoveChar(sprite, DirX, DirY);
			value -= 1;
			if (value <= 0)
			{
				isMoving = false;
			}
		}
	}
	
};
