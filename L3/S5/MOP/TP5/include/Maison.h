#ifndef MAISON_H
#define MAISON_H

#include "Bien.h"

class Maison : public Bien
{
public:
	explicit Maison();
	explicit Maison(float surface, unsigned int nombrePieces);
	virtual ~Maison();
	void addPiece(float surface);
	inline unsigned int getNumberOfPieces() { return(m_nombrePieces); };

private:
	unsigned int m_nombrePieces;
};

#endif