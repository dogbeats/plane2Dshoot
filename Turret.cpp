#include "Turret.h"

GLint turretHealth[5];

void Turret::TurretHit(GLint turretNumber)
{
	if (turretHealth[turretNumber] < 100)
		turretHealth[turretNumber] += 50;
	//std::cout << turretHealth[turretNumber] << " \n";
}

GLint Turret::PollTurretHealth(GLint turretNumber)
{
	return turretHealth[turretNumber];
}