//--------------------------------------------------------------------------------------------------
// Fichier     : CBien.h
// Description : Définition de la classe permettant le stockage d'un bien immobilier.
//--------------------------------------------------------------------------------------------------

#ifndef __CBIEN_H
#define __CBIEN_H

#include <string>

//
/// Classe permettant le stockage d'un bien immobilier.
class CBien
{
public:

	//
	/// Type de bien.
	enum EType
	{
		e_type_appartement,		///< Appartement.
		e_type_maison,			///< Maison.
		e_type_immeuble,		///< Immeuble.
	};

	//
	// Construction / Destruction
	explicit		CBien		(float surface);
	virtual			~CBien		(void);

	//
	// Accesseurs
	virtual EType	GetType		(void) const = 0;
	void			SetSurface	(float surface);
	float			GetSurface	(void) const;

	//
	// Affichage
	virtual void	Affiche		(void) const = 0;

protected:

private:

	float			m_surface;	///< Surface du bien.

};

#endif // __CBIEN_H
