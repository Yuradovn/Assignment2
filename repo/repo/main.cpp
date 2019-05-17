#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Header.h"
using namespace std;
int main(){
	string name = "premier_league.csv";
	string s;
	int num = 0;
	TeamNum(s, name, num);
	int *games = new int[num];
	int *points = new int[num];
	string *comands = new string[num];
	int** score = new int*[num];
	for (int i = 0; i < num; i++) {
		score[i] = new int[num];
	}

	Teams(s, comands, name, num);
	Score(s, score, name, num);
	Points(points, score, num);
	GamesCounter(num, score, games);
	SortTeams(points, comands, num, games);
}