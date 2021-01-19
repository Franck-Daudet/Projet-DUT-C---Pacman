#ifndef AFFICHAGE_H
#define AFFICHAGE_H

/*!
 * \file affichage.h
 * \brief All the const and the display of the characters + display of themap
 * \author Franck Daudet
 * \author Nicolas Jaubert
 * \author Valere Coroller
 * \author Justin De Sio
 * \version 1.3
 * \date 07/01/21
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

const string KReset   ("0");
const string KBlack    ("30");
const string KRed   ("31");
const string KGreen    ("32");
const string KYellow   ("33");
const string KBlue    ("34");
const string KMAgenta ("35");
const string KCyan    ("36");
const string KLightGrey ("37");
const string KBCyan   ("46");
const string KBLightGrey ("47");
const string KBYellow  ("43");
const string Pacman  ("\u15E7");



void MoveCharacter (vector<int> pos);

void MoveElt (vector<vector<string>> & map,vector<int> pos,vector<int> AddPos);

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @fn (voir exemple)
 */

void ClearScreen (){
	//Clear the screen
    cout << "\033[H\033[2J";
}

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in] coul   petit résumé à faire
 * @fn (voir exemple)
 */

void Color (const string & coul){
	// Allows you to add Color in the terminal
    cout << "\033[" << coul <<"m";
}

/*!
 * \brief résumé à faire (voir correc prof pour exemple)
 * \param[in, out] Map   petit résumé à faire
 * \fn (voir exemple)
 */

void ShowMap(vector<vector<string>> & map){
	// Color map and show it
	ClearScreen ();
	Color(KBCyan);
    Color(KBlack);
	for (int x = 0; x < map.size(); x++) {
		for (int y = 0; y < map[x].size(); y++) {
			if ( map[x][y] == Pacman){
                Color(KYellow);
				cout << map[x][y] ;
                Color(KBlack);
			}
			else cout << map[x][y] ;
		}
		cout << endl;
	}
	Color(KReset);
}

#endif // AFFICHAGE_H
