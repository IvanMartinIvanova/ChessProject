#pragma once
#include <map>
#include <vector>
#include <string>

using namespace std;

class VecTabl
{
	char file;
	int row;
	std::string zona;
public:
	VecTabl();
	VecTabl(char fin, int rin, std::string zona);
	friend class piezagraf;
};

