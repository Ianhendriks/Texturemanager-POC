#ifndef COMPONENT_H
#define COMPONENT_H
#include "Entity.h"

class Component
{
public:
    Component(Entity& e);
    ~Component() = default;
    void OnUpdate();
    Entity& entity;
};

#endif
