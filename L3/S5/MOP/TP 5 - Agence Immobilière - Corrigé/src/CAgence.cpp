//--------------------------------------------------------------------------------------------------
// Fichier     : CAgence.cpp
// Description : Implémentation de la classe permettant le stockage d'une agence immobilière.
//--------------------------------------------------------------------------------------------------

#include "AgenceImmobiliere.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur par défaut
//--------------------------------------------------------------------------------------------------
/*explicit*/ CAgence::CAgence(void)
: m_aClient()
, m_aBienAppartement()
, m_aBienMaison()
, m_aBienImmeuble()
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CAgence::~CAgence(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Ajout d'un client.
//--------------------------------------------------------------------------------------------------
void CAgence::AjoutClient(void)
{
	std::cout << "\n  Ajout d'un client :\n";

	std::cout << "  Entrez le nom : ";
	std::string strNom;
	ReadString(strNom);
	
	std::cout << "  Entrez le prenom : ";
	std::string strPrenom;
	ReadString(strPrenom);

	std::cout << "  Entrez l'adresse : ";
	std::string strAdresse;
	ReadString(strAdresse);

	std::cout << "  Entrez le telephone : ";
	std::string strTelephone;
	ReadString(strTelephone);

	std::cout << "  Entrez le type (0: acheteur / 1: vendeur / 2: loueur / 3: locataire) :";
	int type = ReadIntBetween(0, 3);
	
	AjoutClient(CClient((CClient::EType)type, strNom, strPrenom, strAdresse, strTelephone));

	std::cout << "  -> Client ajoute !\n\n";
}

//--------------------------------------------------------------------------------------------------
/// Ajout d'un bien.
//--------------------------------------------------------------------------------------------------
void CAgence::AjoutBien(void)
{
	std::cout << "\n  Ajout d'un bien :\n";

	std::cout << "  Entrez le type du bien (0: appartement / 1: maison / 2: immeuble) : ";
	int type = ReadIntBetween(0, 2);
	CBien::EType eType = (CBien::EType)type;

	float surface = 0.0f;
	CBienLot::EStatut eStatut = CBienLot::e_statut_en_vente;
	std::vector<int> aLot;

	switch(eType)
	{
	case CBien::e_type_appartement:
	case CBien::e_type_maison:
		{
			std::cout << "  Entrez la surface : ";
			surface = ReadFloatBetween(0.0f, FLT_MAX);

			std::cout << "  Entrez le statut (0: en vente / 1: a louer / 2: loue) : ";
			int statut = ReadIntBetween(0, 2);
			eStatut = (CBienLot::EStatut)statut;
		}
		break;

	case CBien::e_type_immeuble:
		{
			std::cout << "  Entrez le nombre d'appartements (max 16) : ";
			int nombreAppartements = ReadIntBetween(1, 16);
			for (int nAppartement = 0 ; nAppartement < nombreAppartements ; ++nAppartement)
			{
				std::cout << "  Entrez l'index de l'appartement numero " << nAppartement << " : ";
				int iAppartement = ReadIntBetween(0, GetNombreAppartements());
				aLot.push_back(iAppartement);
			}
		}
		break;

	default:
		{

		}
		break;
	}

	switch(eType)
	{
	case CBien::e_type_appartement:
		{
			AjoutAppartement(CBienLotAppartement(surface, eStatut));
		}
		break;

	case CBien::e_type_maison:
		{
			AjoutMaison(CBienLotMaison(surface, eStatut));
		}
		break;

	case CBien::e_type_immeuble:
		{
			std::vector<CBienLotAppartement> aAppartement;
			for (unsigned int nAppartement = 0 ; nAppartement < aLot.size() ; ++nAppartement)
			{
				aAppartement.push_back(GetAppartement(aLot[nAppartement]));
			}

			AjoutImmeuble(CBienImmeuble(surface, aAppartement));
		}
		break;
	}

	std::cout << "  -> Bien ajoute !\n\n";
}

//--------------------------------------------------------------------------------------------------
/// Suppression d'un client.
//--------------------------------------------------------------------------------------------------
void CAgence::SuppressionClient(void)
{
	if (0 == GetNombreClients())
	{
		std::cout << "\n  Supression impossible : aucun client !\n\n";
		return;
	}

	std::cout << "\n  Supression d'un client :\n\n";

	std::cout << "  Entrez le numero du client a supprimer : ";

	int iClient = ReadIntBetween(0, GetNombreClients() - 1);
	SupprimeClient(iClient);

	std::cout << "  -> Client supprime !\n\n";
}

//--------------------------------------------------------------------------------------------------
/// Suppression d'un bien.
//--------------------------------------------------------------------------------------------------
void CAgence::SuppressionBien(void)
{
	std::cout << "\n  Suppression d'un bien :\n";

	std::cout << "  Entrez le type du bien (0: appartement / 1: maison / 2: immeuble) : ";
	int type = ReadIntBetween(0, 2);
	CBien::EType eType = (CBien::EType)type;

	switch(eType)
	{
	case CBien::e_type_appartement:
		{
			if (0 == GetNombreAppartements())
			{
				std::cout << "\n  Supression impossible : aucun appartement !\n\n";
				return;
			}
			
			std::cout << "  Entrez le numero de l'appartement a supprimer : ";
			int iAppartement = ReadIntBetween(0, GetNombreAppartements() - 1);
			SupprimeAppartement(iAppartement);
			std::cout << "  -> Appartement supprime !\n\n";
			return;
		}
		break;

	case CBien::e_type_maison:
		{
			if (0 == GetNombreMaisons())
			{
				std::cout << "\n  Supression impossible : aucune maison !\n\n";
				return;
			}
			
			std::cout << "  Entrez le numero de la maison a supprimer : ";
			int iMaison = ReadIntBetween(0, GetNombreMaisons() - 1);
			SupprimeMaison(iMaison);
			std::cout << "  -> Maison supprimee !\n\n";
			return;
		}
		break;

	case CBien::e_type_immeuble:
		{
			if (0 == GetNombreImmeubles())
			{
				std::cout << "\n  Supression impossible : aucun immeuble !\n\n";
				return;
			}

			std::cout << "  Entrez le numero de l'immeuble a supprimer : ";
			int iImmeuble = ReadIntBetween(0, GetNombreImmeubles() - 1);
			SupprimeImmeuble(iImmeuble);
			std::cout << "  -> Immeuble supprime !\n\n";
		}
		break;
	}
}

//--------------------------------------------------------------------------------------------------
/// Affichage du nombre total de clients de l'agence.
//--------------------------------------------------------------------------------------------------
void CAgence::AfficheNombreTotalDeClients(void)
{
	std::cout << "Nombre total de clients : " << GetNombreClients() << "\n";
}

//--------------------------------------------------------------------------------------------------
/// Affichage du nombre total de biens de l'agence.
//--------------------------------------------------------------------------------------------------
void CAgence::AfficheNombreTotalDeBiens(void)
{
	const int nombreTotalDeBiens = GetNombreAppartements()
								 + GetNombreMaisons()
								 + GetNombreImmeubles();

	std::cout << "Nombre total de biens : " << nombreTotalDeBiens << "\n";
}

//--------------------------------------------------------------------------------------------------
/// Affichage de la liste des clients de l'agence.
//--------------------------------------------------------------------------------------------------
void CAgence::AfficheListeClients(void)
{
	std::cout << "\n  Liste des clients :\n\n";

	const int nombreClients = GetNombreClients();
	for (int nClient = 0 ; nClient < nombreClients ; ++nClient)
	{
		const CClient & client = GetClient(nClient);
		std::cout << "  Client " << nClient << "\n";
		client.Affiche();
	}
}

//--------------------------------------------------------------------------------------------------
/// Affichage de la liste des biens de l'agence.
//--------------------------------------------------------------------------------------------------
void CAgence::AfficheListeBiens(void)
{
	std::cout << "  Liste des biens : ";
	
	const int nombreAppartements = GetNombreAppartements();
	for (int nAppartement = 0 ; nAppartement < nombreAppartements ; ++nAppartement)
	{
		GetAppartement(nAppartement).Affiche();
	}
	
	const int nombreMaisons = GetNombreMaisons();
	for (int nMaison = 0 ; nMaison < nombreMaisons ; ++nMaison)
	{
		GetMaison(nMaison).Affiche();
	}
	
	const int nombreImmeubles = GetNombreImmeubles();
	for (int nImmeuble = 0 ; nImmeuble < nombreImmeubles ; ++nImmeuble)
	{
		GetImmeuble(nImmeuble).Affiche();
	}
}

//--------------------------------------------------------------------------------------------------
/// Affichage d'un bien.
//--------------------------------------------------------------------------------------------------
void CAgence::AfficheBien(void)
{
	std::cout << "  Entrez le type du bien (0: appartement / 1: maison / 2: immeuble) : ";
	int type = ReadIntBetween(0, 2);
	CBien::EType eType = (CBien::EType)type;

	switch(eType)
	{
	case CBien::e_type_appartement:
		{
			if (0 == GetNombreAppartements())
			{
				std::cout << "\n  Affichage impossible : aucun appartement !\n\n";
				return;
			}
			
			std::cout << "  Entrez le numero de l'appartement a afficher : ";
			int iAppartement = ReadIntBetween(0, GetNombreAppartements() - 1);
			GetAppartement(iAppartement).Affiche();
			return;
		}
		break;

	case CBien::e_type_maison:
		{
			if (0 == GetNombreMaisons())
			{
				std::cout << "\n  Affichage impossible : aucune maison !\n\n";
				return;
			}
			
			std::cout << "  Entrez le numero de la maison a afficher : ";
			int iMaison = ReadIntBetween(0, GetNombreMaisons() - 1);
			GetMaison(iMaison).Affiche();
			return;
		}
		break;

	case CBien::e_type_immeuble:
		{
			if (0 == GetNombreImmeubles())
			{
				std::cout << "\n  Affichage impossible : aucun immeuble !\n\n";
				return;
			}

			std::cout << "  Entrez le numero de l'immeuble a afficher : ";
			int iImmeuble = ReadIntBetween(0, GetNombreImmeubles() - 1);
			GetImmeuble(iImmeuble).Affiche();
		}
		break;
	}
}

//--------------------------------------------------------------------------------------------------
/// Affichage d'un client.
/// @param Référence sur le client à afficher.
//--------------------------------------------------------------------------------------------------
void CAgence::AjoutClient(const CClient & client)
{
	m_aClient.push_back(client);
}

//--------------------------------------------------------------------------------------------------
/// Suppression d'un client.
/// @param iClient Index du client à supprimer.
//--------------------------------------------------------------------------------------------------
void CAgence::SupprimeClient(int iClient)
{
	m_aClient.erase(m_aClient.begin() + iClient);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre de clients de l'agence.
/// @return Nombre de clients de l'agence.
//--------------------------------------------------------------------------------------------------
int CAgence::GetNombreClients(void) const
{
	return(m_aClient.size());
}

//--------------------------------------------------------------------------------------------------
/// Retourn le n-ième client de l'agence.
/// @return Référence sur le n-ième client de l'agence.
//--------------------------------------------------------------------------------------------------
const CClient & CAgence::GetClient(int nClient) const
{
	return(m_aClient[nClient]);
}

//--------------------------------------------------------------------------------------------------
/// Ajout d'un appartement.
/// @param Référence sur l'appartement à ajouter.
//--------------------------------------------------------------------------------------------------
void CAgence::AjoutAppartement(const CBienLotAppartement & appartement)
{
	m_aBienAppartement.push_back(appartement);
}

//--------------------------------------------------------------------------------------------------
/// Supprime le n-ième client de l'agence.
/// @return Référence sur le n-ième client de l'agence.
//--------------------------------------------------------------------------------------------------
void CAgence::SupprimeAppartement(int iAppartement)
{
	m_aBienAppartement.erase(m_aBienAppartement.begin() + iAppartement);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre d'appartements contenus dans l'agence.
/// @return Nombre d'appartements contenus dans l'agence.
//--------------------------------------------------------------------------------------------------
int CAgence::GetNombreAppartements(void) const
{
	return(m_aBienAppartement.size());
}

//--------------------------------------------------------------------------------------------------
/// Retourne le n-ième appartement contenu dans l'agence.
/// @return Référence sur le n-ième appartement contenu dans l'agence.
//--------------------------------------------------------------------------------------------------
const CBienLotAppartement & CAgence::GetAppartement(int nAppartement) const
{
	return(m_aBienAppartement[nAppartement]);
}

//--------------------------------------------------------------------------------------------------
/// Ajout d'une maison.
/// @param Référence sur la maison à ajouter.
//--------------------------------------------------------------------------------------------------
void CAgence::AjoutMaison(const CBienLotMaison & maison)
{
	m_aBienMaison.push_back(maison);
}

//--------------------------------------------------------------------------------------------------
/// Supprime la n-ième maison contenue dans l'agence.
/// @param Index de la maison à supprimer
//--------------------------------------------------------------------------------------------------
void CAgence::SupprimeMaison(int iMaison)
{
	m_aBienMaison.erase(m_aBienMaison.begin() + iMaison);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre de maisons contenues dans l'agence.
/// @return Nombre de maisons contenues dans l'agence.
//--------------------------------------------------------------------------------------------------
int CAgence::GetNombreMaisons(void) const
{
	return(m_aBienMaison.size());
}

//--------------------------------------------------------------------------------------------------
/// Retourne la n-ième maison contenue dans l'agence.
/// @return Référence sur la n-ième maison contenue dans l'agence.
//--------------------------------------------------------------------------------------------------
const CBienLotMaison & CAgence::GetMaison(int nMaison) const
{
	return(m_aBienMaison[nMaison]);
}

//--------------------------------------------------------------------------------------------------
/// Ajout d'un immeuble dans l'agence.
/// @param Référence sur l'immeuble à rajouter dans l'agence.
//--------------------------------------------------------------------------------------------------
void CAgence::AjoutImmeuble(const CBienImmeuble & immeuble)
{
	m_aBienImmeuble.push_back(immeuble);
}

//--------------------------------------------------------------------------------------------------
/// Suppression d'un immeuble de l'agence.
/// @param Index de l'immeuble à supprimer
//--------------------------------------------------------------------------------------------------
void CAgence::SupprimeImmeuble(int iImmeuble)
{
	m_aBienImmeuble.erase(m_aBienImmeuble.begin() + iImmeuble);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre d'immeubles de l'agence.
/// @return nombre d'immeubles de l'agence.
//--------------------------------------------------------------------------------------------------
int CAgence::GetNombreImmeubles(void) const
{
	return(m_aBienImmeuble.size());
}

//--------------------------------------------------------------------------------------------------
/// Retourne le n-ième immeuble contenu dans l'agence.
/// @return Référence sur le n-ième immeuble contenu dans l'agence.
//--------------------------------------------------------------------------------------------------
const CBienImmeuble & CAgence::GetImmeuble(int nImmeuble) const
{
	return(m_aBienImmeuble[nImmeuble]);
}

