//--------------------------------------------------------------------------------------------------
// Fichier     : CBienLot.h
// Description : D�finition de la classe permettant le stockage d'un lot (i.e. un appartement ou
//               une maison faisant partie d'une copropri�t�.
//--------------------------------------------------------------------------------------------------

#ifndef __CBIENLOT_H
#define __CBIENLOT_H

#include "CBien.h"

//
/// Classe permettant le stockage d'un lot.
class CBienLot : public CBien
{
public:

	//
	/// Status
	enum EStatut
	{
		e_statut_en_vente,			///< En vente.
		e_statut_a_louer,			///< A louer.
		e_statut_loue				///< Lou�.
	};

	//
	// Construction / Destruction
	explicit		CBienLot			(float surface, EStatut eStatut);
	virtual			~CBienLot			(void);

	//
	// Accesseurs
	void			SetStatut			(EStatut eStatut);
	EStatut			GetStatut			(void) const;
	std::string		GetStatutAsString	(void) const;
	void			SetNombreDePieces	(int nombreDePieces);
	int				GetNombreDePieces	(void) const;

	//
	// Affichage
	virtual void	Affiche				(void) const;

protected:

private:

	EStatut			m_eStatut;			///< Statut du bien (@see CBienLot::EStatut).
	int				m_nombreDePieces;	///< Nombre de pi�ces du bien.
	
};

#endif // __CBIENLOT_H
