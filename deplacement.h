#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
#include "getch.h"

using namespace std;

// MATRICE YX (et non XY)


unsigned MapXSize (vector<vector<string>> & map){
	// return X size of the map
	return map[0].size();
}

unsigned MapYSize (vector<vector<string>> & map){
	// return Y size of the map
	return map.size()-1;
}

void MoveXElt (vector<vector<string>> & map,vector<int> pos, int NewX){
	// Move X pos of the Element
	map[pos[0]][pos[1]]= " ";
	map[NewX][pos[1]] = "\u15E7";
}

void MoveYElt (vector<vector<string>> & map,vector<int> pos, int NewY){
	// Move Y pos of the Element
	map[pos[0]][pos[1]]= " ";
	map[pos[0]][NewY] = "\u15E7";
}

void MoveElt (vector<vector<string>> & map,vector<int> pos,vector<int> Addpos){
	// Move X and Y pos of the Element
	map[pos[0]+Addpos[0]][pos[1]+Addpos[1]] = "\u15E7";
	map[pos[0]][pos[1]]= " ";
}

bool ColisionTest(string & FutureElement){
	// Return if the element is in the wall list
	string WallList[] = {"\u2550","\u2551","\u2554","\u2557","\u255A","\u255D" };
	if (find(begin(WallList),end(WallList),FutureElement) != end(WallList))return false;
	else return true;
}

/** bool BonusTouchTest(string & FuturElement){       //Vérifie si collision avec bonus
    string BonusList[] = {"¤"};
    if (find(begin(BonusList),end(BonusList),FuturElement) == end(BonusList)) return true;
    else return false;
}**/

bool GoingToJump(vector<vector<string>> & map,vector<int> & AddtoPos,vector<int> & pos){
	// Return true if the character is going to jump
	if (pos[0]+AddtoPos[0] < 0 || pos[0]+AddtoPos[0] > MapYSize(map) || pos[1]+AddtoPos[1] < 0 || pos[1]+AddtoPos[1] > MapXSize(map)-1 ) return true;
	else return false;
}

void Jump(vector<int> & pos,vector<int> Addpos, vector<vector<string>> & map){
	// Make the character jump
	map[pos[0]][pos[1]]= " ";
	if (pos[0] == 0 && Addpos[0] == -1){
		pos[0] = MapYSize(map);
	}
	else if (pos[0] == MapYSize(map) && Addpos[0] == 1){
		pos[0] = 0;
	}
	else if (pos[1] == 0 && Addpos[1] == -1){
		pos[1] = MapXSize(map)-1;
	}
	else if (pos[1] == MapXSize(map)-1 && Addpos[1] == 1){
		pos[1] = 0;
	}
	map[pos[0]][pos[1]]="\u15E7";
}

/** unsigned Scoress(0); **/

void MoveCharacter (vector<int> & pos,vector<vector<string>> & map){
	char x;
	x=getch();
	vector<int> Addtopos ;
	switch (x){
		case 'Z':
		case 'z':
			Addtopos = {-1,0};
			break;
		case 'Q':
		case 'q':
			Addtopos = {0,-1};
			break;
		case 'S':
		case 's':
			Addtopos = {1,0};
			break;
		case 'D':
		case 'd':
			Addtopos = {0,1};
			break;
	}
	if (GoingToJump(map,pos,Addtopos)){
		Jump(pos,Addtopos,map);
	}
	else if (ColisionTest(map[pos[0]+Addtopos[0]][pos[1]+Addtopos[1]])){
		MoveElt(map,pos,Addtopos);
		pos[0] += Addtopos[0];
		pos[1] += Addtopos[1];
	}
    /** else if (BonusTouchTest(map[pos[0]+Addtopos[0]][pos[1]+Addtopos[1]])){  //augmentation point
        Scoress = Scoress + 10;
    } **/
}

unsigned Calculatescoring(){
    unsigned scdqsd = Scoress;
    return scdqsd;
}
