//--------------------------------------------------------------------------------------------------
// Fichier     : CVehicule.h
// Description : Définition de la classe permettant le stockage d'un Garage.
//--------------------------------------------------------------------------------------------------

#ifndef __CVEHICULE_H
#define __CVEHICULE_H

#include <string>
#include <vector>

//
/// Classe permettant le stockage d'un vehicule
class CVehicule
{
public:
	//
	/// Type de vehicule.
	enum EType
	{
		e_type_voiture,		///< Voiture.
		e_type_utilitaire,	///< Utilitaire.
		e_type_moto,		///< Moto.
	};

	//
	/// Statut du vehicule
	enum EStatut
	{
		e_statut_location,
		e_statut_vente,
	};

	//
	// Construction / Destruction
	explicit			CVehicule			(const std::string & strImmatriculation, EStatut statut);
	virtual				~CVehicule			(void);

	//
	// Accesseurs
	virtual EType		GetType				(void) const = 0;
	EStatut				GetStatut			(void) const;
	void				SetImmatriculation	(const std::string & strImmatriculation);
	const std::string &	GetImmatriculation	(void) const;

	//
	// Affichage
	virtual void		Affiche             (void) const = 0;

private:

	std::string 	m_strImmatriculation;	///<Immatriculation du vehicule.
	EStatut 		m_statut;				///<Statut du vehicule (location / vente).
};

#endif // __CVEHICULE_H