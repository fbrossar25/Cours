#ifndef DISPLAYMESSAGE_H
#define DISPLAYMESSAGE_H

#if defined(_SYSTEM_LINUX)
	#include "stdio.h"
#elif defined(_SYSTEM_WINDOWS)
	#include "windows.h"
#endif

void DisplayMessage(const char * szMessage);

#endif