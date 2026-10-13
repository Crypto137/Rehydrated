#pragma once

#include <rex/types.h>

struct Vector3D
{
	rex::be<f32> x;
	rex::be<f32> y;
	rex::be<f32> z;
};

typedef Vector3D VelocityVector3D;
typedef Vector3D AccelVector3D;
typedef Vector3D ImpulseVector3D;
