#include "Client.h"

Client::Client(std::string nom, std::string prenom, std::string addresse, std::string numero,
				bool acheteur, bool vendeur, bool loueur, bool locataire)
: Personne::Personne(nom,prenom)
, m_addresse(addresse)
, m_numero(numero)
, m_type{acheteur,vendeur,loueur,locataire}
{

}

Client::~Client()
{

}