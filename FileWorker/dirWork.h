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
	void coPy(const char* Src, const char* Dst);
	void moVe(const char* Src, const char* Dst);
	void showDir();
};

