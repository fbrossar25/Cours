#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

class Personne
{
public:
	explicit Personne(std::string nom, std::string prenom);
	virtual ~Personne();
	inline std::string getNom() { return(m_nom); };
	inline std::string getPrenom() { return(m_prenom); };

protected:
	std::string m_nom, m_prenom;
};

#endif