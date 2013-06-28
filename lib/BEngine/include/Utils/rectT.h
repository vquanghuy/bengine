#pragma once

namespace math
{
	template<typename T>
	struct rect
	{
		rect(T x, T y, T x2, T y2)
		{
			upperLeft = math::vec2<T>(x, y);
			lowerRight = math::vec2<T>(x2, y2);
		};

		rect(math::vec2<T> upperLeft, math::vec2<T> lowerRight)
		{
			this->upperLeft = upperLeft;
			this->lowerRight = lowerRight;
		};

		s32 getWidth()
		{
			return upperLeft.x - lowerRight.x;
		}

		s32 getHight()
		{
			return upperLeft.y - lowerRight.y;
		}

		math::vec2<T> upperLeft;
		math::vec2<T> lowerRight;
		
	};
}