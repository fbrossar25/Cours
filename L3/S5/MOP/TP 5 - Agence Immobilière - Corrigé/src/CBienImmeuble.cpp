//--------------------------------------------------------------------------------------------------
// Fichier     : CBienImmeuble.cpp
// Description : Définition de la classe permettant le stockage d'un immeuble.
//--------------------------------------------------------------------------------------------------

#include "AgenceImmobiliere.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur.
/// @param surface Surface du bien.
/// @param aAppartement Tableau contenant les appartements.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CBienImmeuble::CBienImmeuble(float surface, const std::vector<CBienLotAppartement> & aAppartement)
: CBien(surface)
, m_aAppartement(aAppartement)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CBienImmeuble::~CBienImmeuble(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Retourne le type de l'immeuble (@see CBien::EType).
/// @return Type de l'immeuble (@see CBien::EType).
//--------------------------------------------------------------------------------------------------
/*virtual*/ CBien::EType CBienImmeuble::GetType(void) const
{
	return(e_type_immeuble);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre d'appartements contenus dans l'immeuble.
/// @return Nombre d'appartements contenus dans l'immeuble.
//--------------------------------------------------------------------------------------------------
int CBienImmeuble::GetNombreDAppartements(void)
{
	return(m_aAppartement.size());
}

//--------------------------------------------------------------------------------------------------
/// Retourne le n-ième appartement contenu dans l'immeuble.
/// @return Référence sur le n-ième appartement contenu dans l'immeuble.
//--------------------------------------------------------------------------------------------------
const CBienLotAppartement & CBienImmeuble::GetAppartement(int nAppartement) const
{
	return(m_aAppartement[nAppartement]);
}

//--------------------------------------------------------------------------------------------------
/// Affiche l'immeuble sur la ligne de commande.
//--------------------------------------------------------------------------------------------------
/*virtual*/ void CBienImmeuble::Affiche(void) const
{
	int nombreAppartement = m_aAppartement.size();
	for (int nAppartement = 0 ; nAppartement < nombreAppartement ; ++nAppartement)
	{
		m_aAppartement[nAppartement].Affiche();
	}
}



