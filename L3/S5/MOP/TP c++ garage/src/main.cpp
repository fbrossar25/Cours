//--------------------------------------------------------------------------------------------------
// Fichier     : main.cpp
// Description : Implémentation du point d'entrée de l'application.
//--------------------------------------------------------------------------------------------------

#include "Garage.h"

//--------------------------------------------------------------------------------------------------
/// Point d'entrée de l'application
//--------------------------------------------------------------------------------------------------
int main(void)
{
	printf("Bienvenue dans l'application Garage !\n");

	CGarage garage;

	while (1)
	{
		std::cout << "------------------------------------------------------------\n";
		std::cout << "1 : Ajout d'un nouveau client\n";
		std::cout << "2 : Ajout d'un vehicule\n";
		std::cout << "3 : Suppression d'un vehicule\n";

		std::cout << "4 : Affichage du nombre total de vehicules\n";

		std::cout << "5 : Affichage de la liste des vehicules\n";
		std::cout << "6 : Affichage de la liste des clients\n";
		
		std::cout << "\n";
		
		std::cout << "Entrez votre choix : ";

		int choix = ReadIntBetween(1, 6);
		switch(choix)
		{
		case 1:  { garage.AjoutClient();                   } break;
		case 2:  { garage.AjoutVehicule();                 } break;
		case 3:  { garage.SuppressionVehicule();           } break;
		case 4:  { garage.AfficheNombreTotalDeVehicules(); } break;
		case 5:  { garage.AfficheListeVehicules();         } break;
		case 6:  { garage.AfficheListeClients();           } break;
		default: {							 			   } break;
		}
	}

	return(0);
}

