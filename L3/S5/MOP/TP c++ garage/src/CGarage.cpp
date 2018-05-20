//--------------------------------------------------------------------------------------------------
// Fichier     : CGarage.cpp
// Description : Implémentation de la classe permettant le stockage d'un garage.
//--------------------------------------------------------------------------------------------------

#include "Garage.h"

//--------------------------------------------------------------------------------------------------
/// Constructeur par défaut
//--------------------------------------------------------------------------------------------------
/*explicit*/ CGarage::CGarage(void)
: m_aClient()
, m_aVoiture()
, m_aUtilitaire()
, m_aMoto()
{

}

//--------------------------------------------------------------------------------------------------
/// Destructeur
//--------------------------------------------------------------------------------------------------
/*virtual*/ CGarage::~CGarage(void)
{

}

//--------------------------------------------------------------------------------------------------
/// Ajout d'un client.
//--------------------------------------------------------------------------------------------------
void CGarage::AjoutClient(void)
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

	std::cout << "  Entrez le mail : ";
	std::string strMail;
	ReadString(strMail);
	
	AjoutClient(CClient(strNom, strPrenom, strAdresse, strTelephone, strMail));

	std::cout << "  -> Client ajoute !\n\n";
}

//--------------------------------------------------------------------------------------------------
/// Ajout d'un bien.
//--------------------------------------------------------------------------------------------------
void CGarage::AjoutVehicule(void)
{
	std::cout << "\n  Ajout d'un vehicule :\n";

	std::cout << "  Entrez le type du vehicule (0: voiture / 1: utilitaire / 2: moto) : ";
	int type = ReadIntBetween(0, 2);
	CVehicule::EType eType = (CVehicule::EType)type;

	std::cout << "  Entrez le statut du vehicule (0: location / 1: vente) : ";
	int statut = ReadIntBetween(0, 1);
	CVehicule::EStatut eStatut = (CVehicule::EStatut)statut;

	std::string strImmatriculation;
	std::cout << "  Entrez l'immatriculation du vehicule : ";
	ReadString(strImmatriculation);

	std::vector<int> aLot;

	switch(eType)
	{
	case CVehicule::e_type_voiture:
		{
			std::cout << "  Entrez le nombre de places dans la voiture : ";
			unsigned int nbPlaces = ReadIntBetween(1, 10);
			AjoutVoiture(CVoiture(strImmatriculation, eStatut, nbPlaces));
		}
		break;

	case CVehicule::e_type_utilitaire:
		{
			std::cout << "  Entrez le volume du vehicule utilitaire : ";
			float volume = ReadFloatBetween(0, 10000.0f);
			AjoutUtilitaire(CUtilitaire(strImmatriculation, eStatut, volume));
		}
		break;

	case CVehicule::e_type_moto:
		{
			std::cout << "  Entrez la cylindree de la moto : ";
			unsigned int cylindre = ReadIntBetween(0, 5000);
			AjoutMoto(CMoto(strImmatriculation, eStatut, cylindre));
		}
		break;
	}

	std::cout << "  -> Bien ajoute !\n\n";
}

//--------------------------------------------------------------------------------------------------
/// Suppression d'un vehicule.
//--------------------------------------------------------------------------------------------------
void CGarage::SuppressionVehicule(void)
{
	std::cout << "\n  Suppression d'un vehicule :\n";

	std::cout << "  Entrez le type du vehicule (0: voiture / 1: utilitaire / 2: moto) : ";
	int type = ReadIntBetween(0, 2);
	CVehicule::EType eType = (CVehicule::EType)type;

	switch(eType)
	{
	case CVehicule::e_type_voiture:
		{
			if (0 == GetNombreVoitures())
			{
				std::cout << "\n  Supression impossible : aucune voiture !\n\n";
				return;
			}
			
			std::cout << "  Entrez le numero de la voiture a supprimer : ";
			int iVoiture = ReadIntBetween(0, GetNombreVoitures() - 1);
			SupprimeVoiture(iVoiture);
			std::cout << "  -> Voiture supprimee !\n\n";
			return;
		}
		break;

	case CVehicule::e_type_utilitaire:
		{
			if (0 == GetNombreUtilitaires())
			{
				std::cout << "\n  Supression impossible : aucun vehicule utilitaire !\n\n";
				return;
			}
			
			std::cout << "  Entrez le numero du vehicule utilitaire a supprimer : ";
			int iUtilitaire = ReadIntBetween(0, GetNombreUtilitaires() - 1);
			SupprimeUtilitaire(iUtilitaire);
			std::cout << "  -> Vehicule utilitaire supprime !\n\n";
			return;
		}
		break;

	case CVehicule::e_type_moto:
		{
			if (0 == GetNombreMotos())
			{
				std::cout << "\n  Supression impossible : aucune moto !\n\n";
				return;
			}

			std::cout << "  Entrez le numero de la moto a supprimer : ";
			int iMoto = ReadIntBetween(0, GetNombreMotos() - 1);
			SupprimeMoto(iMoto);
			std::cout << "  -> Moto supprimee !\n\n";
		}
		break;
	}
}

//--------------------------------------------------------------------------------------------------
/// Affichage du nombre total de biens de l'agence.
//--------------------------------------------------------------------------------------------------
void CGarage::AfficheNombreTotalDeVehicule(void)
{
	const int nombreTotalDeVehicule = GetNombreVoitures() + GetNombreUtilitaires() + GetNombreMotos();
	std::cout << "Nombre total de vehicules : " << nombreTotalDeVehicule << "\n";
}

//--------------------------------------------------------------------------------------------------
/// Affichage de la liste des vehicules du garage.
//--------------------------------------------------------------------------------------------------
void CGarage::AfficheListeVehicules(void)
{
	std::cout << "  Liste des vehicules : ";
	
	const int nombreVoitures = GetNombreVoitures();
	for (int nVoiture = 0 ; nVoiture < nombreVoitures ; ++nVoiture)
	{
		GetVoiture(nVoiture).Affiche();
	}
	
	const int nombreUtilitaires = GetNombreUtilitaires();
	for (int nUtilitaire = 0 ; nUtilitaire < nombreUtilitaires ; ++nUtilitaire)
	{
		GetUtilitaire(nUtilitaire).Affiche();
	}
	
	const int nombreMotos = GetNombreMotos();
	for (int nMoto = 0 ; nMoto < nombreMotos ; ++nMoto)
	{
		GetMoto(nMoto).Affiche();
	}
}

//--------------------------------------------------------------------------------------------------
/// Affichage de la liste des clients du garage.
//--------------------------------------------------------------------------------------------------
void CGarage::AfficheListeClients(void)
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
/// Affichage d'un client.
/// @param client Référence sur le client.
//--------------------------------------------------------------------------------------------------
void CGarage::AjoutClient(const CClient & client)
{
	m_aClient.push_back(client);
}

//--------------------------------------------------------------------------------------------------
/// Suppression d'un client.
/// @param iClient Index du client à supprimer.
//--------------------------------------------------------------------------------------------------
void CGarage::SupprimeClient(int iClient)
{
	m_aClient.erase(m_aClient.begin() + iClient);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre de clients du garage.
/// @return Nombre de clients du garage.
//--------------------------------------------------------------------------------------------------
int CGarage::GetNombreClients(void) const
{
	return(m_aClient.size());
}

//--------------------------------------------------------------------------------------------------
/// Retourne le n-ième client du garage.
/// @param nClient index du client.
/// @return Référence sur le n-ième client du garage.
//--------------------------------------------------------------------------------------------------
const CClient & CGarage::GetClient(int nClient) const
{
	return(m_aClient[nClient]);
}

//--------------------------------------------------------------------------------------------------
/// Ajout d'une voiture.
/// @param voiture Référence sur la voiture à ajouter.
//--------------------------------------------------------------------------------------------------
void CGarage::AjoutVoiture(const CVoiture & voiture)
{
	m_aVoiture.push_back(voiture);
}

//--------------------------------------------------------------------------------------------------
/// Supprime la n-ième voiture du garage.
/// @param iVoiture index de la voiture a supprimer.
//--------------------------------------------------------------------------------------------------
void CGarage::SupprimeVoiture(int iVoiture)
{
	m_aVoiture.erase(m_aVoiture.begin() + iVoiture);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre de voiture contenues dans le garage.
/// @return Nombre de voiture contenues dans le garage.
//--------------------------------------------------------------------------------------------------
int CGarage::GetNombreVoitures(void) const
{
	return(m_aVoiture.size());
}

//--------------------------------------------------------------------------------------------------
/// Retourne la n-ième voiture contenu dans le garage.
/// @param nVoiture index de la voiture.
/// @return Référence sur la n-ième voiture contenu dans le garage.
//--------------------------------------------------------------------------------------------------
const CVoiture & CGarage::GetVoiture(int nVoiture) const
{
	return(m_aVoiture[nVoiture]);
}

//--------------------------------------------------------------------------------------------------
/// Ajout d'un vehicule utilitaire.
/// @param Référence sur le vehicule utilitaire a ajouter.
//--------------------------------------------------------------------------------------------------
void CGarage::AjoutUtilitaire(const CUtilitaire & utilitaire)
{
	m_aUtilitaire.push_back(utilitaire);
}

//--------------------------------------------------------------------------------------------------
/// Supprime le n-ième vehicule utilitaire contenu dans le garage.
/// @param Index de la vehicule utilitaire à supprimer
//--------------------------------------------------------------------------------------------------
void CGarage::SupprimeUtilitaire(int iUtilitaire)
{
	m_aUtilitaire.erase(m_aUtilitaire.begin() + iUtilitaire);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre de vehicules utilitaires contenus dans le garage.
/// @return Nombre de vehicules utilitaires contenus dans le garage.
//--------------------------------------------------------------------------------------------------
int CGarage::GetNombreUtilitaires(void) const
{
	return(m_aUtilitaire.size());
}

//--------------------------------------------------------------------------------------------------
/// Retourne le n-ième vehicule utilitaire contenu dans le garage.
/// @return Référence sur la n-ième vehicule utilitaire contenu dans le garage.
//--------------------------------------------------------------------------------------------------
const CUtilitaire & CGarage::GetUtilitaire(int nUtilitaire) const
{
	return(m_aUtilitaire[nUtilitaire]);
}

//--------------------------------------------------------------------------------------------------
/// Ajout d'une moto dans le garage.
/// @param Référence sur la moto à rajouter dans le garage.
//--------------------------------------------------------------------------------------------------
void CGarage::AjoutMoto(const CMoto & moto)
{
	m_aMoto.push_back(moto);
}

//--------------------------------------------------------------------------------------------------
/// Suppression d'une moto du garage.
/// @param Index de la moto à supprimer.
//--------------------------------------------------------------------------------------------------
void CGarage::SupprimeMoto(int iMoto)
{
	m_aMoto.erase(m_aMoto.begin() + iMoto);
}

//--------------------------------------------------------------------------------------------------
/// Retourne le nombre de motos dans le garage.
/// @return nombre de motos dans le garage.
//--------------------------------------------------------------------------------------------------
int CGarage::GetNombreMotos(void) const
{
	return(m_aMoto.size());
}

//--------------------------------------------------------------------------------------------------
/// Retourne la n-ième moto contenue dans le garage.
/// @return Référence sur la n-ième moto contenue dans le garage.
//--------------------------------------------------------------------------------------------------
const CMoto & CGarage::GetMoto(int nMoto) const
{
	return(m_aMoto[nMoto]);
}