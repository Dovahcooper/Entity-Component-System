#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "SmartPointer.h"

class Entity {
public:
	Entity();
	~Entity();

protected:

private:

	static unsigned int m_numEntities;
	int m_entityID;

	SmartPointer<Entity> m_parent;
	std::vector<SmartPointer<Entity>> m_children;
};

#endif