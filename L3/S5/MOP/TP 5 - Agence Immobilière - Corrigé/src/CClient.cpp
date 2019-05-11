//--------------------------------------------------------------------------------------------------
// Fichier     : CClient.cpp
// Description : Implémentation de la classe permettant le stockage d'un client.
//--------------------------------------------------------------------------------------------------

#include "AgenceImmobiliere.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur.
/// @param eType Type de client (@see CClient::EType)
/// @param strName Nom du client.
/// @param strPrenom Prenom du client.
/// @param strAdresse Adresse postale du client
/// @param strTelephone Numero de telephone du client.
//--------------------------------------------------------------------------------------------------
/*explicit*/ CClient::CClient(EType eType, const std::string & strNom, const std::string & strPrenom, const std::string & strAdresse, const std::string & strTelephone)
: m_eType(eType)
, m_strNom(strNom)
, m_strPrenom(strPrenom)
, m_strAdresse(strAdresse)
, m_strTelephone(strTelephone)
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CClient::~CClient(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Initialise du type du client.
/// @param eType Nouveau type (@see CClient::EType).
//--------------------------------------------------------------------------------------------------
void CClient::SetType(EType eType)
{
	m_eType = eType;
}

//--------------------------------------------------------------------------------------------------
/// Retourne le type du client (@see CClient::EType).
/// @return Type du client.
//--------------------------------------------------------------------------------------------------
CClient::EType CClient::GetType(void) const
{
	return(m_eType);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le type du client sous la forme d'une chaine de caracteres.
/// @return Type du client.
//--------------------------------------------------------------------------------------------------
std::string CClient::GetTypeAsString(void) const
{
	switch(m_eType)
	{
	case e_type_acheteur:  { return("acheteur");  } break;
	case e_type_vendeur:   { return("vendeur");   } break;
	case e_type_loueur:    { return("loueur");    } break;
	case e_type_locataire: { return("locataire"); } break;
	default:               { return("inconnu");   } break;
	}
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
/// Affiche les données du client sur la ligne de commande.
//--------------------------------------------------------------------------------------------------
void CClient::Affiche(void) const
{
	std::cout << "  " << GetNom() << "\n";
	std::cout << "  " << GetPrenom() << "\n";
	std::cout << "  " << GetAdresse() << "\n";
	std::cout << "  " << GetTelephone() << "\n";
	std::cout << "  " << GetTypeAsString() << "\n";
	std::cout << "\n";
}
