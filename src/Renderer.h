#pragma once


#include "Scene.h"

class Renderer {
public:
    static void Render(const Scene& scene);
    static void Clear();
};