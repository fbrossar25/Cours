//--------------------------------------------------------------------------------------------------
// Fichier     : CAgence.h
// Description : D�finition de la classe permettant le stockage d'une agence immobili�re.
//--------------------------------------------------------------------------------------------------

#ifndef __CAGENCE_H
#define __CAGENCE_H

#include <string>
#include <vector>

#include "CClient.h"
#include "CBienLotAppartement.h"
#include "CBienLotMaison.h"
#include "CBienImmeuble.h"

//
/// Classe permettant le stockage d'une agence immobili�re.
class CAgence
{
public:

	//
	// Construction / Destruction
	explicit							CAgence						(void);
	virtual								~CAgence					(void);

	//
	// Methodes expos�es � l'utilisateur
	void								AjoutClient					(void);
	void								AjoutBien					(void);
	void								SuppressionClient			(void);
	void								SuppressionBien				(void);
	void								AfficheNombreTotalDeClients	(void);
	void								AfficheNombreTotalDeBiens	(void);
	void								AfficheListeClients			(void);
	void								AfficheListeBiens			(void);
	void								AfficheBien					(void);

protected:

	//
	// Methodes internes liees aux clients
	void								AjoutClient				(const CClient & client);
	void								SupprimeClient			(int iClient);
	int									GetNombreClients		(void) const;
	const CClient &						GetClient				(int nClient) const;

	//
	// Methodes internes liees aux appartements
	void								AjoutAppartement		(const CBienLotAppartement & appartement);
	void								SupprimeAppartement		(int iAppartement);
	int									GetNombreAppartements	(void) const;
	const CBienLotAppartement &			GetAppartement			(int nAppartement) const;
	
	//
	// Methodes internes liees aux maisons
	void								AjoutMaison				(const CBienLotMaison & maison);
	void								SupprimeMaison			(int iMaison);
	int									GetNombreMaisons			(void) const;
	const CBienLotMaison &				GetMaison				(int nMaison) const;

	//
	// Methodes internes liees aux immeubles
	void								AjoutImmeuble			(const CBienImmeuble & immeuble);
	void								SupprimeImmeuble		(int iImmeuble);
	int									GetNombreImmeubles		(void) const;
	const CBienImmeuble &				GetImmeuble				(int nImmeuble) const;

private:

	std::vector<CClient>				m_aClient;				///< Tableau destin� � accueillir les clients.

	std::vector<CBienLotAppartement>	m_aBienAppartement;		///< Tableau destin� � accueillir les appartements.
	std::vector<CBienLotMaison>			m_aBienMaison;			///< Tableau destin� � accueillir les maison.
	std::vector<CBienImmeuble>			m_aBienImmeuble;		///< Tableau destin� � accueillir les immeubles.
	
};

#endif // __CAGENCE_H

