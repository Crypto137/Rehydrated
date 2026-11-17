#pragma once

#include "core/memory.h"

struct Vector3D
{
	be<f32> x;
	be<f32> y;
	be<f32> z;
};

typedef Vector3D VelocityVector3D;
typedef Vector3D AccelVector3D;
typedef Vector3D ImpulseVector3D;
