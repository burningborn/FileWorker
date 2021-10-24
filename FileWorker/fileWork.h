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
	void coPy(const char* Src, const char* Dst);
	void moVe(const char* Src, const char* Dst);
	void searchMask();
};

