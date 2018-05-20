//--------------------------------------------------------------------------------------------------
// Fichier     : CUtilitaire.h
// Description : Définition de la classe permettant le stockage d'un vehicule utilitaire.
//--------------------------------------------------------------------------------------------------

#ifndef __CUTILITAIRE_H
#define __CUTILITAIRE_H

#include "CVehicule.h"

//
/// Classe permettant le stockage d'un vehicule utilitaire.
class CUtilitaire : public CVehicule
{
public:
	//
	// Construction / Destruction
	explicit		CUtilitaire	(const std::string & strImmatriculation, EStatut statut, float volume);
	virtual			~CUtilitaire	(void);

	//
	// Accesseurs
	virtual EType	GetType		(void) const;
	float 			GetVolume	(void) const;
	void			SetVolume   (float volume);

	//
	// Affichage
	virtual void	Affiche     (void);

protected:

private:
	float m_volume;	///<Volume du vehicule.
};

#endif // __CUTILITAIRE_H