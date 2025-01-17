#ifndef CAMERA_h
#define CAMERA_h

#include "../math/mat4.h"
#include "../math/vec3.h"
#include "gameobject.h"

typedef struct {
    GameObject game_object;
    float fov;
    float zNear, zFar;
    float aspect;
} Camera;

/*
 * perspective - Calculate a perspective projection matrix
 * @cam: The Camera containing the field of view, aspect ratio, and near/far
 * planes
 *
 * Calculate a 4x4 perspective projection matrix based on the Camera's
 * parameters.
 *
 * Source:
 * https://registry.khronos.org/OpenGL-Refpages/gl2.1/xhtml/gluPerspective.xml
 *
 * Return: The perspective projection matrix.
 */
Mat4 perspective(const Camera *cam);
Mat4 orthographic(const Camera *cam);

/*
 * view - Calculate a view matrix
 * @cam: The Camera containing the eye position, target position, and up vector
 *
 * Calculate a 4x4 view matrix based on the Camera's parameters.
 *
 *
 * Return: The view matrix.
 */
Mat4 view(const Camera *cam);

/*
 * lookAt - Calculate a view matrix using the lookAt method
 * @eye: The position of the eye point
 * @center: The position of the center of interest
 * @up: The up vector
 *
 * Calculate a 4x4 view matrix based on the eye position, center of interest,
 * and up vector.
 *
 * Source: (Add your source here if available)
 *
 * Return: The view matrix.
 */
Mat4 lookAt(const Vec3 eye, const Vec3 center, const Vec3 up);

#endif
