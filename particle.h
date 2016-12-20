#pragma once
#include "core.h"



/* Une particuel est l'objet le plus simple
qui peut être simulé dans un système physique
*/
using namespace cyclone;


class Particle
{

	protected:

	/* Position de la particule dans l'espace
	*/

	Vector3 position;

	/* Vitesse de la particule dans l'espace
	*/

	Vector3 velocity;

	/* Acceleration de la particule dans l'espace. Cette valeur peut être utilisée
	pour l'accélération de la gravié ou toute autre valeur censée être constante
	*/

	Vector3 acceleration;

	/*
	variable qui simule les frottements;
	*/

	real damping;

	/*
	Contient la valeur de l'inverse de la masse de la particule. Il est plus utile de
	stocker la valeur de l'inverse de la masse que celle de la masse puisqu'en simulation
	temps réel il est plus utile d'avoir des objets de masse infini (1/m = 0 ) que de
	masse zéro (très instable et pas très pertinent).
	*/

	real inverseMass;



	/*
	contient le vecteur force devant être appliqué à la particule à l'itération suivante seulement.
	Ce vecteur est annulé à chaque étape d'intégration.
	*/
	Vector3 forceAccum;

	public :

		/*
		Intègre la position et l'accélération de la particule pour l'itération suivante
		*/

		void integrate(real duration);
	//Ensemble de setteurs et de getteurs


	
	void setMass(const real mass);
	real getMass() const;
	void setInverseMass(const real inverseMass);
	real getInverseMass() const;
	bool hasFiniteMass() const;
	void setDamping(const real damping);
	real getDamping() const;
	
	//Position

	void setPosition(const Vector3 &position);
	void setPosition(const real x, const real y, const real z);
	Vector3 getPosition() const;
	void getPosition(Vector3 * position) const;

	//Velocity

	void setVelocity(const Vector3 &velocity);
	void setVelocity(const real x, const real y, const real z);
	Vector3 getVelocity() const;
	void getVelocity(Vector3 * velocity) const;

	//Acceleration

	void setAcceleration(const Vector3 &acceleration);
	void setAcceleration(const real x, const real y, const real z);
	Vector3 getAcceleration() const;
	void getAcceleration(Vector3 * acceleration) const;


	void clearAccumulator();
	void addForce(const Vector3 &force);


	/*Calcule l'énergie cinétique de la particule
	*/

	real kineticEnergy();



};