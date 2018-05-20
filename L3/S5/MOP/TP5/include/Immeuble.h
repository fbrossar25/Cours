
#ifndef IMMEUBLE_H
#define IMMEUBLE_H

#include <vector>

#include "Bien.h"
#include "Appartement.h"

class Immeuble : public Bien
{
public:
	explicit Immeuble();
	virtual ~Immeuble();
	void addAppartement(Appartement *appartement);

private:
	std::vector<Appartement*> m_appartements;
};

#endif