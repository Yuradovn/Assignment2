#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void TeamNum(string s, string name, int &num);
void Score(string s, int **score, string name, int num);
void Teams(string s, string *comands, string name, int num);
void GamesCounter(int num, int **score, int *games);
void Points(int *points, int **score, int num);
