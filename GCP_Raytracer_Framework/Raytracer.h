#pragma once
#include "Ray.h"
#include "BaseObject.h"
#include "Light.h"
#include <GLM/glm.hpp>
#include <vector>


class Raytracer
{
public:
	glm::vec3 TraceRay(Ray ray);
	std::vector<BaseObject*> objects;
	std::vector<Light*> lights;
};