#ifndef FACADE_H
#define FACADE_H

#include <vector>
#include <iostream>

#include "pignon.h"
#include "rectangle.h"
#include "fenetres.h"
#include "portes.h"

class CFacade
{
public:
    CFacade();
    CFacade(bool hasPignon);
    CFacade(float largeur, float hauteur);
    CFacade(float RLargeur, float RHauteur, float PHauteur);
    ~CFacade();
    void addPorte(float largeur, float hauteur);
    void addFenetre(float largeur, float hauteur);
    inline unsigned int getNPortes() const { return m_portes.getSize(); };
    inline unsigned int getNFenetres() const { return m_fenetres.getSize(); };
    float getAire() const;
    void printStats() const;
    void addFenetreSurPignon(float largeur, float hauteur);

private:
	CRectangle m_rectangle;
	bool m_hasPignon;
	CPignon m_pignon;
    CPortes m_portes;
	CFenetres m_fenetres;
};

#endif