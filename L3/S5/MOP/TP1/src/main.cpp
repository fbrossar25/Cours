//
// Created by florian on 16/09/16.
//

#include "maison.h"

int main()
{
    int nFacades;
    std::cout << "Combien de facades ? ";
    std::cin >> nFacades;
    if(nFacades <= 0) return 0;//Pas de facades -> pas de surface à crépir.

    CMaison maison;
    float lFacade,hFacade,hPignon = 0.0;
    int nFenetres,nPortes;
    char c;
    for(int i=0; i<nFacades; i++)//Pour chaques facades
    {
    	std::cout << "\n==========Facade " << i+1 << "==========\n" << std::endl;

    	std::cout << "\tLargeur ? ";
    	std::cin >> lFacade;
    	std::cout << "\tHauteur? ";
    	std::cin >> hFacade;

    	std::cout << "\tPignon (o pour oui, n pour non) ? ";
    	std::cin >> c;
    	if(c == 'o')//Si pignon
    	{
    		std::cout << "\tHauteur du pignon ? ";
    		std::cin >> hPignon;
    		if(hPignon < 0.0) hPignon = 0.0;
    	}

    	//Ajout de la facade
    	if(c == 'o' && hPignon > 0.0)//si pignon
    	{
    		maison.addFacade(lFacade, hFacade, hPignon);
            std::cout << "\tNombre de fenetres sur le pignon ? ";
            std::cin >> nFenetres;
            if(nFenetres > 0)//Si fenêtres
            {
                float hFenetre,lFenetre;
                for(int j=0; j<nFenetres; j++)//Pour chaque fenetres
                {
                    std::cout << "\tLargeur fenetre " << j+1 << " ? ";
                    std::cin >> hFenetre;
                    std::cout << "\tHauteur fenetre " << j+1 << " ? ";
                    std::cin >> lFenetre;
                    if(lFenetre < 0.0 || hFenetre < 0.0) lFenetre = hFenetre = 0.0;//On ne prend pas en compte la fenêtres lors du calcul
                    maison.getLastFacade()->addFenetreSurPignon(lFenetre,hFenetre);
                }
            }
    	}
    	else
    	{
    		maison.addFacade(lFacade, hFacade);
    	}

    	std::cout << "\tNombre de fenêtres ? ";
    	std::cin >> nFenetres;
    	if(nFenetres > 0)//Si fenêtres
    	{
    		float hFenetre,lFenetre;
    		for(int j=0; j<nFenetres; j++)//Pour chaque fenetres
    		{
    			std::cout << "\tLargeur fenetre " << j+1 << " ? ";
		    	std::cin >> hFenetre;
		    	std::cout << "\tHauteur fenetre " << j+1 << " ? ";
		    	std::cin >> lFenetre;
		    	if(lFenetre < 0.0 || hFenetre < 0.0) lFenetre = hFenetre = 0.0;//On ne prend pas en compte la fenêtres lors du calcul
		    	maison.getLastFacade()->addFenetre(lFenetre,hFenetre);
    		}
    	}

    	std::cout << "\tNombre de portes ? ";
    	std::cin >> nPortes;
    	if(nPortes > 0)//Si portes
    	{
    		float hPorte,lPorte;
    		for(int j=0; j<nPortes; j++)//Pour chaque portes
    		{
    			std::cout << "\tLargeur " << j+1 << " ? ";
		    	std::cin >> hPorte;
		    	std::cout << "\tHauteur " << j+1 << " ? ";
		    	std::cin >> lPorte;
		    	if(lPorte <= 0.0 || hPorte <= 0.0)
		    	{
		    		lPorte = hPorte = 0.0;//On ne prend pas en compte la portes lors du calcul
		    	}
		    	maison.getLastFacade()->addPorte(lPorte,hPorte);
    		}
    	}
    }

    //Affichage
    maison.printStats();

	std::cout << "Il y a une surface de "<< maison.getAireACrepir() << "m carre a crepir." << std::endl;
    return 0;
}