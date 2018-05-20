//--------------------------------------------------------------------------------------------------
// Fichier     : CVehicule.cpp
// Description : Implémentation de la classe permettant le stockage d'un vehicule.
//--------------------------------------------------------------------------------------------------

#include "Garage.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur
/// @param strImmatriculation Immatriculation du vehicule.
/// @param statut 			  Statut du vehicule.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CVehicule::CVehicule(const std::string & strImmatriculation, CVehicule::EStatut statut)
: m_strImmatriculation(immatriculation)
, m_statut(statut)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CVehicule::~CVehicule(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Retourne le statut du vehicule
/// @return Statut du vehicule.
//--------------------------------------------------------------------------------------------------
CVehicule::EStatut CVehicule::GetStatut(void) const
{
	return(m_statut);
}

//--------------------------------------------------------------------------------------------------
/// Definis l'immatriculation du vehicule
/// @param strImmatriculation Immatriculation du vehicule.
//--------------------------------------------------------------------------------------------------
void CVehicule::SetImmatriculation(const std::string & strImmatriculation)
{
	assert(m_strImmatriculation != "");
	m_strImmatriculation = immatriculation;
}

//--------------------------------------------------------------------------------------------------
/// Retourne l'immatriculation du vehicule
/// @return Immatriculation du vehicule.
//--------------------------------------------------------------------------------------------------
const std::string & CVehicule::GetImmatriculation(void) const
{
	return(m_strImmatriculation);
}