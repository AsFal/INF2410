///////////////////////////////////////////////////////////
//  VisitorPrimitiveSelector.cpp
//  Implementation of the Class VisitorPrimitiveSelector
//  Created on:      07-nov.-2018 21:20:38
//  Original author: p482457
///////////////////////////////////////////////////////////

#include <exception>

#include "VisitorPrimitiveSelector.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Object3DComposite.h"
#include "TransformedObject3D.h"

VisitorPrimitiveSelector::VisitorPrimitiveSelector(PRIMITIVE_TYPE typ)
	: m_type(typ)
{
}

VisitorPrimitiveSelector::~VisitorPrimitiveSelector()
{
}

void VisitorPrimitiveSelector::visitCube(class Cube& cub)
{
	// A COMPLETER:
	if (!m_currentObjStack.empty()) {
		if (PRIMITIVE_TYPE::Cube_t == m_type)
			m_selectObjContainer.push_back(m_currentObjStack.back());
	}
	// Verifier que la pile d'objets courants n'est pas vide
	// Verifier que le type de la primitive est bien celui recherchee
	// Si oui, ajouter la primitive dans les objets selectionnes
}

void VisitorPrimitiveSelector::visitCylinder(class Cylinder& cyl)
{

	if (!m_currentObjStack.empty()) {
		if (PRIMITIVE_TYPE::Cylinder_t == m_type)
			m_selectObjContainer.push_back(m_currentObjStack.back());
	}
	// A COMPLETER:
	// Verifier que la pile d'objets courants n'est pas vide
	// Verifier que le type de la primitive est bien celui recherchee
	// Si oui, ajouter la primitive dans les objets selectionnes
}

void VisitorPrimitiveSelector::visitObjComposite(const Object3DComposite& comp)
{
	throw(std::invalid_argument("VisitorPrimitiveSelector cannot process const Objects"));
}

void VisitorPrimitiveSelector::visitObjComposite(class Object3DComposite& comp)
{
	// A COMPLETER:
	Object3DIterator it = comp.begin();
	Object3DIterator end = comp.end();
	while (it != end) {
		m_currentObjStack.push_back(it);
		it->accept(*this);
		m_currentObjStack.pop_back();
		it++;
	}
	// Iterer sur les enfants du composite
	//		- Stocker l'enfant sur la pile des objets courants
	//		- Traiter l'enfant
	//		- Retirer l'enfant de sur la pile
}

void VisitorPrimitiveSelector::visitPrimitive(const class PrimitiveAbs& prim)
{
	throw(std::invalid_argument("VisitorPrimitiveSelector cannot process const Objects"));
}

void VisitorPrimitiveSelector::visitPrimitive(class PrimitiveAbs& prim)
{
	// Type de primitive inconnue... cette primitive n'est pas selectionnee
}

void VisitorPrimitiveSelector::visitSphere(class Sphere& sph)
{

	if (!m_currentObjStack.empty()) {
		if (PRIMITIVE_TYPE::Sphere_t == m_type)
			m_selectObjContainer.push_back(m_currentObjStack.back());
	}
	//Object3DIterator()
	// A COMPLETER:
	// Verifier que la pile d'objets courants n'est pas vide
	// Verifier que le type de la primitive est bien celui recherchee
	// Si oui, ajouter la primitive dans les objets selectionnes
}

void VisitorPrimitiveSelector::visitTransformedObj(class TransformedObject3D& tobj)
{
	// A COMPLETER:
	// Deleguer le traitement a la primitive contenue dans le decorateur
	tobj.getObject3D().accept(*this);
}

void VisitorPrimitiveSelector::getSelectObjects(Obj3DIteratorContainer & objContainer)
{
	// A COMPLETER:
	for each (auto it in m_selectObjContainer)
	{
		objContainer.push_back(it);
	}
	// Transferer les objets selectionnes du conteneur local au visiteur
	// vers le conteneur fourni en argument
}
