//
// Created by florian on 16/09/16.
//

#ifndef MOPO_TP1_FENETRES_H
#define MOPO_TP1_FENETRES_H

#include <cstddef>
#include <assert.h>
#include <vector>
#include <iostream>
#include "ouverture.h"

class CFenetres
{
public:
    CFenetres();
    ~CFenetres();
    void addFenetre(float largeur, float hauteur);
    unsigned int getSize() const;
    COuverture getFenetre(unsigned int n);
    float getAire() const;
    void printStats() const;

private:
    std::vector <COuverture> m_fenetres;
};


#endif //MOPO_TP1_FENETRES_H
