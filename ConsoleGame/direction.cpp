#include "direction.h"

Direction reverseDirection(Direction toReverse)
{
	//checking does toReverse equal LEFT
	if (toReverse == Direction::LEFT)
		//returning RIGHT
		return Direction::RIGHT;

	//checking does toReverse equal UP
	else if (toReverse == Direction::UP)
		//returning DOWN
		return Direction::DOWN;

	//checking does toReverse equal RIGHT
	else if (toReverse == Direction::RIGHT)
		//returning LEFT
		return Direction::LEFT;

	//checking does toReverse equal DOWN
	else if (toReverse == Direction::DOWN)
		//returning UP
		return Direction::UP;
}
