#include "Core/CStateManagement.h"

#include "Core/CState.h"

namespace BEngine
{
	CStateManagement::CStateManagement() : m_pCurrentState(0), m_pNextState(0)
	{
	}

	CStateManagement::~CStateManagement()
	{
	}

	void CStateManagement::Update(bool isPause)
	{
		//state changed
		if (m_pCurrentState != m_pNextState)
		{
			if (m_pCurrentState)
				m_pCurrentState->Exit();

			if (m_pNextState)
			{
				m_pCurrentState = m_pNextState;
				m_pCurrentState->Init();				
			}
		}

		if (m_pCurrentState)
		{
			if (!isPause)
				m_pCurrentState->Update();

			m_pCurrentState->Render();
		}
	}

	void CStateManagement::SwitchState(CState *pNextState)
	{
		m_pNextState = pNextState;
	}
}