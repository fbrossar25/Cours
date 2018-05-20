//--------------------------------------------------------------------------------------------------
// Fichier     : CVoiture.h
// Description : Définition de la classe permettant le stockage d'une voiture.
//--------------------------------------------------------------------------------------------------

#ifndef __CVOITURE_H
#define __CVOITURE_H

#include "CVehicule.h"

//
/// Classe permettant le stockage d'une voiture.
class CVoiture : public CVehicule
{
public:
	//
	// Construction / Destruction
	explicit		CVoiture	(const std::string & strImmatriculation, EStatut statut, unsigned int nbPlaces);
	virtual			~CVoiture	(void);

	//
	// Accesseurs
	virtual EType	GetType		(void) const;
	unsigned int 	GetNbPlaces	(void) const;
	void			SetNbPlaces (unsigned int nbPlaces);

	//
	// Affichage
	virtual void	Affiche     (void);

protected:

private:
	unsigned int m_nbPlaces;	///<Nombre de places dans la voiture.
};

#endif // __CVOITURE_H