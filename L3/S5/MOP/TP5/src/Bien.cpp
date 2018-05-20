#include "Bien.h"

Bien::Bien()
: m_surface(0.0)
{

}

Bien::Bien(float surface)
: m_surface(surface)
{

}

Bien::~Bien()
{

}

float Bien::getSurface()
{
	return(m_surface);
}