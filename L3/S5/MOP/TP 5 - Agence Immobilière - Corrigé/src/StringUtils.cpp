//--------------------------------------------------------------------------------------------------
// Fichier     : StringUtils.h
// Description : Implementation des methodes utilitaires pour l'utilisation de strings
//--------------------------------------------------------------------------------------------------

#include "AgenceImmobiliere.h"

//--------------------------------------------------------------------------------------------------
/// Vide le buffer du flux d'entrée.
//--------------------------------------------------------------------------------------------------
void EmptyBuffer(void)
{
	std::cin.clear();
	std::cin.seekg(0, std::ios::end);
	if (!std::cin.fail())
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}
	else
	{
		std::cin.clear();
	}
}

//--------------------------------------------------------------------------------------------------
/// Lecture d'une chaine de caractères entrée par l'utilisateur.
/// @param str Reference de la chaine a remplir.
//--------------------------------------------------------------------------------------------------
void ReadString(std::string & str)
{
	EmptyBuffer();
	getline(std::cin, str);
	EmptyBuffer();
}

//--------------------------------------------------------------------------------------------------
/// Lecture d'un nombre entrier, avec attente d'une saisie valide, en précisant les bornes
/// inférieure et supérieure.
/// @param minValue Valeur de la borne inférieure.
/// @param maxValue Valeur de la borne supérieure.
/// @return La valeur entière saisie par l'utilisateur.
//--------------------------------------------------------------------------------------------------
int ReadIntBetween(int minValue, int maxValue)
{
	EmptyBuffer();

	int iOut = 0;

	bool bDone = false;
	while(!bDone)
	{
		std::cin >> iOut;
		if (std::cin.eof() || std::cin.bad())
		{
			std::cerr << "Erreur interne dans la saisie" << std::endl;
			EmptyBuffer();
		}
		else if (std::cin.fail())
		{
			std::cout << "Saisie incorrecte : Veuillez saisir un entier." << std::endl;
			EmptyBuffer();
		}
		else
		{
			if (iOut < minValue)
			{
				std::cout << "Saisie incorrecte : Saisir un entier superieur ou egal a " << minValue << std::endl;
			}
			else if (iOut > maxValue)
			{
				std::cout << "Saisie incorrecte : Saisir un entier inferieur ou egal a " << maxValue << std::endl;
			}
			else
			{
				bDone = true;
			}
		}
	}

	EmptyBuffer();

	return(iOut);
}

//--------------------------------------------------------------------------------------------------
/// Lecture d'un nombre flottant, avec attente d'une saisie valide, en précisant les bornes
/// inférieure et supérieure.
/// @param minValue Valeur de la borne inférieure.
/// @param maxValue Valeur de la borne supérieure.
/// @return La valeur flottante saisie par l'utilisateur.
//--------------------------------------------------------------------------------------------------
float ReadFloatBetween(float minValue, float maxValue)
{
	EmptyBuffer();

	float fOut = 0.0;
	bool bDone = false;

	while (!bDone)
	{
		std::cin >> fOut;

		if (std::cin.eof() || std::cin.bad())
		{
			std::cerr << "Erreur interne dans la saisie" << std::endl;
			EmptyBuffer();
		}
		else if (std::cin.fail())
		{
			std::cout << "Saisie incorrecte : Veuillez saisir un reel." << std::endl;
			EmptyBuffer();
		}
		else
		{
			if (fOut < minValue)
			{
				std::cout << "Saisie incorrecte : Saisir un reel superieur ou egal a " << minValue << std::endl;
			}
			else if (fOut > maxValue)
			{
				std::cout << "Saisie incorrecte : Saisir un reel inferieur ou egal a " << maxValue << std::endl;
			}
			else
			{
				bDone = true;
			}
		}
	}
	
	EmptyBuffer();

	return(fOut);
}
