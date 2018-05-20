//--------------------------------------------------------------------------------------------------
// Fichier     : CBienLotAppartement.cpp
// Description : Implémentation de la classe permettant le stockage d'un appartement.
//--------------------------------------------------------------------------------------------------

#include "AgenceImmobiliere.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur.
/// @param surface Surface du bien.
/// @param eStatut Statut courant.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CBienLotAppartement::CBienLotAppartement(float surface, CBienLot::EStatut eStatut)
: CBienLot(surface, eStatut)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CBienLotAppartement::~CBienLotAppartement(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Retourne le type du bien (@see CBien::EType)
/// @return Type du bien.
//--------------------------------------------------------------------------------------------------
/*virtual*/ CBien::EType CBienLotAppartement::GetType(void) const
{
	return(e_type_appartement);
}

