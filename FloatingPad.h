#pragma once
#include "Plants.h"

class floatingPad : public Plants
{
private:

public:
	floatingPad();
	floatingPad(string, int, int);
	void Fire();
	void destroyPea(int);

	int getX() override;
	int getY() override;
	void drawPlant();
};
