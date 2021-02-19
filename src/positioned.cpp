#include "positioned.h"

Positioned::Positioned(unsigned int posX, unsigned int posY, char sprite)
	:_positionX(posX), _positionY(posY), _sprite(sprite)
{
}

Positioned::~Positioned()
{
}

void Positioned::newPositionX(unsigned int newPosition)
{
	_positionX = newPosition;
}

void Positioned::newPositionY(unsigned int newPosition)
{
	_positionY = newPosition;
}

void Positioned::newPosition(std::pair<unsigned int, unsigned int> newPosition)
{
	_positionX = newPosition.first;
	_positionY = newPosition.second;
}

unsigned int Positioned::getPositionX()
{
	return _positionX;
}

unsigned int Positioned::getPositionY()
{
	return _positionY;
}

std::pair<unsigned int, unsigned int> Positioned::getPosition()
{
	return std::pair<unsigned int, unsigned int>(_positionX, _positionY);
}

void Positioned::newSprite(char newSprite)
{
	_sprite = newSprite;
}

char Positioned::getSprite()
{
	return _sprite;
}
