///////////////////////////////////////////////////////////
//  Torus.cpp
//  Implementation of the Class Torus
//  Created on:      08-nov.-2018 12:51:51
//  Original author: Alexandre Falardeau - Evan Kirby McGregor
///////////////////////////////////////////////////////////

#include "Torus.h"

Torus::Torus(const Point3D& pt, float ir, float or)
	: PrimitiveAbs(pt)
{
	if (ir < 0.0 || or < 0.0)
		throw std::range_error("Invalid dimension value for cube. Must be larger than 0");

	m_dimensions[0] = ir;
	m_dimensions[1] = or;
}

Torus::~Torus() {
}

Torus * Torus::clone() const
{
	// A Completer...
	return new Torus(m_center, m_dimensions[0], m_dimensions[1]);
}

size_t Torus::getNbParameters() const {

	// A Completer...
	return 2;
}

PrimitiveParams Torus::getParameters() const
{
	// A Completer...
	PrimitiveParams params;
	params.push_back(m_dimensions[0]);
	params.push_back(m_dimensions[1]);
	return params;
}

void Torus::setParameter(size_t pIndex, float pValue) {

	if (pIndex < 0 || pIndex > 2)
		throw std::range_error("Invalid parameter index for cube. Must be between 0 and 2");

	if (pValue<0.0)
		throw std::range_error("Invalid dimension value for cube. Must be larger than 0");

	m_dimensions[pIndex] = pValue;
}

std::ostream & Torus::toStream(std::ostream & o) const
{
	return o << "Torus:      center = " << m_center
		<< "; inner radius = " << m_dimensions[0]
		<< "; outer radius = " << m_dimensions[1] << ";";
}
