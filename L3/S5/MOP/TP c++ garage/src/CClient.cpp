//--------------------------------------------------------------------------------------------------
// Fichier     : CClient.cpp
// Description : Implémentation de la classe permettant le stockage d'un client.
//--------------------------------------------------------------------------------------------------

#include "Garage.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur.
/// @param strName Nom du client.
/// @param strPrenom Prenom du client.
/// @param strAdresse Adresse postale du client
/// @param strTelephone Numero de telephone du client.
/// @param strMail Adresse mail du client.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CClient::CClient(const std::string & strNom, const std::string & strPrenom, const std::string & strAdresse, const std::string & strTelephone, const std::string & strMail)
: m_strNom(strNom)
, m_strPrenom(strPrenom)
, m_strAdresse(strAdresse)
, m_strTelephone(strTelephone)
, m_strMail(strMail)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CClient::~CClient(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Initialise le nom du client.
/// @param strNom Nouveau nom.
//--------------------------------------------------------------------------------------------------
void CClient::SetNom(const std::string & strNom)
{
	m_strNom = strNom;
}

//--------------------------------------------------------------------------------------------------
/// Retourn le nom du client.
/// @return Nom du client.
//--------------------------------------------------------------------------------------------------
const std::string & CClient::GetNom(void) const
{
	return(m_strNom);
}

//--------------------------------------------------------------------------------------------------
/// Initialise le prénom du client.
/// @param strNom Nouveau prénom.
//--------------------------------------------------------------------------------------------------
void CClient::SetPrenom(const std::string & strPrenom)
{
	m_strPrenom = strPrenom;
}

//--------------------------------------------------------------------------------------------------
/// Retourne le prénom du client.
/// @return Prénom du client.
//--------------------------------------------------------------------------------------------------
const std::string & CClient::GetPrenom(void) const
{
	return(m_strPrenom);
}

//--------------------------------------------------------------------------------------------------
/// Initialise l'adresse du client.
/// @param strAdresse Adresse du client.
//--------------------------------------------------------------------------------------------------
void CClient::SetAdresse(const std::string & strAdresse)
{
	m_strAdresse = strAdresse;
}

//--------------------------------------------------------------------------------------------------
/// Retourne l'adresse du client
/// @return Adresse du client.
//--------------------------------------------------------------------------------------------------
const std::string & CClient::GetAdresse(void) const
{
	return(m_strAdresse);
}

//--------------------------------------------------------------------------------------------------
/// Initialise le numéro de téléphone du client.
/// @param strTelephone Nouveau numéro de téléphone.
//--------------------------------------------------------------------------------------------------
void CClient::SetTelephone(const std::string & strTelephone)
{
	m_strTelephone = strTelephone;
}

//--------------------------------------------------------------------------------------------------
/// Retourne le numéro de téléphone du client
/// @return Numéro de télphone du client.
//--------------------------------------------------------------------------------------------------
const std::string & CClient::GetTelephone(void) const
{
	return(m_strTelephone);
}


//--------------------------------------------------------------------------------------------------
/// Initialise l'adresse mail du client.
/// @param strMail Adresse mail du client.
//--------------------------------------------------------------------------------------------------
void CClient::SetMail(const std::string & strMail)
{
	m_strMail = strMail;
}

//--------------------------------------------------------------------------------------------------
/// Retourne l'adresse mail du client
/// @return Adresse mail du client.
//--------------------------------------------------------------------------------------------------
const std::string & CClient::GetMail(void) const
{
	return(m_strMail);
}

//--------------------------------------------------------------------------------------------------
/// Affiche les données du client sur la ligne de commande.
//--------------------------------------------------------------------------------------------------
void CClient::Affiche(void) const
{
	std::cout << "  " << GetNom() << "\n";
	std::cout << "  " << GetPrenom() << "\n";
	std::cout << "  " << GetAdresse() << "\n";
	std::cout << "  " << GetTelephone() << "\n";
	std::cout << "  " << GetMail() << "\n";
	std::cout << "\n";
}
