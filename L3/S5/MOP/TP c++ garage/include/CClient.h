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
	// Construction / Destruction
	explicit			CClient			(const std::string & strNom, const std::string & strPrenom, const std::string & strAdresse, const std::string & strTelephone, const std::string & strMail);
	virtual				~CClient		(void);

	//
	// Accesseurs
	void				SetNom			(const std::string & strNom);
	const std::string &	GetNom			(void) const;
	void				SetPrenom		(const std::string & strPrenom);
	const std::string &	GetPrenom		(void) const;
	void				SetAdresse		(const std::string & strAdresse);
	const std::string &	GetAdresse		(void) const;
	void				SetTelephone	(const std::string & strTelephone);
	const std::string &	GetTelephone	(void) const;
	void				SetMail			(const std::string & strMail);
	const std::string &	GetMail			(void) const;

	//
	// Affichage
	void				Affiche			(void) const;

protected:

private:

	std::string			m_strNom;		///< Nom.
	std::string			m_strPrenom;	///< Prénom.
	std::string			m_strAdresse;	///< Adresse postale.
	std::string			m_strTelephone;	///< Numéro de téléphone.
	std::string			m_strMail;		///< Adresse mail.

};

#endif // __CCLIENT_H
