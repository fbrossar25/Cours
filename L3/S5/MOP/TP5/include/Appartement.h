#ifndef APPARTEMENT_H
#define APPARTEMENT_H

#include "Bien.h"

class Appartement : public Bien
{
public:
	explicit Appartement();
	explicit Appartement(float surface, unsigned int nombrePieces);
	virtual ~Appartement();
	void addPiece(float surface);
	inline unsigned int getNumberOfPieces() { return(m_nombrePieces); };
	inline float getSurface() { return(m_surface); };

private:
	unsigned int m_nombrePieces;
};

#endif