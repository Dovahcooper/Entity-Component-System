#include "Entity.h"

unsigned int Entity::m_numEntities = 0;

Entity::Entity() {
	m_entityID = m_numEntities++;
}

Entity::~Entity() {
	m_numEntities--;
}