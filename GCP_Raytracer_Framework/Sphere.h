#pragma once
#include "BaseObject.h"
#include "Ray.h"
#include <GLM/glm.hpp>

struct Sphere : public BaseObject
{
public:
	Sphere(glm::vec3 mPosition, glm::vec3 mColour, float mRadius);


	bool RayCollide(Ray _ray, glm::vec3& _CollidePoint);
	glm::vec3 NormalPosition(glm::vec3 _CollidePoint);

private:
	float mRadius;


};