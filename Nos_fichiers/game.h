#ifndef GAME_H
#define GAME_H

/*!
 * \file game.h
 * \brief Main file of the project
 * \author Franck Daudet
 * \author Nicolas Jaubert
 * \author Valere Coroller
 * \version 1.6
 * \date 07/01/21
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "Start-End_Screen.h"
#include "deplacement.h"
#include "affichage.h"
#include "settings.h"
#include "triclassement.h"
// Different map
vector<vector<string>> kmap{
	{"╔","═","═",".",".","═","═",".","═",".","═","═",".","═","╗"},
	{".","ᗧ",".",".",".",".",".",".",".",".",".",".",".",".","."},
	{".",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","."},
    {".",".",".",".",".",".","║",".","║",".",".",".","║","¤","."},
	{".",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
	{".",".","║",".","║",".","║",".","║",".","║",".","║",".","."},
	{".",".","║",".",".",".","║",".","║",".",".",".","║",".","."},
	{".",".","╚",".",".","═","╝",".","╚","═",".","═","╝",".","║"},
    {".",".",".",".",".",".",".","¤",".",".",".",".",".",".","."},
	{"║",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","║"},
    {"║","¤","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","."},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","╚","═",".","═","╝",".","╚","═",".","═","╝",".","."},
	{"║",".",".",".",".",".",".",".",".",".",".",".",".",".","."},
	{"╚","═",".","═",".","═","═",".",".","═",".",".",".","═","╝"}};




/**
 * @brief count the numbers of PacGum on the map at each refresh
 * @return (voir exemple)
 */

unsigned CountNbPacGum();



/**
 * @brief count the numbers of Cherry(bonus) on the map at each refresh
 * @return (voir exemple)
 */

unsigned CountNbCherry();



/**
 * @brief count the numbers of Ghosts on the map at each refresh
 * @return (voir exemple)
 */

unsigned CountNbGhost()
{
    unsigned nbghost(0);
    for (int x = 0; x < kmap.size(); x++) {
        for (int y = 0; y < kmap[x].size(); y++) {
              if(kmap[x][y] == "¤")
                {
                  nbghost = nbghost + 1;
              }
            }
    }
    return nbghost;
}


/**
 * @brief do at each movements a calculing operation that permit to get the player's score
 * @return (voir exemple)
 */

unsigned Calculscore()
{
    unsigned PlayerScore(0);
    unsigned NbPacGumEatByPlayer(0);
    unsigned NbCherryEatByPlayer(0);
    unsigned NbGhostEatByplayer(0);
    NbPacGumEatByPlayer = NbPacGumInit - CountNbPacGum();
    NbCherryEatByPlayer = NbcherryInit - CountNbCherry();
    NbGhostEatByplayer = 3 - CountNbGhost();
    PlayerScore = NbPacGumEatByPlayer + NbCherryEatByPlayer*10 + NbGhostEatByplayer*50;
    return PlayerScore;
}



/**
 * @brief display the player's score
 */

void AffichScore();

// start the game and show map/enemies/character

/*!
 * \brief résumé à faire (voir correc prof pour exemple)
 * \fn (voir exemple)
 */

void Launch_Game();

    vector<int> pos {1,1};
	vector<int> posf1 {1,2};
    vector<int> oldposf1 {0,0};
	vector<int> posf2 {3,7};
    vector<int> oldposf2 {0,0};
    vector<int> posf3 {2,4};
    vector<int> oldposf3 {0,0};

    string ElementOnF1 (" ");
    string ElementOnF2 (" ");
    string ElementOnF3 (" ");
    ShowMap(kmap);
    string EatByPacman = " ";
    bool Pasmort = true;

    while (Pasmort){
        AffichScore();
        EatByPacman = MovePacman(pos,kmap);
        oldposf1 = NextPhantomMove(kmap,posf1,oldposf1);
        oldposf2 = NextPhantomMove(kmap,posf2,oldposf2);
        oldposf3 = NextPhantomMove(kmap,posf3,oldposf3);

		
        ElementOnF1 = MoveCharacter(posf1,kmap,oldposf1,"@",ElementOnF1);
        ElementOnF2 = MoveCharacter(posf2,kmap,oldposf2,"$",ElementOnF2);
        ElementOnF3 = MoveCharacter(posf3,kmap,oldposf3,"£",ElementOnF3);

        if (ElementOnF1 == "$"){
            ElementOnF1 = ElementOnF2;
        }
        else if (ElementOnF1 == "£"){
            ElementOnF1 = ElementOnF3;
        }
        if (ElementOnF2 == "@"){
            ElementOnF2 = ElementOnF1;
        }
        else if (ElementOnF2 == "£"){
            ElementOnF2 = ElementOnF3;
        }
        if (ElementOnF3 == "@"){
            ElementOnF3 = ElementOnF1;
        }
        else if (ElementOnF3 == "$"){
            ElementOnF3 = ElementOnF2;
        }


		ShowMap(kmap);
        if (pos == posf1 || pos == posf2 || pos == posf3) Pasmort = false;
	}
}

/*! 
 * \brief main function of the project 
 * \fn void PacMan() 
 */ 

void PacMan() 
{ 
    while(true) 
    { 
        unsigned u = Start_Screen(); 
        if (u==1) 
        { 
            Launch_Game();
            EntryPlayerscore(Calculscore());
            while(true) 
            { 
                unsigned v = End_Screen(); 
                if (v==1) 
                { 
                    Launch_Game();
                    EntryPlayerscore(Calculscore());
                    continue; 
                } 
                else if (v==2) 
                { 
                    SortDisplay();
                    continue; 
                } 
                else if (v==3) 
                { 
                    settings();
                    continue; 
                } 
                else if (v==4) 
                    exit(0);
                else if (v==5)
                {
                    Credit();
                    continue;
                }

#endif // GAME_H 
