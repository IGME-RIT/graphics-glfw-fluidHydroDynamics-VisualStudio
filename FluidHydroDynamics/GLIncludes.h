/*
Title: Fluid Simulation (SPH)
File Name: GLincludes.h
Copyright � 2015
Original authors: Srinivasan Thiagarajan
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Description:
Description:
In this example we use the previous "Fluid Simulation (SPH)" example to
demonstrate the hydrodynamics of fluid.
Fluid when poured onto a a container which is connected to another by a
pipe along the bottom, the fluid flows into the second container until
the level of fluid is the same on both containers. This is because it
need to balance the pressure on both sides. The pressure on each side is
independant of the surface area and dependant on the height.
So, if external pressure is applied on any one side, the fluid level changes
or more accurately balances out the difference in p[ressure between the two containers.

In this example, all the fluid particles are released in one container and
they gradually flow into the adjacent container until there is equal liquid in both
the containers.

Press "SHIFT" to start simulation
Use "SPACE" to toggle gravity in x-axis, or use "W" to toggle gravity in y-axis.

Changing gravity in x-axis will cause all the fluid to flow into the left container.

References:
Real time collision Detection by Ericson
AABB-2D by Brockton Roth
Nicholas Gallagher
*/


#ifndef _GL_INCLUDES_H
#define _GL_INCLUDES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include "GL\glew.h"
#include "glfw\glfw3.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtc\quaternion.hpp"
#include "glm\gtx\quaternion.hpp"
#include "glm\gtx\rotate_vector.hpp"


#define PI 3.14159265
#define DIVISIONS  15

// We create a VertexFormat struct, which defines how the data passed into the shader code wil be formatted
struct VertexFormat
{
	glm::vec4 color;	// A vector4 for color has 4 floats: red, green, blue, and alpha
	glm::vec3 position;	// A vector3 for position has 3 float: x, y, and z coordinates

	// Default constructor
	VertexFormat()
	{
		color = glm::vec4(0.0f);
		position = glm::vec3(0.0f);
	}

	// Constructor
	VertexFormat(const glm::vec3 &pos, const glm::vec4 &iColor)
	{
		position = pos;
		color = iColor;
	}
};

#endif _GL_INCLUDES_H