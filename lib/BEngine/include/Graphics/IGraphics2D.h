#ifndef _IGRAPHICS2D_H_
#define _IGRAPHICS2D_H_

namespace BEngine
{
	class IGraphics2D
	{
	public:
		virtual void	Initialize() = 0;

		virtual void	Clear(math::vec4f color) = 0;
		virtual void	Clear(math::vec4i color) = 0;

		virtual void	SetColor(math::vec4f color) = 0;
		virtual void	SetColor(math::vec4i color) = 0;

		virtual void	Flush() = 0;

		virtual void	DrawRect(math::rectf rect) = 0;

		virtual void	DrawLine(math::vec2f start, math::vec2f end) = 0;
		virtual void	DrawLine(math::vec2i start, math::vec2i end) = 0;

		virtual void	DrawTriangle(math::vec2f p1, math::vec2f p2, math::vec2f p3) = 0;
		virtual void	DrawTriangle(math::vec2i p1, math::vec2i p2, math::vec2i p3) = 0;

		virtual void	FillRect(math::rectf rect) = 0;
		virtual void	FillTriangle(math::vec2f p1, math::vec2f p2, math::vec2f p3) = 0;
		virtual void	FillTriangle(math::vec2i p1, math::vec2i p2, math::vec2i p3) = 0;
	};
}

#endif