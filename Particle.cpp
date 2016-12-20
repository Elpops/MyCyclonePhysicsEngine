#include "Particle.h"
#include <assert.h>



using namespace cyclone;

void Particle::integrate(real duration)
{
	//On n'intègre pas les objets de masse infinie

	if (inverseMass <= 0.0f) return;
	assert(duration > 0.0);

	//On met à jour la position
	position.addScaledVector(velocity, duration);

	//On calcule la résultante de l'accélération (toutes les forces appliquées multipliées par l'inverse de la masse)

	Vector3 resultingAcc = acceleration;

	//On met à jour la vitesse

	velocity.addScaledVector(acceleration, duration);

	//On impose les frottements

	velocity *= real_pow(damping, duration);

	//On supprime toutes les forces appliquées pour repartir à zéro à la prochaine frame

	clearAccumulator();


}

void Particle::setMass(const real mass)
{
	assert(mass > 0.0);
	inverseMass = ((real) 1.0 ) / mass;

}

real Particle::getMass() const
{
	if (inverseMass == 0)
	{
		return REAL_MAX;
	}
	return ((real) 1.0) / inverseMass;
}

void Particle::setInverseMass(const real inverseMass)
{
	Particle::inverseMass = inverseMass;
}

real Particle::getInverseMass() const
{
	return inverseMass;
}

bool Particle::hasFiniteMass() const
{
	return (inverseMass >= 0.0f);
}

void Particle::setDamping(const real damping)
{
	Particle::damping = damping;
}

real Particle::getDamping() const
{
	return damping;
}

void Particle::setPosition(const Vector3 & position)
{
	Particle::position = position;
}

void Particle::setPosition(const real x, const real y, const real z)
{
	position.x = x;
	position.y = y;
	position.z = z;

}

Vector3 Particle::getPosition() const
{
	return position;
}

void Particle::getPosition(Vector3 * position) const
{
	*position = Particle::position;
}

void Particle::setVelocity(const Vector3 & velocity)
{
	Particle::velocity = velocity;
}

void Particle::setVelocity(const real x, const real y, const real z)
{
	velocity.x = x;
	velocity.y = y;
	velocity.z = z;

}

Vector3 Particle::getVelocity() const
{
	return velocity;
}

void Particle::getVelocity(Vector3 * velocity) const
{
	*velocity = Particle::velocity;
}

void Particle::setAcceleration(const Vector3 & acceleration)
{
	Particle::acceleration = acceleration;
}

void Particle::setAcceleration(const real x, const real y, const real z)
{
	acceleration.x = x;
	acceleration.y = y;
	acceleration.z = z;
}

Vector3 Particle::getAcceleration() const
{
	return acceleration;
}

void Particle::getAcceleration(Vector3 * acceleration) const
{
	*acceleration = Particle::acceleration;
}

void Particle::clearAccumulator()
{
	forceAccum.clear();
}

void Particle::addForce(const Vector3 & force)
{
	forceAccum += force;
}

real Particle::kineticEnergy()
{
	return (1 / inverseMass)*(1 / 2)*velocity.magnitude*velocity.magnitude;
}
