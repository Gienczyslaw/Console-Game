#pragma once

#include <vector>

using std::vector;

class Board
{
public:
    /// <summary>
    /// Constructor.
    /// </summary>
    /// <param name="sizeX">- Size of board on axle X. If function get 0 or 1 it will be automatically replaced by 2.</param>
    /// <param name="sizeY">- Size of board on axle Y. If function get 0 or 1 it will be automatically replaced by 2.</param>
    /// <param name="spaceChar">- Specifies which character will be used to make a free space, actual board.</param>
    /// <param name="addFrames">- If it's true to board will be added frame.</param>
    /// <param name="replaceSpaceByFrame">- If it's true characters counted to board will be replaced by frame. If it's true and any of value is less than 4, size will be greated to value 4.</param>
    /// <param name="frameChar">- Specifies which character will be used to make a frame.</param>
    Board(unsigned int sizeX = 2, unsigned int sizeY = 2, char spaceChar = ' ', bool addFrames = true, bool replaceSpaceByFrame = false, char frameChar = '#');

    /// <summary>
    /// Destructor.
    /// </summary>
	~Board();

    /// <summary>
    /// You can get characters from, which create board.
    /// </summary>
    /// <param name="xStart">- That informs function where start getting characters from axle x. If it's more than width of board it will be changed to weight of board.</param>
    /// <param name="yStart">- That informs function where start getting characters from axle y. If it's more than width of board it will be changed to height of board.</param>
    /// <param name="xEnd">- That informs function where end getting characters from axle x. If it's 0, function will return all characters from axle or if it's more than width of board it will be changed to weight of board.</param>
    /// <param name="yEnd">- That informs function where end getting characters from axle y. If it's 0, function will return all characters from axle or if it's more than width of board it will be changed to height of board.</param>
    /// <returns>Array of characters that creates board.</returns>
    vector<vector<char>> getCharacters(unsigned int xStart = 0, unsigned int yStart = 0, unsigned int xEnd = 0, unsigned int yEnd = 0) const;
    
    /// <summary>
    /// You can replace some characters by that character that you like to.
    /// </summary>
    /// <param name="replacement">- Character that will replace chosen characters.</param>
    /// <param name="xStart">- That informs function where start replacing characters from axle x. If it's more than width of board it will be changed to weight of board.</param>
    /// <param name="yStart">- That informs function where start replacing characters from axle y. If it's more than width of board it will be changed to height of board.</param>
    /// <param name="xEnd">- That informs function where end replacing characters from axle x. If it's 0, function will replace all characters from axle or if it's more than width of board it will be changed to weight of board.</param>
    /// <param name="yEnd">- That informs function where end replacing characters from axle y. If it's 0, function will replace all characters from axle or if it's more than width of board it will be changed to height of board.</param>
    void changeCharacters(unsigned int xStart = 0, unsigned int yStart = 0, unsigned int xEnd = 0, unsigned int yEnd = 0, char replacement = ' ') const;

    /// <summary>
    /// You can replace one character by character that you like to.
    /// </summary>
    /// <param name="replacement">- Character that will replace chosen character.</param>
    /// <param name="positionX">- Position on axle X of character that is shall be replaced by replacement.</param>
    /// <param name="positionY">- Position on axle Y of character that is shall be replaced by replacement.</param>
    void changeCharacter(char replacement, unsigned int positionX = 0, unsigned int positionY = 0);

    /// <summary>
    /// Displays charcters that create board. It uses getCharacters() method.
    /// </summary>
    /// <param name="xStart">- That informs function where start displaying characters from axle x. It works on the same principle as in getCharacters().</param>
    /// <param name="yStart">- That informs function where start displaying characters from axle y. It works on the same principle as in getCharacters().</param>
    /// <param name="xEnd">- That informs function where end displaying characters from axle x. It works on the same principle as in getCharacters().</param>
    /// <param name="yEnd">- That informs function where end displaying characters from axle y. It works on the same principle as in getCharacters().</param>
    void display(unsigned int xStart = 0, unsigned int yStart = 0, unsigned int xEnd = 0, unsigned int yEnd = 0) const;

    /// <summary>
    /// Generates a random number that is inside board (never on frame) and is on axle X.
    /// </summary>
    /// <param name="setSeed">- If it's set new seed using srand(time(NULL)).</param>
    /// <returns>Position on axle X.</returns>
    unsigned int getRanNumInsideOnX(bool setSeed = true) const;

    /// <summary>
    /// Generates a random number that is inside board (never on frame) and is on axle Y.
    /// </summary>
    /// <param name="setSeed">- If it's set new seed using srand(time(NULL)).</param>
    /// <returns>Position on axle Y.</returns>
    unsigned int getRanNumInsideOnY(bool setSeed = true) const;

    /// <summary>
    /// Generates a random number that is inside board (never on frame).
    /// </summary>
    /// <param name="setSeed">- If it's set new seed using srand(time(NULL)).</param>
    /// <returns>Position as pair structure.</returns>
    std::pair<unsigned int, unsigned int> getRanNumInside(bool setSeed = true) const;

    /// <summary>
    /// Use it to get size of board on axis X.
    /// </summary>
    /// <returns>Size of board on axis X.</returns>
    unsigned int getSizeX() const;

    /// <summary>
    /// Use it to get size of board on axis Y.
    /// </summary>
    /// <returns>Size of board on axis Y.</returns>
    unsigned int getSizeY() const;

    /// <summary>
    /// Use it to get size of board.
    /// </summary>
    /// <returns>Size of board.</returns>
    std::pair<unsigned int, unsigned int> getSize() const;

    /// <summary>
    /// Use it to get character that creates space in board.
    /// </summary>
    /// <returns>Character that creates space in board</returns>
    char getCharOfSpace();

    /// <summary>
    /// Says is position of object on frame or out of board.
    /// </summary>
    /// <param name="positionX">- position of object on axle x.</param>
    /// <param name="positionY">- position of object on axle y.</param>
    /// <returns>Information about that is object on frame or out of board.</returns>
    bool isOnFrame(unsigned int positionX, unsigned int positionY);

private:
    /// <summary>
    /// Checks and if need to repairs parameters that gets. Values are checking in relation to axis X.
    /// </summary>
    /// <param name="posistion">- "Positon" of on board to check.</param>
    /// <param name="takeFramesIntoAccount"> - If it's true permissible position of value to check will be reduced by size of frames.</param>
    void checkVariableX(unsigned int& posistion, bool takeFramesIntoAccount = true) const;

    /// <summary>
    /// Checks and if need to repairs parameters that gets. Values are checking in relation to axis X.
    /// </summary>
    /// <param name="posistion">- It must be a variable from method that variable have the same name.</param>
    /// <param name="takeFramesIntoAccount"> - If it's true permissible position of value to check will be reduced by size of frames.</param>
    void checkVariableY(unsigned int& posistion, bool takeFramesIntoAccount = true) const;

    /// <summary>
    /// Checks and if need to repairs parameters that from changeCharacters() or getCharacters() gets.
    /// </summary>
    /// <param name="xStart">- It must be a variable from method that variable have the same name.</param>
    /// <param name="yStart">- It must be a variable from method that variable have the same name.</param>
    /// <param name="xEnd">- It must be a variable from method that variable have the same name.</param>
    /// <param name="yEnd">- It must be a variable from method that variable have the same name.</param>
    /// <param name="takeFramesIntoAccount">- If it's true permissible position of value to check will be reduced.</param>
    /// <param name="swap">- If it's true and end is bigger than start theese values will be swaped.</param>
    /// <param name="zeroIsAll">- If it's true and xEnd or yEnd will equal zero, it will be greated to biggest possible value.</param>
    void specialCheckVariables(unsigned int& xStart, unsigned int& yStart, unsigned int& xEnd, unsigned int& yEnd, bool takeFramesIntoAccount = false, bool swap = true, bool zeroIsAll = true) const;

    /// <summary>
    /// Says does board have frames.
    /// </summary>
    bool m_frames;

    /// <summary>
    /// Specifies which character will be used to make a free space, actual board.
    /// </summary>
    char m_space;

    /// <summary>
    /// Specifies which character will be used to make a frame.
    /// </summary>
    char m_frame;

    /// <summary>
    /// Specifies board's size on axle X.
    /// </summary>
    int m_sizeX;

    /// <summary>
    /// Specifies board's size on axle Y.
    /// </summary>
    int m_sizeY;

    /// <summary>
    /// Array that contains character which create the board.
    /// </summary>
    mutable vector<vector<char>*>* m_gamePool;
};