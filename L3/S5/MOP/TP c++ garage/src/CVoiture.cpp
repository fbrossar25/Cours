//--------------------------------------------------------------------------------------------------
// Fichier     : CVoiture.cpp
// Description : Implémentation de la classe permettant le stockage d'une voiture.
//--------------------------------------------------------------------------------------------------

#include "Garage.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur.
/// @param strImmatriculation 	Immatriculation du vehicule.
/// @param EStatut 				Statut du vehicule.
/// @param nbPlaces 			Nombre de places dans le vehicule.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CVoiture::CVoiture(const std::string & strImmatriculation, CVehicule::EStatut statut, unsigned int nbPlaces)
: CVehicule(strImmatriculation, statut)
, m_nbPlaces(nbPlaces)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CVoiture::~CVoiture(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Retourne le type du vehicule (@see CVehicule::EType)
/// @return Type du Vehicule.
//--------------------------------------------------------------------------------------------------
/*virtual*/ CVehicule::EType CVoiture::GetType(void) const
{
	return(e_type_voiture);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre de places dans la voiture
/// @return Nombre de places dans la voiture.
//--------------------------------------------------------------------------------------------------
unsigned int CVoiture::GetNbPlaces(void) const
{
	return(m_nbPlaces);
}

//--------------------------------------------------------------------------------------------------
/// Definis le nombre de places dans la voiture
/// @param  nbPlaces Le nombre de places dans la voiture.
//--------------------------------------------------------------------------------------------------
void CVoiture::SetNbPlaces(unsigned int nbPlaces)
{
	assert(nbPlaces > 0);
	m_nbPlaces = nbPlaces;
}

//--------------------------------------------------------------------------------------------------
/// Affiche la voiture.
//--------------------------------------------------------------------------------------------------
/*virtual*/ void CVoiture::Affiche(void)
{
	std::cout << "  Voiture\n";
	std::cout << "  " << GetImmatriculation() << "\n";
	std::cout << "  " << GetNbPlaces() << " places\n";
	std::cout << "\n";
}