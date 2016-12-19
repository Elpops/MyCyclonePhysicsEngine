#pragma once
#include "core.h"



/* Une particuel est l'objet le plus simple
qui peut �tre simul� dans un syst�me physique
*/
using namespace cyclone;


class Particle
{

protected :

	/* Position de la particule dans l'espace
	*/

	Vector3 position;

	/* Vitesse de la particule dans l'espace
	*/

	Vector3 vitesse;

	/* Acceleration de la particule dans l'espace. Cette valeur peut �tre utilis�e
	pour l'acc�l�ration de la gravi� ou toute autre valeur cens�e �tre constante
	*/

	Vector3 acceleration;







};