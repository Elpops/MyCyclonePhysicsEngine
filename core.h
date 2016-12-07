#pragma once
#include "precision.h"



namespace cyclone {
	
	
	//Encapsule un vecteur en trois dimensions. 
	//Quatre membres sont alloués pour assurer l'alignement en mémoire

	class Vector3
	{
	public :
		real x;
		real y;
		real z;

	private :
		real pad;
	public :
		//Constructeur par défaut
		Vector3(): x(0), y(0), z(0) {}
		//Constructeur explicite
		Vector3(const real x, const real y, const real z)
			: x(x), y(y), z(z) {}

		//Inverse le vecteur

		void invert()
		{
			x = -x;
			y = -y;
			z = -z;
		}

		real magnitude() const
		{
			return real_sqrt(x*x + y*y + z*z);
		}

		real squareMagnitude() const
		{
			return x*x + y*y + z*z;
		}

		void normalize()
		{
			real l = magnitude();
			if (l > 0)
			{
				(*this) *= ((real)1) / l;
			}
		}

		void operator*=(const real value)
		{
			x *= value;
			y *= value;
			z *= value;

		}

		void operator+=(const Vector3& v)
		{
			x += v.x;
			y += v.x;
			z += v.x;

		}

		void operator-=(const Vector3& v)
		{
			x -= v.x;
			y -= v.x;
			z -= v.x;

		}



		Vector3 operator*(const real value)
		{
			return Vector3(x*value, y*value, z*value);
		}


		Vector3 operator+(const Vector3& v)
		{
			return Vector3(x + v.x, y + v.y, z + v.z);
		}

		Vector3 operator-(const Vector3& v)
		{
			return Vector3(x - v.x, y - v.y, z - v.z);
		}

		void addScaleVector(const Vector3& v, real scale)
		{
			x += v.x*scale;
			y += v.y*scale;
			z += v.z*scale;

		}

		Vector3 componentProduct(const Vector3 &v) const
		{
			return Vector3(x*v.x, y*v.y, z*v.z);
		}

		void componentProductUpdate(const Vector3& v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
		}

		real scalarProduct(const Vector3 &v) const
		{
			return x*v.x + y*v.y + z*v.z;
		}

		real operator*(const Vector3 &v) const
		{
			return x*v.x + y*v.y + z*v.z;
		}
	};
}