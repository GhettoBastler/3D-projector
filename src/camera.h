#ifndef CAMERA_H
#define CAMERA_H

#include "primitives.h"

#define WIDTH 720
#define HEIGHT 480
#define SCALE 80

typedef struct {
    float width, height;
    float focal_length;
    float transform_mat[16];
    float orbit_radius;
} Camera;

Point2D project_point(Point3D point, Camera* pcam);
Camera make_camera(float width, float height, float focal_length);
void update_transform_matrix(float* mat, Point3D rotation, Point3D translation, bool orbit, float orbit_radius);
TriangleMesh* project_tri_mesh(ProjectedMesh* pbuffer, TriangleMesh* pmesh, Camera* pcam, bool do_cull);
bool point_is_visible(Edge3D edge, float ratio, TriangleMesh* pmesh, int start_idx);

#endif
