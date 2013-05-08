#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "esUtil.h"

class Camera
{
	ESMatrix m_matCamera;

public:
	void		Init();
	ESMatrix	GetCamera();
	void		ResetCamera();

	void		MoveX(float distance);
	void		MoveY(float distance);
	void		MoveZ(float distance);

	void		RotX(float angle);
	void		RotY(float angle);
	void		RotZ(float angle);
};

#endif