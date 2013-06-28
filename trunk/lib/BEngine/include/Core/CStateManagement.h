#ifndef _CSTATE_MANAGEMENT_H_
#define _CSTATE_MANAGEMENT_H_

#include "Utils/CSingleton.h"
#include "bengine_header.h"

namespace BEngine
{
	class CState;
	class CStateManagement : public CSingleton<CStateManagement>
	{
		friend class CSingleton<CStateManagement>;

		CStateManagement();		

	protected:
		CState				*m_pCurrentState;
		CState				*m_pNextState;		

	public:
		virtual ~CStateManagement();

		virtual void		Update(bool isPause = false);
		virtual void		SwitchState(CState* pNextState);
	};
}

#endif