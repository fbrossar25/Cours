//
// Created by florian on 16/09/16.
//

#include "rectangle.h"

CRectangle::CRectangle() : CRectangle(1.0,1.0)
{

}

CRectangle::CRectangle(float largeur, float hauteur)
: m_largeur(largeur)
, m_hauteur(hauteur)
{

}

CRectangle::~CRectangle()
{

}