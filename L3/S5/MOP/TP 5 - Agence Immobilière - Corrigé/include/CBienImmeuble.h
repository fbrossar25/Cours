//--------------------------------------------------------------------------------------------------
// Fichier     : CBienImmeuble.h
// Description : Définition de la classe permettant le stockage d'un immeuble.
//--------------------------------------------------------------------------------------------------

#ifndef __CBIENIMMEUBLE_H
#define __CBIENIMMEUBLE_H

#include <vector>
#include "CBienLotAppartement.h"

//
/// Classe permettant le stockage d'un immeuble.
class CBienImmeuble : public CBien
{
public:

	//
	// Construction / Destruction
	explicit							CBienImmeuble			(float surface, const std::vector<CBienLotAppartement> & aAppartement);
	virtual								~CBienImmeuble			(void);

	//
	// Accesseurs
	virtual EType						GetType					(void) const;

	int									GetNombreDAppartements	(void);
	const CBienLotAppartement &			GetAppartement			(int nAppartement) const;

	//
	// Affichage
	virtual void						Affiche					(void) const;

protected:

private:

	std::vector<CBienLotAppartement>	m_aAppartement;			///< Tableau destiné à accueillir les appartements de l'immeuble.

};

#endif // __CBIENIMMEUBLE_H
