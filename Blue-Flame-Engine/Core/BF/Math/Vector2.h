#pragma once
#include <iostream>

namespace BF
{
	namespace Math
	{
		template<typename T>
		struct Vector2
		{
			T x;
			T y;

			Vector2();
			Vector2(T value);
			Vector2(T x, T y);
			~Vector2();

			T Dot(const Vector2& vector) const;
			T Distance(const Vector2& vector) const;
			T Magnitude() const;
			Vector2 Direction(const Vector2& vector) const;
			Vector2 Normalize() const;
			Vector2 Center() const;
			Vector2 Min();
			Vector2 Max();

			Vector2& operator+=(const Vector2& right);
			Vector2& operator-=(const Vector2& right);
			Vector2& operator*=(const Vector2& right);
			Vector2& operator/=(const Vector2& right);

			bool operator>(const Vector2& right);
			bool operator>=(const Vector2& right);
			bool operator<(const Vector2& right);
			bool operator<=(const Vector2& right);

			bool operator==(const Vector2& right);
			bool operator!=(const Vector2& right);

			friend Vector2 operator+(const Vector2& left, const Vector2& right) { return Vector2(left.x + right.x, left.y + right.y); }
			friend Vector2 operator-(const Vector2& left, const Vector2& right) { return Vector2(left.x - right.x, left.y - right.y); }
			friend Vector2 operator*(const Vector2& left, const Vector2& right) { return Vector2(left.x * right.x, left.y * right.y); }
			friend Vector2 operator/(const Vector2& left, const Vector2& right) { return Vector2(left.x / right.x, left.y / right.y); }

			friend std::ostream& operator<<(std::ostream& os, const Vector2& vector) { return os << "{" << vector.x << ", " << vector.y << "}"; }
		};

#include "Vector2.inl"

		typedef Vector2<int> Vector2i;
		typedef Vector2<float> Vector2f;
	}
}