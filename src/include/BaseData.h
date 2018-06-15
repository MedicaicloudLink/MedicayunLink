#include "include/Address.h"

#pragma once

namespace MedicayunLink
{
	#define DataAddress char[256];
	class BaseData{
		protected:
			DataAddress m_dataid;
			Address m_Owner;
	}
}
