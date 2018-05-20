#ifndef CLIENT_H
#define CLIENT_H

#include "Personne.h"

class Client : public Personne
{
public:
	explicit Client(std::string nom, std::string prenom, std::string addresse, std::string numero,
					bool acheteur, bool vendeur, bool loueur, bool locataire);
	virtual ~Client();
	inline std::string getAddresse() { return(m_addresse); };
	inline std::string getNumero() { return(m_numero); };
	inline bool isAcheteur() { return(m_type[0]); };
	inline bool isVendeur() { return(m_type[1]); };
	inline bool isLoueur() { return(m_type[2]); };
	inline bool isLocataire() { return(m_type[3]); };

private:
	std::string m_addresse, m_numero;
	bool m_type[4];//[0] : acheteur, [1] : vendeur, [2] : loueur, [3] : locataire
};

#endif