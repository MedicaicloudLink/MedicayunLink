#include "include/Address.h"

#pragma once

namespace MedicayunLink
{
	enum EncryptType{
		ET_Plaintext=0,
		ET_AES,
		ET_PubkeyEncrypt,
		ET_PrivatekeyEncrypt;
	};

	class Data:public BaseData
	{
		protected:
			DataAddress m_tempId;
			EncryptType m_plaintext;
			//TBD
	}
}
