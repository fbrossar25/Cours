//
// Created by florian on 16/09/16.
//

#include "portes.h"

CPortes::CPortes()
{
    m_portes.reserve(5);
}

CPortes::~CPortes()
{

}

void CPortes::addPorte(float largeur, float hauteur)
{
    m_portes.push_back(COuverture(largeur, hauteur));
}

unsigned int CPortes::getSize() const
{
    return m_portes.size();
}

COuverture CPortes::getPorte(unsigned int n)
{
    assert(n < m_portes.size());
    return m_portes[n];
}

float CPortes::getAire() const
{
    unsigned int i, n = m_portes.size();
    if(n == 0) return 0.0;
    float res = m_portes[0].getAire();
    for(i = 1;i < n;i++)
    {
        res += m_portes[i].getAire();
    }
    return res;
}

void CPortes::printStats() const
{
    unsigned int i,n = m_portes.size();
    if(n == 0)
    {
        std::cout << "Pas de portes" << std::endl;
        return;
    }
    std::cout << n << " portes :"<< std::endl;
    for(i=0; i<n; i++)
    {
        m_portes[i].printStats();
    }
    std::cout << std::endl;
}