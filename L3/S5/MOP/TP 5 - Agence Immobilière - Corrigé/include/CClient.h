//--------------------------------------------------------------------------------------------------
// Fichier     : CClient.h
// Description : Définition de la classe permettant le stockage d'un client.
//--------------------------------------------------------------------------------------------------

#ifndef __CCLIENT_H
#define __CCLIENT_H

#include <string>

//
/// Classe permettant le stockage d'un client.
class CClient
{
public:

	//
	/// Type de client.
	enum EType
	{
		e_type_acheteur,				///< Acheteur.
		e_type_vendeur,					///< Vendeur.
		e_type_loueur,					///< Loueur.
		e_type_locataire,				///< Locataire.
	};

	//
	// Construction / Destruction
	explicit			CClient			(EType eType, const std::string & strNom, const std::string & strPrenom, const std::string & strAdresse, const std::string & strTelephone);
	virtual				~CClient		(void);

	//
	// Accesseurs
	void				SetType			(EType eType);
	EType				GetType			(void) const;
	std::string			GetTypeAsString	(void) const;
	void				SetNom			(const std::string & strNom);
	const std::string &	GetNom			(void) const;
	void				SetPrenom		(const std::string & strPrenom);
	const std::string &	GetPrenom		(void) const;
	void				SetAdresse		(const std::string & strAdresse);
	const std::string &	GetAdresse		(void) const;
	void				SetTelephone	(const std::string & strTelephone);
	const std::string &	GetTelephone	(void) const;

	//
	// Affichage
	void				Affiche			(void) const;

protected:

private:

	EType				m_eType;		///< Type (@see CClient::EType).
	std::string			m_strNom;		///< Nom.
	std::string			m_strPrenom;	///< Prénom.
	std::string			m_strAdresse;	///< Adresse postale.
	std::string			m_strTelephone;	///< Numéro de téléphone.

};

#endif // __CCLIENT_H
