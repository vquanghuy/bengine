#include "Camera.h"

void Camera::Init()
{
	esMatrixLoadIdentity(&m_matCamera);
}

ESMatrix Camera::GetCamera()
{
	return m_matCamera;
}

void Camera::ResetCamera()
{
	esMatrixLoadIdentity(&m_matCamera);
}

void Camera::MoveX(float distance)
{
	esTranslate(&m_matCamera, distance, 0, 0);
}

void Camera::MoveY(float distance)
{
	esTranslate(&m_matCamera, 0, distance, 0);
}

void Camera::MoveZ(float distance)
{
	esTranslate(&m_matCamera, 0, 0, distance);
}

void Camera::RotX(float angle)
{
	esRotate(&m_matCamera, angle, 1, 0, 0);
}

void Camera::RotY(float angle)
{
	esRotate(&m_matCamera, angle, 0, 1, 0);
}

void Camera::RotZ(float angle)
{
	esRotate(&m_matCamera, angle, 0, 0, 1);
}