//
// Created by florian on 16/09/16.
//

#ifndef MOPO_TP1_PORTES_H
#define MOPO_TP1_PORTES_H

#include <cstddef>
#include <assert.h>
#include <vector>
#include "ouverture.h"

class CPortes
{
public:
    CPortes();
    ~CPortes();
    void addPorte(float largeur, float hauteur);
    unsigned int getSize() const;
    COuverture getPorte(unsigned int n);
    float getAire() const;
    void printStats() const;

private:
    std::vector <COuverture> m_portes;
};


#endif
