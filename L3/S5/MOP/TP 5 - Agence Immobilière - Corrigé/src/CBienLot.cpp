//--------------------------------------------------------------------------------------------------
// Fichier     : CBienLot.cpp
// Description : Implémentation de la classe permettant le stockage d'un lot (i.e. un appartement ou
//               une maison faisant partie d'une copropriété.
//--------------------------------------------------------------------------------------------------

#include "AgenceImmobiliere.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur.
/// @param surface Surface du bien.
/// @param eStatut Statut courant.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CBienLot::CBienLot(float surface, EStatut eStatut)
: CBien(surface)
, m_eStatut(eStatut)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CBienLot::~CBienLot(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Initialiser le statut du bien.
/// @param eStatut Nouveau statut du bien.
//--------------------------------------------------------------------------------------------------
void CBienLot::SetStatut(EStatut eStatut)
{
	m_eStatut = eStatut;
}

//--------------------------------------------------------------------------------------------------
/// Retourne le statut du bien (@see CBienLot::EStatut).
/// @return Statut du bien.
//--------------------------------------------------------------------------------------------------
CBienLot::EStatut CBienLot::GetStatut(void) const
{
	return(m_eStatut);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le statut du bien sous la forme d'une chaine de caracteres.
/// @return Statut du bien.
//--------------------------------------------------------------------------------------------------
std::string CBienLot::GetStatutAsString(void) const
{
	switch(m_eStatut)
	{
	case e_statut_en_vente: { return("en vente"); } break;
	case e_statut_a_louer:  { return("a louer");  } break;
	case e_statut_loue:     { return("loue");     } break;
	default:                { return("inconnu");  } break;
	}
}

//--------------------------------------------------------------------------------------------------
/// Initialise le nombre de pièces du bien.
/// @param nombreDePieces Nouveau nombre de pièces.
//--------------------------------------------------------------------------------------------------
void CBienLot::SetNombreDePieces(int nombreDePieces)
{
	m_nombreDePieces = nombreDePieces;
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre de pièces du bien.
/// @return Nombre de pièces du bien.
//--------------------------------------------------------------------------------------------------
int CBienLot::GetNombreDePieces(void) const
{
	return(m_nombreDePieces);
}

//--------------------------------------------------------------------------------------------------
/// Affiche le bien sur la ligne de commande.
//--------------------------------------------------------------------------------------------------
/*virtual*/ void CBienLot::Affiche(void) const
{
	std::cout << "  Nombre de pieces : " << GetNombreDePieces() << "\n";
	std::cout << "  Status : " << GetStatutAsString() << "\n";
	std::cout << "\n";
}

