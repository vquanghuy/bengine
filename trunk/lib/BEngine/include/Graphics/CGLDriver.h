#ifndef _CGL_DRIVER_H_
#define _CGL_DRIVER_H_

#include "Utils/CSingleton.h"

#include "bengine.h"

//include for OpenGL
#include <gl/GL.h>
#include <gl/GLU.h>

#define EGLD_DEFAULT_MAX_INDIES		1024

namespace BEngine
{
	enum EGL30DriverAttribType
	{
		EGLD_ATTRIB_VERTEX,
		EGLD_ATTRIB_NORMAL,
		EGLD_ATTRIB_COLOR,
		EGLD_ATTRIB_TEXCOOR
	};

	enum EGL30DriverMatrixMode
	{
		EGLD_MATRIXMODE_PROJECTION = GL_PROJECTION,
		EGLD_MATRIXMODE_MODELVIEW = GL_MODELVIEW
	};

	enum EGL30DriverPrimaryType
	{
		EGLD_PRITYPE_FLOAT = GL_FLOAT,
		EGLD_PRITYPE_UINT = GL_UNSIGNED_INT,
		EGLD_PRITYPE_BYTE = GL_BYTE
	};

	enum EGL30DriverRenderMode
	{
		EGLD_RENDER_MODE_TRIANGLE = GL_TRIANGLES,
		EGLD_RENDER_MODE_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
		EGLD_RENDER_MODE_TRIANGLE_FAN = GL_TRIANGLE_FAN
	};

	class CGLDriver : public CSingleton<CGLDriver>
	{
		friend class CSingleton<CGLDriver>;

	private:
		bool					m_isUseAttribPointer[EGLD_ATTRIB_TEXCOOR - EGLD_ATTRIB_VERTEX + 1];
		u32				m_iAttribMapping[EGLD_ATTRIB_TEXCOOR - EGLD_ATTRIB_VERTEX + 1];
		u32				m_iAutoIndices[EGLD_DEFAULT_MAX_INDIES];
		EGL30DriverMatrixMode	m_eCurrentMatrixMode;
		bool					m_isUseAlpha;

	protected:
		//constructor and destructor
		CGLDriver();
		virtual ~CGLDriver();

	public:
		//////////////////////////////////////////////////////////////////////////
		//set color function
		//////////////////////////////////////////////////////////////////////////
		void		SetColor(float red, float green, float blue, float alpha);
		void		SetColor(math::vec4f color);
		void		SetColor(math::vec4i color);

		//////////////////////////////////////////////////////////////////////////
		//Set Blending
		//////////////////////////////////////////////////////////////////////////
		void		EnableBlending(bool enable);
		bool		IsUseBlending();

		//////////////////////////////////////////////////////////////////////////
		//Attribute pointer
		//////////////////////////////////////////////////////////////////////////
		void		AttributePointer(enum EGL30DriverAttribType attribType, s32 size, enum EGL30DriverPrimaryType primType, u32 stride, void* pointer);
		

		//////////////////////////////////////////////////////////////////////////
		//Enable client state (enable / disable attrib pointer)
		//////////////////////////////////////////////////////////////////////////
		void		EnableAttribPointer(enum EGL30DriverAttribType attribType, bool isUse);

		//////////////////////////////////////////////////////////////////////////
		//Draw Array
		//////////////////////////////////////////////////////////////////////////
		void		DrawElements(enum EGL30DriverRenderMode, u32 numOfIndices, enum EGL30DriverPrimaryType primType, void *indices);
		void		DrawElements(enum EGL30DriverRenderMode, u32 numOfIndices);
		void		DrawArrays(enum EGL30DriverMatrixMode, u32 first, u32 size);

		//////////////////////////////////////////////////////////////////////////
		//Clear screen
		//////////////////////////////////////////////////////////////////////////
		void		Clear(math::vec4f color);

		//////////////////////////////////////////////////////////////////////////
		//Set viewport
		//////////////////////////////////////////////////////////////////////////
		void		SetViewport(math::rectf rect);

		//////////////////////////////////////////////////////////////////////////
		// Orthor
		//////////////////////////////////////////////////////////////////////////
		void		Orthor(float left, float right, float top, float bottom, float znear, float zfar);

		//////////////////////////////////////////////////////////////////////////
		// Matrix mode
		//////////////////////////////////////////////////////////////////////////
		void		EnableMatrixMode(enum EGL30DriverMatrixMode mode);
		void		PushMatrix(enum EGL30DriverMatrixMode mode);
		void		PopMatrix(enum EGL30DriverMatrixMode mode);
		void		LoadIdentity(enum EGL30DriverMatrixMode mode);
	};
}

#endif