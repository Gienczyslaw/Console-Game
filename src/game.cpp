#include "game.h"

#ifdef CURSES_AVAILABLE
#include <ctype.h>

Game::Game(unsigned int sizeX, unsigned int sizeY, char spaceChar, bool addFrames, bool replaceSpaceByFrame, char frameChar, unsigned int playerPositionX, unsigned int playerPositionY, char playerSprite, char pointSprite)
    :_board(sizeX, sizeY, spaceChar, addFrames, replaceSpaceByFrame, frameChar), _points(0), _ended(false)
{    
    //reparing sizes
    sizeX = _board.getSizeX();
    sizeY = _board.getSizeY();

    //checking player position
    if (sizeX <= playerPositionX) playerPositionX = sizeX - 1;
    if (sizeY <= playerPositionY) playerPositionY = sizeY - 1;

    //setting up objects
    _player = Positioned(playerPositionX, playerPositionY, playerSprite);
    _point = Positioned(_board.getRanNumInsideOnX(true), _board.getRanNumInsideOnY(false), pointSprite);

    checkCollisions(false);

    //drawing Positioned objects
    _board.changeCharacter(_point.getSprite(), _point.getPositionX(), _point.getPositionY());
    _board.changeCharacter(_player.getSprite(), _player.getPositionX(), _player.getPositionY());
}

Game::~Game()
{
}

void Game::newFrame()
{
    //makes next _player's move
    makeMove(getch());

    if (_ended)
        return;

    //checking _player's and _point's positions
    checkCollisions();

    //shows board
    show();
}

void Game::cleanTraceOfPositioned(Positioned& toClean)
{
    //"deleting" trace of old position of point
    _board.changeCharacter(_board.getCharOfSpace(), toClean.getPositionX(), toClean.getPositionY());
}

void Game::makeMove(char character)
{
    //exit
    if (tolower(character) == 'e')
    {
        _ended = true;
        return;
    }
    
    //cleaning old position
    cleanTraceOfPositioned(_player);

    //setting new position of point
    move(Direction(tolower(character)));

    //checking is _player on frame and if it is returning to old position
    if (positionCheck())
        move(reverseDirection(Direction(tolower(character))));

    //drawing new position on board
    _board.changeCharacter(_player.getSprite(), _player.getPositionX(), _player.getPositionY());
}

void Game::show(bool cleanBoard, bool showPoints, bool showPosition)
{
    //cleaning
    if (cleanBoard)
    {
        clear();
    }


    //displaying board
    _board.display();

    //showing points
    if (showPoints)
    {
        printw("Points: %u\n", _points);
    }

    //displaying position
    if (showPosition)
    {
        printw("Points: %u %u\n", _player.getPositionX(), _player.getPositionY());
    }
}

bool Game::isEnded()
{
    return _ended;
}

void Game::checkCollisions(bool addPoints)
{
    //checking are position equal
    if (_point.getPosition() == _player.getPosition())
    {
        //incrasing points
        if(addPoints) _points++;

        //generates new position
        newPositionOfPoint();

        //if generating faild generates new position while position is wrong
        while (_point.getPosition() == _player.getPosition())
        {
            //generates new position
            newPositionOfPoint(false);
        }

        //drawing new point
        _board.changeCharacter(_point.getSprite(), _point.getPositionX(), _point.getPositionY());
    }
}

void Game::newPositionOfPoint(bool setSeed)
{
    //generates new position
    _point.newPosition(_board.getRanNumInside(setSeed));
}

void Game::move(Direction direction)
{    
    //switch that checks direction
    switch (direction)
    {
    //left checking
    case Direction::LEFT:
        _player.newPositionX(_player.getPositionX() - 1);
        break;

    //up checking
    case Direction::UP:
        _player.newPositionY(_player.getPositionY() - 1);
        break;

    //right checking
    case Direction::RIGHT:
        _player.newPositionX(_player.getPositionX() + 1);
        break;

    //down checking
    case Direction::DOWN:
        _player.newPositionY(_player.getPositionY() + 1);
        break;
    }
}

bool Game::positionCheck()
{
    //cheking is _player on frame
    if (_board.isOnFrame(_player.getPositionX(), _player.getPositionY()))
        //returning true if it is
        return true;
    else
        //returning false if it not
        return false;
}
#endif