#ifndef BIEN_H
#define BIEN_H

class Bien
{
public:
	explicit Bien();
	explicit Bien(float surface);
	virtual ~Bien();
	float getSurface();

protected:
	float m_surface;
};

#endif