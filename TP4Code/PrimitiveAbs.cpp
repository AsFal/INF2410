///////////////////////////////////////////////////////////
//  PrimitiveAbs.cpp
//  Implementation of the Class PrimitiveAbs
//  Created on:      25-oct.-2018 20:47:13
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "PrimitiveAbs.h"

// Declaration d'un conteneur vide pour retourner des iterateurs toujours valides
Objet3DContainer PrimitiveAbs::m_emptyContainer;

PrimitiveAbs::PrimitiveAbs(){
	m_center = Point3D();
}

PrimitiveAbs::PrimitiveAbs(const Point3D& c)
{
	m_center = c;
}

PrimitiveAbs::~PrimitiveAbs(){

}

void PrimitiveAbs::addChild(const Objet3DAbs& obj3d){
	// Echoue silencieusement
}

Objet3DIterator PrimitiveAbs::begin(){

	Objet3DIterator it = m_emptyContainer.begin();
	return it;
}

Objet3DIterator_const PrimitiveAbs::cbegin() const {

	//Not too sure about this one
	Objet3DIterator_const it = m_emptyContainer.begin();
	return it;
}

Objet3DIterator_const PrimitiveAbs::cend() const {

	//Not too sure about this one
	Objet3DIterator_const it = m_emptyContainer.end();
	return it;
}

Objet3DIterator PrimitiveAbs::end(){
	// A Completer...
	Objet3DIterator it = m_emptyContainer.end();
	return it;
}

void PrimitiveAbs::removeChild(Objet3DIterator_const obj3dIt){
	// Echoue silencieusement
}

Point3D PrimitiveAbs::getCenter() const {

	return  m_center;
}

void PrimitiveAbs::moveCenter(const Point3D & delta)
{
	m_center += delta;
}

void PrimitiveAbs::setCenter(const Point3D& center)
{
	m_center = center;
}

std::ostream & operator<<(std::ostream & o, const Objet3DAbs& obj3d )
{
	return obj3d.toStream(o);
}
