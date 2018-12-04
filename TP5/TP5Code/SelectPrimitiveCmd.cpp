///////////////////////////////////////////////////////////
//  SelectPrimitiveCmd.cpp
//  Implementation of the Class SelectPrimitiveCmd
//  Created on:      08-nov.-2018 21:05:02
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "SelectPrimitiveCmd.h"
#include "VisitorPrimitiveSelector.h"

SelectPrimitiveCmd::SelectPrimitiveCmd(PRIMITIVE_TYPE typ, Object3DAbs & obj3d)
	: m_type(typ), m_obj3d(obj3d)
{
}

SelectPrimitiveCmd::~SelectPrimitiveCmd()
{
}

void SelectPrimitiveCmd::cancel()
{
	m_selectObjContainer.clear();
	// A COMPLETER: Vider le conteneur local a la commande d'objets selectionnes
}


void SelectPrimitiveCmd::execute()
{
	VisitorPrimitiveSelector visitor = VisitorPrimitiveSelector(m_type);
	m_obj3d.accept(visitor);
	visitor.getSelectObjects(m_selectObjContainer);

	// A COMPLETER:
	//		- Construire un visiteur de selection
	//		- Appliquer le visiteur a l'objet 3d
	//		- Recuperer les objets selectionnes dans le conteneur local de la commande
}

void SelectPrimitiveCmd::getSelectObjects(Obj3DIteratorContainer & objContainer)
{
	for each (auto it in m_selectObjContainer)
	{
		objContainer.push_back(it);
	}
	// A COMPLETER:
	// Transferer les objets selectionnes du conteneur local a la commande
	// vers le conteneur fourni en argument
}
