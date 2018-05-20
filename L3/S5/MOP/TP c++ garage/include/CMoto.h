//--------------------------------------------------------------------------------------------------
// Fichier     : CMoto.h
// Description : Définition de la classe permettant le stockage d'un appartement.
//--------------------------------------------------------------------------------------------------

#ifndef __CMOTO_H
#define __CMOTO_H

#include "CVehicule.h"

//
/// Classe permettant le stockage d'un appartement.
class CMoto : public CVehicule
{
public:
	//
	// Construction / Destruction
	explicit		CMoto	(const std::string & strImmatriculation, EStatut statut, unsigned int cynlindre);
	virtual			~CMoto	(void);

	//
	// Accesseurs
	virtual EType	GetType		(void) const;
	unsigned int	GetCylindre	(void) const;
	void			SetCylindre (unsigned int m_cynlindre);

	//
	// Affichage
	virtual void	Affiche     (void);

protected:

private:
	unsigned int m_cynlindre;	///<Volume du vehicule.
};

#endif // __CMOTO_H