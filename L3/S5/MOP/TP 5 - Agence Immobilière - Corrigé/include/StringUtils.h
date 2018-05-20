//--------------------------------------------------------------------------------------------------
// Fichier     : StringUtils.h
// Description : Definition des methodes utilitaires pour l'utilisation de strings
//--------------------------------------------------------------------------------------------------

#ifndef __STRINGUTILS_H
#define __STRINGUTILS_H

#include <string>

void	EmptyBuffer			(void);
void	ReadString			(std::string & str);
int		ReadIntBetween		(int minValue, int maxValue);
float	ReadFloatBetween	(float minValue, float maxValue);

#endif // __STRINGUTILS_H
