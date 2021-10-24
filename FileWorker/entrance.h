#pragma once
#include <iostream>
using namespace std;

class entrance
{
protected:

	entrance() {};
	~entrance() {};

public:

	//void inputMenu();

	virtual void make() = 0;
	virtual void reMove() = 0;
	virtual void reName() = 0;
	virtual void coPy(const char* Src, const char* Dst) = 0;
	virtual void moVe(const char* Src, const char* Dst) = 0;
};

