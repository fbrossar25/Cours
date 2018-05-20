//--------------------------------------------------------------------------------------------------
// Fichier     : CMoto.cpp
// Description : Implémentation de la classe permettant le stockage d'une moto.
//--------------------------------------------------------------------------------------------------

#include "Garage.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur.
/// @param strImmatriculation 	Immatriculation du vehicule.
/// @param EStatut 				Statut du vehicule.
/// @param cylindre 			Cylindree de la moto.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CMoto::CMoto(const std::string & strImmatriculation, CVehicule::EStatut statut, unsigned int cylindre)
: CVehicule(strImmatriculation, statut)
, m_cylindre(cylindre)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CMoto::~CMoto(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Retourne le type du vehicule (@see CVehicule::EType)
/// @return Type du Vehicule.
//--------------------------------------------------------------------------------------------------
/*virtual*/ CVehicule::EType CMoto::GetType(void) const
{
	return(e_type_moto);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le cylindre de la moto
/// @return cylindre de la moto.
//--------------------------------------------------------------------------------------------------
unsigned int CMoto::Getcylindre(void) const
{
	return(m_cylindre);
}

//--------------------------------------------------------------------------------------------------
/// Definis le cylindre de la moto
/// @param  cylindre Le cylindre de la moto.
//--------------------------------------------------------------------------------------------------
void CMoto::Setcylindre(unsigned int cylindre)
{
	assert(cylindre > 0);
	m_cylindre = cylindre;
}

//--------------------------------------------------------------------------------------------------
/// Affiche le vehicule utilitaire.
//--------------------------------------------------------------------------------------------------
/*virtual*/ void CMoto::Affiche(void)
{
	std::cout << "  Moto\n";
	std::cout << "  " << GetImmatriculation() << "\n";
	std::cout << "  cylindree : " << GetCylindre() << "\n";
	std::cout << "\n";
}