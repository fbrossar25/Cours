//--------------------------------------------------------------------------------------------------
// Fichier     : CBienLotAppartement.h
// Description : Définition de la classe permettant le stockage d'un appartement.
//--------------------------------------------------------------------------------------------------

#ifndef __CBIENLOTAPPARTEMENT_H
#define __CBIENLOTAPPARTEMENT_H

#include "CBienLot.h"

//
/// Classe permettant le stockage d'un appartement.
class CBienLotAppartement : public CBienLot
{
public:

	//
	// Construction / Destruction
	explicit		CBienLotAppartement		(float surface, CBienLot::EStatut eStatut);
	virtual			~CBienLotAppartement	(void);

	//
	// Accesseurs
	virtual EType	GetType					(void) const;

protected:

private:

};

#endif // __CBIENLOTAPPARTEMENT_H

