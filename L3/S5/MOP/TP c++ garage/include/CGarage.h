//--------------------------------------------------------------------------------------------------
// Fichier     : CGarage.h
// Description : Définition de la classe permettant le stockage d'un Garage.
//--------------------------------------------------------------------------------------------------

#ifndef __CGARAGE_H
#define __CGARAGE_H

#include <string>
#include <vector>

#include "CCLient.h"
#include "CVoiture.h"
#include "CUtilitaire.h"
#include "CMoto.h"

//
/// Classe permettant le stockage d'un garage.
class CGarage
{
public:

	//
	// Construction / Destruction
	explicit							CGarage						(void);
	virtual								~CGarage					(void);

	//
	// Methodes exposées à l'utilisateur
	void								AjoutClient					(void);
	void								AjoutVehicule				(void);
	void								SuppressionVehicule			(void);
	void								AfficheNombreTotalDeVehicule(void);
	void								AfficheListeVehicules		(void);
	void								AfficheListeClient			(void);

protected:

	//
	// Methodes internes liees aux clients
	void								AjoutClient					(const CClient & client);
	int									GetNombreClients			(void) const;

	//
	// Methodes internes liees aux voitures
	void								AjoutVoiture				(const CVoiture & voiture);
	void								SupprimeVoiture				(int iVoiture);
	int									GetNombreVoitures			(void) const;
	const CVoiture &					GetVoiture					(int nVoiture) const;
	
	//
	// Methodes internes liees aux vehicules utilitaires
	void								AjoutUtilitaire				(const CUtilitaire & utilitaire);
	void								SupprimeUtilitaire			(int iUtilitaire);
	int									GetNombreUtilitaires		(void) const;
	const CUtilitaire &					GetUtilitaire				(int nUtilitaire) const;

	//
	// Methodes internes liees aux motos
	void								AjoutMoto				(const CMoto & moto);
	void								SupprimeMoto			(int iMoto);
	int									GetNombreMotos			(void) const;
	const CMoto &						GetMoto					(int nMoto) const;

private:

	std::vector<CClient>				m_aClient;				///< Tableau destiné à accueillir les clients.

	std::vector<CVoiture>				m_aVoiture;				///< Tableau destiné à accueillir les voiture.
	std::vector<CUtilitaire>			m_aUtilitaire;			///< Tableau destiné à accueillir les vehicule utilitaire.
	std::vector<CMoto>					m_aMoto;				///< Tableau destiné à accueillir les motos.

};

#endif // __CGARAGE_H