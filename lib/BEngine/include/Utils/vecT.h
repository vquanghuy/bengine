#pragma once

namespace math
{
	template<typename T>
	struct vec2
	{
		T x, y;

		//constructor
		vec2():x(0),y(0) {  };
		vec2(T x, T y) { this->x = x; this->y = y; };
	};

	template<typename T>
	struct vec3
	{
		T x, y, z;

		//constructor
		vec3():x(0),y(0),z(0) {  };
		vec3(T x, T y) { this->x = x; this->y = y; this->z = z; };
	};

	template<typename T>
	struct vec4
	{
		T x, y, z, w;

		//constructor
		vec4():x(0),y(0),z(0),w(0) {  };
		vec4(T x, T y) { this->x = x; this->y = y; this->z = z; this->w = w; };
	};
}