/*
	//Board board(10, 10, '0', true, false, '*');
	//board.changeCharacter('s', 1, 1);
	//board.display();


	//cout << lol << lol1 << "\n";
	//board.checkVariableX(lol, false);
	//cout << lol << lol1 << "\n";

	//while (1) {		
		//player.move();
		//gra.losujPolozeniePunktu();
		//gra.wyswietl();
		//system("cls");
		
	//}
    //#include <cstdlib>
//#include <iostream>
//#include <ctime>
//#include <vector>

        //Rozgrywka gra(4,9);
    //gra.ustawianie();
    //gra.losujPolozeniePunktu();
    //gra.wyswietl();

    //Board board(2, 2, '0', true , false, '#');

    //board.display(0, 0, 3, 3);

#pragma once

#include <utility>
#include "positioned.h"

/// <summary>
/// Player class.
/// </summary>
class Player : public Positioned
{
public:
    /// <summary>
    /// Constructor.
    /// </summary>
    /// <param name="positionX">- Set where player will be on axle x. </param>
    /// <param name="positionY">- Set where player will be on axle y. </param>
    Player(unsigned int positionX = 1, unsigned int positionY = 1);

    /// <summary>
    /// Destructor.
    /// </summary>
    ~Player();

    /// <summary>
    /// It changes position of point on board.
    /// </summary>
    /// <param name="character">- Set where player will be on axle y. </param>
    void move(char character = NULL);

private:
    /// <summary>
    /// It makes player more on right.
    /// </summary>
    void moveToRight();

    /// <summary>
    /// It makes make player more on left.
    /// </summary>
    void moveToLeft();

    /// <summary>
    /// It makes make player more on up.
    /// </summary>
    void moveToUp();

    /// <summary>
    /// It makes make player more on down.
    /// </summary>
    void moveToDown();

    /// <summary>
    /// Key that say where the point is going to go.
    /// </summary>
    char m_moveKey;
};

#include "player.h"
#include <conio.h>
#include <ctype.h>
#include <iostream>

//==============================================================================//

void Rozgrywka::ruchPrawo()
{
    pole_gry[gracza_os_y][gracza_os_x] = ' ';
    gracza_os_x++;
    pole_gry[gracza_os_y][gracza_os_x] = 'P';
}

//------

void Rozgrywka::ruchLewo()
{
    pole_gry[gracza_os_y][gracza_os_x] = ' ';
    gracza_os_x--;
    pole_gry[gracza_os_y][gracza_os_x] = 'P';
}

//------

void Rozgrywka::ruchGora()
{
    pole_gry[gracza_os_y][gracza_os_x] = ' ';
    gracza_os_y--;
    pole_gry[gracza_os_y][gracza_os_x] = 'P';
}

//------

void Rozgrywka::ruchDol()
{
    pole_gry[gracza_os_y][gracza_os_x] = ' ';
    gracza_os_y++;
    pole_gry[gracza_os_y][gracza_os_x] = 'P';
}


void Rozgrywka::poruszSie()
{

    switch (klawisz_ruchu)
    {
    case 'a': this->ruchLewo(); break;
    case 'd': this->ruchPrawo(); break;
    case 'w': this->ruchGora(); break;
    case 's': this->ruchDol(); break;

    case 'A': this->ruchLewo(); break;
    case 'D': this->ruchPrawo(); break;
    case 'W': this->ruchGora(); break;
    case 'S': this->ruchDol(); break;
    }

}

//==============================================================================//

Player::Player(unsigned int posX, unsigned int posY)
    :Positioned(posX, posY), m_moveKey(NULL)
{
}

Player::~Player()
{
}

void Player::move(char character)
{
    m_moveKey = _getch();
    m_moveKey = tolower(m_moveKey);

    switch (m_moveKey)
    {
    case 'a': this->moveToLeft(); break;
    case 'd': this->moveToRight(); break;
    case 'w': this->moveToUp(); break;
    case 's': this->moveToDown(); break;
    }
}

void Player::moveToRight()
{
    std::cout << "right";
}

void Player::moveToLeft()
{
    std::cout << "left";
}

void Player::moveToUp()
{
    std::cout << "up";
}

void Player::moveToDown()
{
    std::cout << "down";
}




#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "headers.h"
#include <conio.h>


using namespace std;

Rozgrywka::Rozgrywka(int y,int x)
{
    gracza_os_y=y;
    gracza_os_x=x;
}

void Rozgrywka::losujPolozeniePunktu()
{
    srand(time(NULL));
    punktu_os_y = rand() % 7 + 1;
    punktu_os_x = rand() % 16 + 1;

    pole_gry[punktu_os_y][punktu_os_x] = '#';
}


void Rozgrywka::sprawdzCzyPunktDotkniety()
{
    if (gracza_os_y == punktu_os_y && gracza_os_x == punktu_os_x)
    {
        pole_gry[punktu_os_y][punktu_os_x] = ' ';
        this->losujPolozeniePunktu();
    }
}

void Rozgrywka::wyswietl()
{
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 17; j++)
        {
            cout << pole_gry[i][j];
        }

        cout << endl;
    }
}

void Rozgrywka::ustawianie()
{
    pole_gry[gracza_os_y][gracza_os_x]='P';

    //ramki

        for(int i=0;i<=17;i++) //gorna granica
        {
        pole_gry[0][i]='-';
        }

        for(int i=0;i<=17;i++) //dolna granica
        {
        pole_gry[8][i]='-';
        }

        for(int i=1;i<=9;i++) //lewa granica
        {
        pole_gry[i][0]='-';
        }

        for(int i=1;i<=9;i++) //prawa granica
        {
        pole_gry[i][16]='-';
        }

    //srodek

    for(int j=1;j<=7;j++)

        for(int i=1;i<=16;i++)
        {
        if(j==4&&i==9)i++;
        pole_gry[j][i]=' ';
        }

}

//SPACEEEEEEEEEE

void Game::moveToRight()
{
    //cleaning old position
    cleanTraceOfPositioned(m_player);

    //setting up new position
    m_player.newPositionX(m_player.getPositionX() + 1);

    //drawing new position on board
    m_board.changeCharacter(m_player.getSprite(), m_player.getPositionX(), m_player.getPositionY());
}

void Game::moveToLeft()
{
    //cleaning old position
    cleanTraceOfPositioned(m_player);

    //setting up new position
    m_player.newPositionX(m_player.getPositionX() - 1);

    //drawing new position on board
    m_board.changeCharacter(m_player.getSprite(), m_player.getPositionX(), m_player.getPositionY());
}

void Game::moveToUp()
{
    //cleaning old position
    cleanTraceOfPositioned(m_player);

    //setting up new position
    m_player.newPositionY(m_player.getPositionY() - 1);

    //drawing new position on board
    m_board.changeCharacter(m_player.getSprite(), m_player.getPositionX(), m_player.getPositionY());
}

void Game::moveToDown()
{
    //cleaning old position
    cleanTraceOfPositioned(m_player);

    //setting up new position
    m_player.newPositionY(m_player.getPositionY() + 1);

    //drawing new position on board
    m_board.changeCharacter(m_player.getSprite(), m_player.getPositionX(), m_player.getPositionY());
}

void Game::makeMove(char character)
{
    //switch (tolower(character))
    //{
    //case 'a': moveToLeft(); break;
    //case 'd': moveToRight(); break;
    //case 'w': moveToUp(); break;
    //case 's': moveToDown(); break;
    //}

    //cleaning old position
    cleanTraceOfPositioned(m_player);

    //setting new position of point
    move(Direction(tolower(character)));

    //checking is m_player on frame and if it is returning to old position
    if (moveCheck())
        move(reverseDirection(Direction(tolower(character))));

    //drawing new position on board
    m_board.changeCharacter(m_player.getSprite(), m_player.getPositionX(), m_player.getPositionY());
}
*/