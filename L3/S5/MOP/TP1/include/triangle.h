//
// Created by florian on 16/09/16.
//

#ifndef MOPO_TP1_TRIANGLE_H
#define MOPO_TP1_TRIANGLE_H

#include <iostream>

class CTriangle
{
public:
    CTriangle();
    CTriangle(float base, float hauteur);
    virtual ~CTriangle();
    inline float getBase() const { return (m_base); };
    inline float getHauteur() const { return (m_hauteur); };
    inline float getAire() const { return (m_base * (m_hauteur / 2.0)); };
    inline void printStats() const { std::cout << m_base << "m * "<< m_hauteur << "m" << std::endl; };

protected:
    float m_base, m_hauteur;
};


#endif //MOPO_TP1_TRIANGLE_H