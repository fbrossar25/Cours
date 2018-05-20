//--------------------------------------------------------------------------------------------------
// Fichier     : CBienLotMaison.cpp
// Description : Implémentation de la classe permettant le stockage d'une maison.
//--------------------------------------------------------------------------------------------------

#include "AgenceImmobiliere.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur.
/// @param surface Surface du bien.
/// @param eStatut Statut courant.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CBienLotMaison::CBienLotMaison(float surface, CBienLot::EStatut eStatut)
: CBienLot(surface, eStatut)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CBienLotMaison::~CBienLotMaison(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Retourne le type du bien (@see CBien::EType)
/// @return Type du bien.
//--------------------------------------------------------------------------------------------------
/*virtual*/ CBien::EType CBienLotMaison::GetType(void) const
{
	return(e_type_maison);
}

