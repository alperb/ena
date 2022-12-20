#pragma once

#include <vector>

#include "Object.h"


class Scene {
public:
    Scene();
    ~Scene();

    void addObject(Object* object);
    const std::vector<Object*> getObjects() const;
private:
    std::vector<Object*> objects;
};