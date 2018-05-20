//
// Created by florian on 16/09/16.
//

#include "triangle.h"

CTriangle::CTriangle()
{
    CTriangle(1.0,1.0);
}

CTriangle::CTriangle(float base, float hauteur)
: m_base(base)
, m_hauteur(hauteur)
{

}

CTriangle::~CTriangle()
{

}