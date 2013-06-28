#include "Graphics/CGLDriver.h"

namespace BEngine
{
	CGLDriver::CGLDriver() :	m_eCurrentMatrixMode(EGLD_MATRIXMODE_PROJECTION),
									m_isUseAlpha(false)
	{
		//set default value
		for (int i = 0; i < EGLD_ATTRIB_TEXCOOR - EGLD_ATTRIB_VERTEX + 1; i++)
		{
			m_isUseAttribPointer[i] = false;
		}

		//mapping attrib pointer
		m_iAttribMapping[EGLD_ATTRIB_VERTEX] = GL_VERTEX_ARRAY;
		m_iAttribMapping[EGLD_ATTRIB_NORMAL] = GL_NORMAL_ARRAY;
		m_iAttribMapping[EGLD_ATTRIB_COLOR] = GL_COLOR_ARRAY;
		m_iAttribMapping[EGLD_ATTRIB_TEXCOOR] = GL_TEXTURE_COORD_ARRAY;

		//set default for indicate
		for (int i = 0; i < EGLD_DEFAULT_MAX_INDIES; i++)
		{
			m_iAutoIndices[i] = i;
		}
	}

	CGLDriver::~CGLDriver()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	//set color function
	//////////////////////////////////////////////////////////////////////////
	void CGLDriver::SetColor(float red, float green, float blue, float alpha)
	{
		glColor4f(red/255.0f, green/255.0f, blue/255.0f, alpha/255.0f);
	}

	void CGLDriver::SetColor(math::vec4f color)
	{
		SetColor(color.x, color.y, color.z, color.w);
	}

	void CGLDriver::SetColor(math::vec4i color)
	{
		SetColor((float) color.x, (float) color.y, (float) color.z, (float) color.w);
	}

	//////////////////////////////////////////////////////////////////////////
	//Set Blending
	//////////////////////////////////////////////////////////////////////////
	void CGLDriver::EnableBlending(bool enable)
	{
		if (m_isUseAlpha != enable)
		{
			m_isUseAlpha = enable;

			if (m_isUseAlpha)
			{
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			} 
			else
			{
				glDisable(GL_BLEND);
			}
		}
	}

	bool CGLDriver::IsUseBlending()
	{
		return m_isUseAlpha;
	}

	//////////////////////////////////////////////////////////////////////////
	//Attribute pointer
	//////////////////////////////////////////////////////////////////////////
	void CGLDriver::AttributePointer(enum EGL30DriverAttribType attribType, s32 size, enum EGL30DriverPrimaryType primType, u32 stride, void* pointer)
	{
		switch(attribType)
		{
		case EGLD_ATTRIB_VERTEX:
			glVertexPointer(size, m_iAttribMapping[attribType], stride, pointer);
			break;

		case EGLD_ATTRIB_NORMAL:
			glNormalPointer(m_iAttribMapping[attribType], stride, pointer);
			break;

		case EGLD_ATTRIB_COLOR:
			glColorPointer(size, m_iAttribMapping[attribType], stride, pointer);
			break;

		case EGLD_ATTRIB_TEXCOOR:
			glTexCoordPointer(size, m_iAttribMapping[attribType], stride, pointer);
			break;
		}
	}


	//////////////////////////////////////////////////////////////////////////
	//Enable client state (enable / disable attrib pointer)
	//////////////////////////////////////////////////////////////////////////
	void CGLDriver::EnableAttribPointer(enum EGL30DriverAttribType attribType, bool isUse)
	{
		if (isUse)
		{
			if (m_isUseAttribPointer[attribType] == false)
			{
				m_isUseAttribPointer[attribType] = true;
				glEnableClientState(m_iAttribMapping[attribType]);
			}
		} 
		else
		{
			if (m_isUseAttribPointer[attribType] == true)
			{
				m_isUseAttribPointer[attribType] = false;
				glDisableClientState(m_iAttribMapping[attribType]);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	//Draw Array
	//////////////////////////////////////////////////////////////////////////
	void CGLDriver::DrawElements(enum EGL30DriverRenderMode mode, u32 numOfIndices, enum EGL30DriverPrimaryType primType, void *indices)
	{
		if (indices == 0)
		{
			indices = m_iAutoIndices;
			primType = EGLD_PRITYPE_UINT;
		}

		if (numOfIndices < EGLD_DEFAULT_MAX_INDIES)
		{
			glDrawElements(mode, numOfIndices, primType, indices);
		}
		else
		{
			LOGI("************ Num of Indices too hight - %d", numOfIndices);
		}
	}

	void CGLDriver::DrawElements(enum EGL30DriverRenderMode mode, u32 numOfIndices)
	{
		DrawElements(mode, numOfIndices, EGLD_PRITYPE_UINT, 0);
	}

	void CGLDriver::DrawArrays(enum EGL30DriverMatrixMode mode, u32 first, u32 size)
	{
		glDrawArrays(mode, first, size);
	}

	//////////////////////////////////////////////////////////////////////////
	//Clear screen
	//////////////////////////////////////////////////////////////////////////
	void CGLDriver::Clear(math::vec4f color)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(color.x / 255.0f, color.y / 255.0f, color.z / 255.0f, color.w / 255.0f);
	}

	//////////////////////////////////////////////////////////////////////////
	//Set viewport
	//////////////////////////////////////////////////////////////////////////
	void CGLDriver::SetViewport(math::rectf rect)
	{
		glViewport((GLsizei) rect.upperLeft.x, (GLsizei) rect.upperLeft.y, (GLsizei) rect.getWidth(), (GLsizei) rect.getHight());
	}

	//////////////////////////////////////////////////////////////////////////
	// Orthor
	//////////////////////////////////////////////////////////////////////////
	void CGLDriver::Orthor(float left, float right, float top, float bottom, float znear, float zfar)
	{
		glOrtho(left, right, bottom, top, znear, zfar);
	}

	//////////////////////////////////////////////////////////////////////////
	// Matrix mode
	//////////////////////////////////////////////////////////////////////////
	void CGLDriver::EnableMatrixMode(enum EGL30DriverMatrixMode mode)
	{
		if (mode != m_eCurrentMatrixMode)
		{
			m_eCurrentMatrixMode = mode;
			glEnable(m_eCurrentMatrixMode);
		}
	}

	void CGLDriver::PushMatrix(enum EGL30DriverMatrixMode mode)
	{
		EnableMatrixMode(mode);
		glPushMatrix();
	}

	void CGLDriver::PopMatrix(enum EGL30DriverMatrixMode mode)
	{
		EnableMatrixMode(mode);
		glPopMatrix();
	}

	void CGLDriver::LoadIdentity(enum EGL30DriverMatrixMode mode)
	{
		EnableMatrixMode(mode);
		glLoadIdentity();
	}
}