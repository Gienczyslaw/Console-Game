#include "game.h"
#include <iostream>
#include <conio.h> 

Game::Game(unsigned int sizeX, unsigned int sizeY, char spaceChar, bool addFrames, bool replaceSpaceByFrame, char frameChar, unsigned int playerPositionX, unsigned int playerPositionY, char playerSprite, char pointSprite)
    :m_board(sizeX, sizeY, spaceChar, addFrames, replaceSpaceByFrame, frameChar), m_points(0)
{    
    //reparing sizes
    sizeX = m_board.getSizeX();
    sizeY = m_board.getSizeY();

    //checking player position
    if (sizeX <= playerPositionX) playerPositionX = sizeX - 1;
    if (sizeY <= playerPositionY) playerPositionY = sizeY - 1;

    //setting up objects
    m_player = Positioned(playerPositionX, playerPositionY, playerSprite);
    m_point = Positioned(m_board.getRanNumInsideOnX(true), m_board.getRanNumInsideOnY(false), pointSprite);

    checkCollisions(false);

    //drawing Positioned objects
    m_board.changeCharacter(m_point.getSprite(), m_point.getPositionX(), m_point.getPositionY());
    m_board.changeCharacter(m_player.getSprite(), m_player.getPositionX(), m_player.getPositionY());
}

Game::~Game()
{
}

void Game::newFrame()
{
    //makes next m_player's move
    makeMove(_getch());

    //checking m_player's and m_point's positions
    checkCollisions();

    //shows board
    show();
}

void Game::cleanTraceOfPositioned(Positioned& toClean)
{
    //"deleting" trace of old position of point
    m_board.changeCharacter(m_board.getCharOfSpace(), toClean.getPositionX(), toClean.getPositionY());
}

void Game::makeMove(char character)
{
    //cleaning old position
    cleanTraceOfPositioned(m_player);

    //setting new position of point
    move(Direction(tolower(character)));

    //checking is m_player on frame and if it is returning to old position
    if (positionCheck())
        move(reverseDirection(Direction(tolower(character))));

    //drawing new position on board
    m_board.changeCharacter(m_player.getSprite(), m_player.getPositionX(), m_player.getPositionY());
}

void Game::show(bool cleanBoard, bool showPoints, bool showPosition)
{
    //cleaning
    if (cleanBoard) system("cls");

    //displaying board
    m_board.display();

    //showing points
    if (showPoints) std::cout << "Points: " << m_points << std::endl;

    //displaying position
    if (showPosition) std::cout << "Position: " << m_player.getPositionX() << " " << m_player.getPositionY() << std::endl;
}

void Game::checkCollisions(bool addPoints)
{
    //checking are position equal
    if (m_point.getPosition() == m_player.getPosition())
    {
        //incrasing points
        if(addPoints) m_points++;

        //generates new position
        newPositionOfPoint();

        //if generating faild generates new position while position is wrong
        while (m_point.getPosition() == m_player.getPosition())
        {
            //generates new position
            newPositionOfPoint(false);
        }

        //drawing new point
        m_board.changeCharacter(m_point.getSprite(), m_point.getPositionX(), m_point.getPositionY());
    }
}

void Game::newPositionOfPoint(bool setSeed)
{
    //generates new position
    m_point.newPosition(m_board.getRanNumInside(setSeed));
}

void Game::move(Direction direction)
{    
    //switch that checks direction
    switch (direction)
    {
    //left checking
    case Direction::LEFT:
        m_player.newPositionX(m_player.getPositionX() - 1);
        break;

    //up checking
    case Direction::UP:
        m_player.newPositionY(m_player.getPositionY() - 1);
        break;

    //right checking
    case Direction::RIGHT:
        m_player.newPositionX(m_player.getPositionX() + 1);
        break;

    //down checking
    case Direction::DOWN:
        m_player.newPositionY(m_player.getPositionY() + 1);
        break;
    }
}

bool Game::positionCheck()
{
    //cheking is m_player on frame
    if (m_board.isOnFrame(m_player.getPositionX(), m_player.getPositionY()))
        //returning true if it is
        return true;
    else
        //returning false if it not
        return false;
}
