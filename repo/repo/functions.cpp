#include "Header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void TeamNum(string s, string name, int &num)
{
	ifstream file;
	file.open(name);
	while (!file.eof()) {
		getline(file, s);
		num++;
	}
}

void Score(string s, int **score, string name, int num)
{
	ifstream afile(name);
	string N;
	for (int k = 0; k < num; k++)
	{
		getline(afile, s);
		size_t a = s.length();
		int i = 0;

		for (int j = 0; j < a; j++)
		{
			if (isdigit(s[j]) || s[j] == 'x')
			{
				N = s[j];
				if (N == "x") {
					score[i][k] = -1;
					score[i + 1][k] = -1;
					i += 2;
				}
				else {
					score[i][k] = stoi(N);
					i++;
				}
			}
		}
	}
	afile.close();
}

void Teams(string s, string *comands, string name, int num)
{
	ifstream file;
	file.open(name);

	for (int i = 0; i < num; i++)
	{
		size_t a;
		getline(file, s);
		a = s.find(",");
		comands[i] = s.substr(0, a);
	}
	file.close();
}

void GamesCounter(int num, int **score, int *games) {
	for (int i = 0; i < num; i++) {
		games[i] = 0;
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (score[j][i] >= 0) {
				games[i]++;
			}
		}
		games[i] = games[i] / 2;
	}
}

void Points(int *points, int **score, int num)
{
	for (int i = 0; i < num; i++)
	{
		points[i] = 0;
		for (int j = 0; j < num; j = j + 2)
		{
			if (score[j][i] > score[j + 1][i])
			{
				points[i] = points[i] + 3;
			}


			else if (score[j][i] == score[j + 1][i])
			{
				points[i] = points[i] + 1;
			}

			else
			{
				points[i] = points[i] + 0;
			}
		}
	}
}