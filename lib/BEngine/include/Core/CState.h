#ifndef _CSTATE_H_
#define _CSTATE_H_

namespace BEngine
{
	//This is abstract class, every state must be inherit from this class
	class CState
	{
	public:
		CState()			{};
		virtual ~CState()	{};

		//abstract function
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void Exit() = 0;
	};
}

#endif