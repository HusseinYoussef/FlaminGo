#pragma once
#include "definitions.h"
#include "GoEngine.h"
using namespace std;
void test1();
void test2();

int main()
{
	test2();
	return 0;
}


void test1() {
	GoEngine engine;

	State state;
	// cout << "...testing compute score..." << endl;
	Score s(0, 0);// = engine.computeScore(state);
				  // cout << "black score = " << s.black << ", white score = " << s.white << endl;

	CellState cells[13][13]{
		EMPTY,EMPTY,EMPTY,EMPTY,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,EMPTY,EMPTY,EMPTY,
		EMPTY,EMPTY,EMPTY,EMPTY,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,EMPTY,EMPTY,EMPTY,
		EMPTY,EMPTY,EMPTY,EMPTY,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,
		BLACK,WHITE,WHITE,EMPTY,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
		BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,
		BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,EMPTY,EMPTY,
		EMPTY,EMPTY,EMPTY,BLACK,BLACK,WHITE,WHITE,BLACK,WHITE,BLACK,EMPTY,EMPTY,EMPTY,
		EMPTY,EMPTY,EMPTY,EMPTY,BLACK,EMPTY,WHITE,BLACK,EMPTY,BLACK,EMPTY,EMPTY,EMPTY,
		EMPTY,EMPTY,EMPTY,EMPTY,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,EMPTY,EMPTY,
		BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,EMPTY,EMPTY,
		BLACK,BLACK,WHITE,WHITE,EMPTY,EMPTY,EMPTY,EMPTY,WHITE,WHITE,BLACK,EMPTY,EMPTY,
		BLACK,WHITE,WHITE,WHITE,EMPTY,EMPTY,EMPTY,EMPTY,WHITE,BLACK,BLACK,EMPTY,EMPTY,
		EMPTY,WHITE,WHITE,WHITE,EMPTY,EMPTY,EMPTY,EMPTY,WHITE,WHITE,BLACK,EMPTY,EMPTY
	}; // 82 black, 77 white
	for (int i = 0; i<13; i++) {
		for (int j = 0; j<13; j++) {
			state(i, j) = cells[i][j];
		}
	}
	//     for (int i = 0; i<13; i++){
	//     for (int j=0;j<13;j++){
	//         cout << state(i,j) << " ";
	//     }
	//     cout << endl;
	// }

	s = engine.computeScore(state);
	cout << "black score = " << s.black << ", white score = " << s.white << endl;
}


void test2() {
	GoEngine engine;

	State state;
	// cout << "...testing compute score..." << endl;
	Score s(0, 0);// = engine.computeScore(state);
				  // cout << "black score = " << s.black << ", white score = " << s.white << endl;

	CellState cells[13][13]{
		//    0     1     2     3    4      5     6     7     8    9     1 0   11    12
		EMPTY,EMPTY,EMPTY,EMPTY,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,EMPTY,EMPTY,EMPTY,// 0
		EMPTY,EMPTY,EMPTY,EMPTY,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,EMPTY,EMPTY,EMPTY,//1
		EMPTY,EMPTY,EMPTY,EMPTY,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,//2
		BLACK,WHITE,WHITE,EMPTY,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,//3
		BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,//4
		BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,EMPTY,EMPTY,//5
		EMPTY,EMPTY,EMPTY,BLACK,BLACK,WHITE,WHITE,BLACK,WHITE,BLACK,EMPTY,EMPTY,EMPTY,//6
		EMPTY,EMPTY,EMPTY,EMPTY,BLACK,EMPTY,WHITE,BLACK,EMPTY,BLACK,EMPTY,EMPTY,EMPTY,//7
		EMPTY,EMPTY,EMPTY,EMPTY,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,EMPTY,EMPTY,//8
		BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,EMPTY,EMPTY,//9
		BLACK,BLACK,WHITE, BLACK ,EMPTY,EMPTY,EMPTY,EMPTY,WHITE,WHITE,BLACK,EMPTY,EMPTY,//10
		BLACK,WHITE,WHITE, BLACK ,EMPTY,EMPTY,EMPTY,EMPTY,WHITE,BLACK,BLACK,EMPTY,EMPTY,//11
		EMPTY,WHITE,WHITE, BLACK ,EMPTY,EMPTY,EMPTY,EMPTY,WHITE,WHITE,BLACK,EMPTY,EMPTY //12
	}; // 82 black, 77 white
	for (int i = 0; i<13; i++) {
		for (int j = 0; j<13; j++) {
			state(i, j) = cells[i][j];
		}
	}
	//     for (int i = 0; i<13; i++){
	//     for (int j=0;j<13;j++){
	//         cout << state(i,j) << " ";
	//     }
	//     cout << endl;
	// }
	State prev = state;
	prev(12, 0) = BLACK;
	prev(12, 1) = EMPTY;
	prev(12, 2) = EMPTY;
	prev(11, 1) = EMPTY;
	// prev(11,2) = EMPTY;
	// prev(10,2) = EMPTY;
	cout << engine.isValidMove(state, prev, Action(BLACK, 12, 0)) << endl;
}
