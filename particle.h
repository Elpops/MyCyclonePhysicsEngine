#pragma once
#include "core.h"



/* Une particuel est l'objet le plus simple
qui peut être simulé dans un système physique
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

	/* Acceleration de la particule dans l'espace. Cette valeur peut être utilisée
	pour l'accélération de la gravié ou toute autre valeur censée être constante
	*/

	Vector3 acceleration;







};