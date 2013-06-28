#pragma once

namespace BEngine
{
	struct DisplayMode
	{
		DisplayMode():size(640, 480) { };
		math::vec2u		size;		
	};
}