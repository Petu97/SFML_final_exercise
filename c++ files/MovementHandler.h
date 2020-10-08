#pragma once
#include "Object.h"

//Abstract functions, no need to initialize handler
bool CheckBoundaries(sf::Sprite o);
void MoveChar(sf::Sprite& o, float ver, float hor);

