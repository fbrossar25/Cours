#include "Appartement.h"

Appartement::Appartement()
: Bien(0.0)
, m_nombrePieces(0)
{

}

Appartement::Appartement(float surface, unsigned int nombrePieces)
: Bien(surface)
, m_nombrePieces(nombrePieces)
{

}

Appartement::~Appartement()
{

}

void Appartement::addPiece(float surface)
{
	m_surface += surface;
	m_nombrePieces++;
}