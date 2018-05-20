//--------------------------------------------------------------------------------------------------
// Fichier     : CUtilitaire.cpp
// Description : Implémentation de la classe permettant le stockage d'une voiture.
//--------------------------------------------------------------------------------------------------

#include "Garage.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur.
/// @param strImmatriculation 	Immatriculation du vehicule.
/// @param EStatut 				Statut du vehicule.
/// @param nbPlaces 			Nombre de places dans le vehicule.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CUtilitaire::CUtilitaire(const std::string & strImmatriculation, CVehicule::EStatut statut, float volume)
: CVehicule(strImmatriculation, statut)
, m_volume(volume)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CUtilitaire::~CUtilitaire(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Retourne le type du vehicule (@see CVehicule::EType)
/// @return Type du Vehicule.
//--------------------------------------------------------------------------------------------------
/*virtual*/ CVehicule::EType CUtilitaire::GetType(void) const
{
	return(e_type_utilitaire);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le volume du vehicule
/// @return Volume du vehicule.
//--------------------------------------------------------------------------------------------------
float CUtilitaire::GetVolume(void) const
{
	return(m_volume);
}

//--------------------------------------------------------------------------------------------------
/// Definis le volume du vehicule
/// @param  volume Le volume du vehicule.
//--------------------------------------------------------------------------------------------------
void CUtilitaire::SetVolume(float volume)
{
	assert(volume > 0);
	m_volume = volume;
}

//--------------------------------------------------------------------------------------------------
/// Affiche le vehicule utilitaire.
//--------------------------------------------------------------------------------------------------
/*virtual*/ void CUtilitaire::Affiche(void)
{
	std::cout << "  Vehicule utilitaire\n";
	std::cout << "  " << GetImmatriculation() << "\n";
	std::cout << "  " << GetVolume() << " m cube\n";
	std::cout << "\n";
}