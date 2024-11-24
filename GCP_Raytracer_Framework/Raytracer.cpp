#include "Raytracer.h"
#include "Timer.h"
#include <iostream>

glm::vec3 Raytracer::TraceRay(Ray ray)
{
	//ScopedTimer Timer("TraceRay Timer");
	glm::vec3 PixelColour{ 0.0f };
	glm::vec3 CloseCollidePosition(0.0f, 0.0f, 0.0f);

	float CloseDepth = 10000000.0f;
	BaseObject* ClosestObject = nullptr;
	for (int i = 0; i < objects.size(); i++)
	{
		glm::vec3 CollidePosition;
		if (objects[i]->RayCollide(ray, CollidePosition))
		{
			float Depth = glm::length(CollidePosition - ray.mOrigin);
			if (Depth < CloseDepth)
			{
				//Depth perception is the ability to see things in three dimensions (including length, width and depth), and to judge how far away an object is. 
				//Depth perception is made possible by monocular (one eye) and binocular (two eyes) cues.
				CloseDepth = Depth;
				CloseCollidePosition = CollidePosition;
				ClosestObject = objects[i];
			}
		}

	}
	
	for (int i = 0; i < lights.size(); i++)
	{
		PixelColour += ClosestObject->ShadePosition(CloseCollidePosition,lights[i]->mPosition,lights[i]->mColour,ray.mOrigin);
	}
	return PixelColour;

}