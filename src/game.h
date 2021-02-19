#pragma once

#include "board.h"
#include "positioned.h"
#include "direction.h"

/// <summary>
/// Game class.
/// </summary>
class Game 
{
public:
    /// <summary>
    /// Constructor.
    /// </summary>
    /// <param name="sizeX">- Width of board.</param>
    /// <param name="sizeY">- Height of board.</param>
    /// <param name="spaceChar">- Character that will be used to create space of board.</param>
    /// <param name="addFrames">- Says does board will have frames.</param>
    /// <param name="replaceSpaceByFrame">- If it's true frames will contains in sizeX and sizeY and for this reason theese values have to equal 4 or more.</param>
    /// <param name="frameChar">- Character that will be used to create frames of board.</param>
    /// <param name="playerPositionX">- Position of player on board on axle x.</param>
    /// <param name="playerPositionY">- Position of player on board on axle Y.</param>
    /// <param name="playerSprite">- Character that will be used to create player.</param>
    /// <param name="pointSprite">- Character that will be used to create point.</param>
    Game(unsigned int sizeX = 2, unsigned int sizeY = 2, char spaceChar = ' ', bool addFrames = true, bool replaceSpaceByFrame = false, char frameChar = '#', unsigned int playerPositionX = 0, unsigned int playerPositionY = 0, char playerSprite = 'O', char pointSprite = '*');

    /// <summary>
    /// Destructor.
    /// </summary>
    ~Game();
    
    /// <summary>
    /// Makes a new "frame" of game.
    /// </summary>
    void newFrame();

    /// <summary>
    /// It's drawing a board on console and if cleanBoard is true, clearing a last show of board.
    /// </summary>
    /// <param name="cleanBoard">- If it's true function cleans console. It's using system("cls").</param>
    /// <param name="showPosition">- If it's true function displays position of player under board.</param>
    void show(bool cleanBoard = true, bool showPoints = true, bool showPosition = false);
    
    /// <summary>
    /// It's telling do game has been ended. It's ending when player give 'e' character.
    /// </summary>
    /// <returns>True if game has been ended false if not.</returns>
    bool isEnded();

private:
    /// <summary>
    /// Cleans old position of Positioned.
    /// </summary>
    /// <param name="toClean">- m_point or m_player</param>
    void cleanTraceOfPositioned(Positioned& toClean);

    /// <summary>
    /// It's getting a character, checking it out and then changing position of player.
    /// </summary>
    /// <param name="character">- Character from keyboard. A - left, W - up, D - right, S - down.</param>
    void makeMove(char character);

    /// <summary>
    /// It's checking out position of point and player and if they equal it's generating new position of point if makeNewPosition is true.
    /// </summary>
    /// <param name="addPoints">- If it's true and positions of m_point and m_player equal m_points are incrasing. Else it's not.</param>
    void checkCollisions(bool addPoints = true);

    /// <summary>
    /// Sets new random position of m_point.
    /// </summary>
    /// <param name="setSeed">- If it's set new seed using srand(time(NULL)).</param>
    void newPositionOfPoint(bool setSeed = true);

    /// <summary>
    /// Makes new move of player.
    /// </summary>
    /// <param name="direction">Direction which says where player will make move.</param>
    void move(Direction direction);

    /// <summary>
    /// Checks is player on board's frame.
    /// </summary>
    /// <returns>True if it is on frames, false if not.</returns>
    bool positionCheck();

    /// <summary>
    /// Tells is game ended.
    /// </summary>
    bool _ended;

    /// <summary>
    /// Says how many times m_point and m_player was on same position.
    /// </summary>
    unsigned int _points;

    /// <summary>
    /// Point object.
    /// </summary>
    Positioned _point;

    /// <summary>
    /// Object that will be moving on console.
    /// </summary>
    Positioned _player;

    /// <summary>
    /// There are all character that make up the board
    /// </summary>
    Board _board;
};