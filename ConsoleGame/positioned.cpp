#include "positioned.h"

Positioned::Positioned(unsigned int posX, unsigned int posY, char sprite)
	:m_positionX(posX), m_positionY(posY), m_sprite(sprite)
{
}

Positioned::~Positioned()
{
}

void Positioned::newPositionX(unsigned int newPosition)
{
	m_positionX = newPosition;
}

void Positioned::newPositionY(unsigned int newPosition)
{
	m_positionY = newPosition;
}

void Positioned::newPosition(std::pair<unsigned int, unsigned int> newPosition)
{
	m_positionX = newPosition.first;
	m_positionY = newPosition.second;
}

unsigned int Positioned::getPositionX()
{
	return m_positionX;
}

unsigned int Positioned::getPositionY()
{
	return m_positionY;
}

std::pair<unsigned int, unsigned int> Positioned::getPosition()
{
	return std::pair<unsigned int, unsigned int>(m_positionX, m_positionY);
}

void Positioned::newSprite(char newSprite)
{
	m_sprite = newSprite;
}

char Positioned::getSprite()
{
	return m_sprite;
}
