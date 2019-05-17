#include "Header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void CommandNum(string s, string name, int &num)
{
	ifstream file;
	file.open(name);
	while (!file.eof()) {
		getline(file, s);
		num++;
	}
}