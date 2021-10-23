#pragma once
#include <iostream>
#include "entrance.h"

using namespace std;

class fileWork :
    public entrance
{
public:
    fileWork():entrance{}{}
	~fileWork(){}
	
	void fileMenu();

	void make();
	void reMove();
	void reName();
	void coPy(const char* Source, const char* Destination);
	void moVe(const char* Source, const char* Destination);
};

