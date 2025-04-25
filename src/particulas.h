#pragma once
class particulas
{
public:
	int maxrad = 2000;
	int maxpart = 5000;
	int maxz = 10;
	double teta, fi, rad, z;
public:
	void dibujac(double orgx, double orgy, double orgz);
	void dibujae(double orgx, double orgy, double orgz);
};