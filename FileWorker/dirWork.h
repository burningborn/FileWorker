#pragma once
#include <iostream>
#include "entrance.h"

using namespace std;

class dirWork :
    public entrance
{
public:
	dirWork() :entrance{}{}
	~dirWork() {}

	void dirMenu();

	void make();
	void reMove();
	void reName();
	void coPy(const char* Source, const char* Destination);
	void moVe(const char* Source, const char* Destination);
};

