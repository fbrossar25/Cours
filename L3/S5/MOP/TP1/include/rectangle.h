//
// Created by florian on 16/09/16.
//

#ifndef MOPO_TP1_RECTANGLE_H
#define MOPO_TP1_RECTANGLE_H

#include <iostream>


class CRectangle
{
public:
    CRectangle();
    CRectangle(float largeur, float hauteur);
    virtual ~CRectangle();
    inline float getLargeur() const { return(m_largeur); };
    inline float getHauteur() const { return(m_hauteur); };
    inline float getAire() const { return(m_largeur * m_hauteur); };
    inline void printStats() const { std::cout << m_largeur << "m * " << m_hauteur << "m" << std::endl; };

protected:
    float m_largeur, m_hauteur;
};


#endif //MOPO_TP1_RECTANGLE_H
