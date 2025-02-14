#pragma once

#ifndef __UTILS_VECTOR3
#define __UTILS_VECTOR3

#include "MotorEngine/MotorEngineAPI.h"
#include <math.h>
#include <cmath>

namespace Ogre {
	template<int dism, typename T>
	class Vector;
	typedef Vector< 3, float > 	Vector3f;

	class Quaternion;
}

class btQuaternion;

namespace std {
	template <class T>
	struct char_traits;
	template <class _Elem, class _Traits>
	class basic_ostream;
	using ostream = basic_ostream<char, char_traits<char>>;
}

class btVector3;
class btQuaternion;

class FMOD_VECTOR;

namespace me {

	class __MOTORENGINE_API Vector3
	{

	public:
		float x, y, z;


		Vector3();
		Vector3(float a, float b, float c);
		Vector3(const Vector3& v);

		/**
		Returns the difference between this vector and another vector

		@param v The other vector to subtract from this vector
		@return The difference between this vector and the other vector
		*/
		Vector3 operator-(const Vector3& v);

		/**
		Returns the difference between this vector and another vector

		@param v The other vector to subtract from this vector
		@return The difference between this vector and the other vector
		*/
		Vector3 operator-=(const Vector3& v);

		/**
		Returns the sum of this vector and another vector

		@param v The other vector to add to this vector
		@return The sum of this vector and the other vector
		*/
		Vector3 operator+(const Vector3& v);

		/**
		Returns the sum of this vector and another vector

		@param v The other vector to add to this vector
		@return The sum of this vector and the other vector
		*/
		Vector3 operator+=(const Vector3& v);

		/**
		Returns the product of this vector and a scalar

		@param s The scalar to multiply this vector by
		@return The product of this vector and the scalar
		*/
		Vector3 operator*(const float& s);

		/**
		Returns the product of two vectors

		@param other The vector used in the product
		@return The final vector after the product
		*/
		Vector3 operator*(const Vector3& other);

		/**
		Returns the product of this vector and a scalar

		@param s The scalar to multiply this vector by
		@return The product of this vector and the scalar
		*/
		Vector3 operator*=(const float & s);

		/**
		Returns the division of two vectors

		@param other The vector used in the division
		@return The final vector after the division
		*/
		Vector3 operator/(const Vector3& other);

		/**
		Returns the division of two vectors

		@param s The scalar to divide this vector by
		@return The final vector after the division
		*/
		Vector3 operator/(const float& s);


		void operator=(const Vector3& v);
		void operator=(const Vector3* v);
		void operator=(const btVector3&v);

		/**
		Check if this vector is equal to another vector "v"

		@param v The other vector to check equality with
		@return True if the two vectors are equal, false otherwise
		*/
		bool operator==(const Vector3& v);

		/**
		Check if this vector is not equal to another vector "v"

		@param v The other vector to check inequality with
		@return True if the two vectors are not equal, false otherwise
		*/
		bool operator!=(const Vector3& v);

		/**
		Returns the linear interpolation between "a" and "b" by a factor of "f"

		@param a The starting vector to interpolate from
		@param b The ending vector to interpolate to
		@param f The interpolation factor, a value between 0 and 1
		*/
		static Vector3 Lerp(const Vector3 & a, const Vector3 & b, float f);

		/**
		Calculate the magnitude (length) of the vector

		@return The magnitude of the vector
		*/
		float magnitude();

		/**
		Normalize the vector to have a magnitude of 1
		*/
		Vector3 normalize();

		/*
		Performs the translation of the vector in a given direction and distance
		from a given startPoint.
		@param StartPoint the origin position of the vector to translate
		@param Direction the vector that describes the direction and the distance to translate
		@return The new vector, that is the translation of the original
		*/
		Vector3 translate(Vector3 startPoint, Vector3 direction);

		/**
		Calculate the dot product between this vector and another vector "v"

		@param v The other vector to calculate the dot product with
		@return The dot product of the two vectors
		*/
		float dot(const Vector3& v);

		/**
		Calculate the cross product between this vector and another vector "v"

		@param v The other vector to calculate the cross product with
		@return The cross product of the two vectors
		*/
		Vector3 cross(const Vector3& v);

		/**
		Returns the linear interpolation between "a" and "b" by a factor of "f"
		*/
		static Vector3 Zero();

		/**
		Returns a unit vector pointing upwards along the y-axis
		*/
		static Vector3 Up();

		/**
		Returns a unit vector pointing downwards along the y-axis
		*/
		static Vector3 Down();

		/**
		Returns a unit vector pointing to the left along the x-axis
		*/
		static Vector3 Left();

		/**
		Returns a unit vector pointing to the right along the x-axis
		*/
		static Vector3 Right();

		/**
		Returns a unit vector pointing backwards along the z-axis
		*/
		static Vector3 Back();

		/**
		Returns a unit vector pointing forwards along the z-axis
		*/
		static Vector3 Forward();

		/**
		Returns the distance between this vector and another vector "v"

		@param v The other vector
		@return The distance between the two vectors
		*/
		float distance(const Vector3 & v);

		/**
		Returns the conversion of a Vector3 to an Ogre::Vector3f
		*/
		Ogre::Vector3f v3ToOgreV3() const;

		/**
		Returns the conversion of a Vector3 to an btVector3
		*/
		btVector3 v3ToBulletV3() const;

		/**
		Returns the conversion of a Vector3 to an FMOD_VECTOR
		*/
		FMOD_VECTOR v3ToFmodV3() const;

		/**
		Returns a formatted string representation of the vector
		
		@param os The output stream to write to
		@param v The vector to format
		@return The output stream with the formatted string
		*/
		friend std::ostream& operator<<(std::ostream& os, const Vector3 & v);

	};
}

#endif