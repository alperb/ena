#include <math.h>
#include <iostream>
#include "Skybox.h"

Skybox::Skybox(): CubeMap() { 
    faces = { "right.jpg", "left.jpg", "top.jpg", "bottom.jpg", "front.jpg", "back.jpg" };
}