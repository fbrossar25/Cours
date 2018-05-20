#include "DisplayMessage.h"

void DisplayMessage(const char * szMessage)
{
	#if defined(_SYSTEM_LINUX)
		printf("%s",szMessage);
	#elif defined(_SYSTEM_WINDOWS)
		MessageBox(NULL,szMessage,"Message", MB_OK);
	#endif
}