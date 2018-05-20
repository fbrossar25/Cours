#ifndef MAISON_H
#define MAISON_H

#include "facade.h"
#include <assert.h>
#include <vector>
#include <iostream>

class CMaison
{
public:
	CMaison();
	~CMaison();
	void addFacade();
    void addFacade(bool hasPignon);
    void addFacade(float largeur, float hauteur);
    void addFacade(float RLargeur, float RHauteur, float PHauteur);
    inline CFacade *getLastFacade() { return &(m_facades.back()); };
	float getAireACrepir() const;
	void printStats() const;

private:
	std::vector <CFacade> m_facades;
};

#endif