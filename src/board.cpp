#include "Board.h"

#ifdef CURSES_AVAILABLE
#include <algorithm>
#include <time.h>


Board::Board(unsigned int sizeX, unsigned int sizeY, char spaceChar, bool addFrames, bool replaceSpaceByFrame, char frameChar)
	:_frames(addFrames), _space(spaceChar), _frame(frameChar)
{
	//Greating value to avoid problems
	if (sizeX < 2) sizeX = 2;
	if (sizeY < 2) sizeY = 2;

	if (addFrames && replaceSpaceByFrame)
	{
		if (sizeX < 4) sizeX = 4;
		if (sizeY < 4) sizeY = 4;
	}

	//Setting _sizes
	_sizeX = sizeX;
	_sizeY = sizeY;

	//Preparing to make board
	_gamePool = new vector<vector<char>*>();

	//Declarating lambda that will help loops
	auto replaceSpace = [addFrames, replaceSpaceByFrame]()
	{
		if (addFrames && replaceSpaceByFrame)
			return true;

		else
			return false;
	};

	//===Adding top frame===
	if (addFrames)
	{
		_gamePool->push_back(new vector<char>());
		for (int i = 0; i < sizeX && replaceSpace() || i < sizeX + 2 && !replaceSpace(); i++)
		{
			_gamePool->back()->push_back(frameChar);
		}
	}

	//===Adding board and if need be side frames===

	//Start of loop
	for (int i = 0; i < sizeY - 2 && replaceSpace() || i < sizeY && !replaceSpace(); i++)
	{
		_gamePool->push_back(new vector<char>());

		//Adding left frame
		if (addFrames) _gamePool->back()->push_back(frameChar);

		//Adding board
		for (int i = 0; i < sizeX - 2 && replaceSpace() || i < sizeX && !replaceSpace(); i++)
		{
			_gamePool->back()->push_back(spaceChar);
		}

		//Adding right frame
		if (addFrames) _gamePool->back()->push_back(frameChar);
	}
	

	//===Adding bottom frame===
	if (addFrames)
	{
		_gamePool->push_back(new vector<char>());
		for (int i = 0; i < sizeX && replaceSpace() || i < sizeX + 2 && !replaceSpace(); i++)
		{
			_gamePool->back()->push_back(frameChar);
		}
	}

	//Reparing sizes
	if (addFrames && !replaceSpaceByFrame)
	{
		_sizeX += 2;
		_sizeY += 2;
	}
}

Board::~Board()
{
	//loop working on axles y
	for (int i = 0; i < _gamePool->size(); i++)
	{
		//deleting one axle x
		delete _gamePool->at(i);
	}

	//deleting all vector
	delete _gamePool;
}

vector<vector<char>> Board::getCharacters(unsigned int xStart, unsigned int yStart, unsigned int xEnd, unsigned int yEnd) const
{
	//preparing vector
	vector<vector<char>> toReturn;

	//checking variables
	specialCheckVariables(xStart, yStart, xEnd, yEnd);

	//main loop working on axles y
	for (int i = yStart; i < yEnd; i++)
	{
		//adding new vector
		toReturn.push_back(vector<char>());

		//loop working on axles x
		for (int j = xStart; j < xEnd; j++)
		{
			//pushing to vector right value
			toReturn.back().push_back(_gamePool->at(i)->at(j));
		}
	}
	
	//returning
	return toReturn;
}

void Board::changeCharacters(unsigned int xStart, unsigned int yStart, unsigned int xEnd, unsigned int yEnd, char replacement) const
{
	//checking variables
	specialCheckVariables(xStart, yStart, xEnd, yEnd);

	//main loop working on axles y
	for (int i = yStart; i < yEnd; i++)
	{
		//loop working on axles x
		for (int j = xStart; j < xEnd; j++)
		{
			//changing right element with replacement
			_gamePool->at(i)->at(j) = replacement;
		}
	}
}

void Board::changeCharacter(char replacement, unsigned int positionX, unsigned int positionY)
{
	//checking variable x
	checkVariableX(positionX, false);
	//checking variable y
	checkVariableY(positionY, false);

	//replacing
	_gamePool->at(positionY)->at(positionX) = replacement;
}

void Board::display(unsigned int xStart, unsigned int yStart, unsigned int xEnd, unsigned int yEnd) const
{
	//getting characters
	vector<vector<char>> v = getCharacters(xStart, yStart, xEnd, yEnd);

	//===displaying===
	
	//main loop working on axle y
	for (int i = 0; i < v.size(); i++)
	{
		//loop working on axle x
		for (int j = 0; j < v[i].size(); j++)
		{
			//displaying on console
			printw("%c", v[i][j]);
		}
		//making new line
		printw("\n");
	}
}

unsigned int Board::getRanNumInsideOnX(bool setSeed) const
{
	//setting good seed
	if (setSeed)
		srand(time(NULL));

	//checking does board have frames
	if (_frames)
		//returning value
		return rand() % (_sizeX - 2)+1;
	else
		//returning value
		return rand() % _sizeX;
}

unsigned int Board::getRanNumInsideOnY(bool setSeed) const
{
	//setting good seed
	if (setSeed)
		srand(time(NULL));

	//checking does board have frames
	if (_frames)
		//returning value
		return rand() % (_sizeY - 2) + 1;
	else
		//returning value
		return rand() % _sizeY;
}

std::pair<unsigned int, unsigned int> Board::getRanNumInside(bool setSeed) const
{
	//returning value
	return std::pair<unsigned int, unsigned int>(getRanNumInsideOnX(setSeed), getRanNumInsideOnY(setSeed));
}

unsigned int Board::getSizeX() const
{
	//returning value
	return _gamePool->back()->size();
}

unsigned int Board::getSizeY() const
{
	//returning value
	return _gamePool->size();
}

std::pair<unsigned int, unsigned int> Board::getSize() const
{
	//returning value
	return std::pair<unsigned int, unsigned int>(_gamePool->back()->size(), _gamePool->size());
}

char Board::getCharOfSpace()
{
	return _space;
}

bool Board::isOnFrame(unsigned int positionX, unsigned int positionY)
{
	//checks are there frames at all
	if (_frames)
	{
		//return true if position is on frame X
		if (positionX == 0 || positionX == _sizeX-1) return true;
		//return true if position is on frame Y
		if (positionY == 0 || positionY == _sizeY-1) return true;
	}
	else
	{
		//return true if position is on frame X
		if (positionX == (unsigned int)-1 || positionX == _sizeX) return true;
		//return true if position is on frame Y
		if (positionY == (unsigned int)-1 || positionY == _sizeY) return true;
	}
	//returns value
	return false;
}


void Board::checkVariableX(unsigned int& position, bool takeFramesIntoAccount) const
{
	//cheking does _frames equal true
	if (takeFramesIntoAccount && _frames)
	{
		//cheking are start values too small
		if (position == 0) position = 1;
		//cheking are start values too big
		else if (position >= _gamePool->back()->size()) position = _gamePool->back()->size()-1;
	}
	else if (position >= _gamePool->back()->size())
	{
		//cheking are start values too big
		position = _gamePool->back()->size();
	}
}

void Board::checkVariableY(unsigned int& position, bool takeFramesIntoAccount) const
{
	//cheking does _frames equal true
	if (takeFramesIntoAccount && _frames)
	{
		//cheking are start values too small
		if (position == 0) position = 1;
		//cheking are start values too big
		else if (position >= _gamePool->size()) position = _gamePool->size()-1;
	}
	else if (position > _gamePool->size())
	{
		//cheking are start values too big
		position = _gamePool->size();
	}
}

void Board::specialCheckVariables(unsigned int& xStart, unsigned int& yStart, unsigned int& xEnd, unsigned int& yEnd, bool takeFramesIntoAccount, bool swap, bool zeroIsAll) const
{	
	//greating values is there are frames
	if (takeFramesIntoAccount && _frames)
	{
		//replacing xStart
		if (xStart == 0)
			xStart++;
		//replacing yStart
		if (yStart == 0)
			yStart++;
	}


	//Declarating lambda that will help and bool variable that help lambda
	auto getSubtrahend = [takeFramesIntoAccount, this]()
	{
		//returning 2 if there are rames
		if (takeFramesIntoAccount && this->_frames)
			return 2;
		//returning 0
		else
			return 0;
	};


	//replacing zeros by biggest possible size if zeroIsllAll equals true
	if (zeroIsAll)
	{
		//replacing xEnd
		if (xEnd == 0)
			xEnd = _gamePool->back()->size() - getSubtrahend();

		//replacing yEnd
		if (yEnd == 0)
			yEnd = _gamePool->size() - getSubtrahend();
	}
	//reducing values if that is necessity
	else
	{
		//replacing xEnd
		if (xEnd != 0) 
			xEnd -= getSubtrahend();

		//replacing yEnd
		if (yEnd != 0) 
			yEnd -= getSubtrahend();
	}
	

	//checking variables on x
	checkVariableX(xStart, false);
	checkVariableX(xEnd, false);

	//checking variables on y
	checkVariableY(yStart, false);
	checkVariableY(yEnd, false);

	//swaping values if need to
	if (xStart > xEnd && swap) std::swap(xStart, xEnd);
	if (yStart > yEnd && swap) std::swap(yStart, yEnd);

	//you can uncomment it to check is method working well
	//printw("Points: %u %u %u %u\n", xStart, yStart, xEnd, yEnd);
}
#endif