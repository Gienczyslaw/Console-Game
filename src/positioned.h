#pragma once

#include <utility>

/// <summary>
/// Class that will be created with objects that will probably be showed on board.
/// </summary>
class Positioned
{
public:
    /// <summary>
    /// Constructor.
    /// </summary>
    /// <param name="posX">- Set where point will be on axle x. </param>
    /// <param name="posY">- Set where point will be on axle y. </param>
    /// <param name="sprite">- Specifies which character will illustrate the positioned object. </param>
    Positioned(unsigned int posX = 1, unsigned int posY = 1, char sprite = '*');

    /// <summary>
    /// Destructor.
    /// </summary>
    ~Positioned();

    /// <summary>
    /// That function can be used to set new position of point on axis X.
    /// </summary>
    /// <param name="newPosition">- Value that is going to be position.</param>
    void newPositionX(unsigned int newPosition);

    /// <summary>
    /// That function can be used to set new position fo point on axis Y.
    /// </summary>
    /// <param name="newPosition">- Value that is going to be position.</param>
    void newPositionY(unsigned int newPosition);

    /// <summary>
    /// Use it to get position of point.
    /// </summary>
    /// <param name="newPosition">- Pair of uints that will be the position of positioned.</param>
    void newPosition(std::pair<unsigned int, unsigned int> newPosition);

    /// <summary>
    /// Use it to get position of point on axis X.
    /// </summary>
    /// <returns>Position of point on axis X.</returns>
    unsigned int getPositionX();

    /// <summary>
    /// Use it to get position of point on axis Y.
    /// </summary>
    /// <returns>Position of point on axis Y.</returns>
    unsigned int getPositionY();

    /// <summary>
    /// Use it to get position of point.
    /// </summary>
    /// <returns>Two values - position on axle X and position on axle Y.</returns>
    std::pair<unsigned int, unsigned int> getPosition();

    /// <summary>
    /// That function can be used to set new position of point on axis X.
    /// </summary>
    /// <param name="newPosition">- Value that is going to be position.</param>
    void newSprite(char newSprite);

    /// <summary>
    /// Use it to get position of point on axis X.
    /// </summary>
    /// <returns>Position of point on axis X.</returns>
    char getSprite();

private:
    /// <summary>
    /// It's positon of point on axis X.
    /// </summary>
    unsigned int m_positionX;

    /// <summary>
    /// It's positon of point on axis Y.
    /// </summary>
    unsigned int m_positionY;

    /// <summary>
    /// Specifies which character will illustrate the positioned object.
    /// </summary>
    char m_sprite;
};

