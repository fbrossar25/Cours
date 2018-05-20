//
// Created by florian on 16/09/16.
//

#ifndef MOPO_TP1_PIGNON_H
#define MOPO_TP1_PIGNON_H

#include "triangle.h"
#include "fenetres.h"

class CPignon : public CTriangle
{
public:
    CPignon();
    CPignon(float base, float hauteur);
    ~CPignon();
    void printStats() const;
    void addFenetre(float largeur, float hauteur);

private:
	CFenetres m_fenetres;
};


#endif //MOPO_TP1_PIGNON_H
