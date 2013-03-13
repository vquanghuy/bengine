#ifndef _IGRAPHICS2D_H_
#define _IGRAPHICS2D_H_

namespace BEngine
{
	class IGraphics2D
	{
	public:
		virtual void	Initialize() = 0;

		virtual void	Clear(SColor4f color) = 0;
		virtual void	Clear(SColor4i color) = 0;

		virtual void	SetColor(SColor4f color) = 0;
		virtual void	SetColor(SColor4i color) = 0;

		virtual void	Flush() = 0;

		virtual void	DrawRect(SRect rect) = 0;

		virtual void	DrawLine(SPoint2f start, SPoint2f end) = 0;
		virtual void	DrawLine(SPoint2i start, SPoint2i end) = 0;

		virtual void	DrawTriangle(SPoint2f p1, SPoint2f p2, SPoint2f p3) = 0;
		virtual void	DrawTriangle(SPoint2i p1, SPoint2i p2, SPoint2i p3) = 0;

		virtual void	FillRect(SRect rect) = 0;
		virtual void	FillTriangle(SPoint2f p1, SPoint2f p2, SPoint2f p3) = 0;
		virtual void	FillTriangle(SPoint2i p1, SPoint2i p2, SPoint2i p3) = 0;
	};
}

#endif