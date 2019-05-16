#pragma once

#include <btBulletDynamicsCommon.h>
#include <glm/glm.hpp>
#include <array>
#include <glm/gtc/quaternion.hpp>
#include <memory>
#include <mos/gfx/mesh.hpp>

namespace mos
{

btVector3 inline to_bt(const glm::vec3 &vec) {
  return btVector3(vec.x, vec.y, vec.z);
}

glm::vec3 inline to_glm(const btVector3 &vec) {
  return glm::vec3(vec.getX(), vec.getY(), vec.getZ());
}

btQuaternion inline to_bt(const glm::quat &quat){
  return btQuaternion(quat.x, quat.y, quat.z, quat.w);
}

std::unique_ptr<btTriangleMesh> inline to_bt(const mos::gfx::Mesh & mesh)
{
  std::unique_ptr<btTriangleMesh> bt_mesh = std::make_unique<btTriangleMesh>();
  for (std::size_t i = 0; i < mesh.triangles.size(); i++) {
    auto i0 = mesh.triangles[i][0];
    auto i1 = mesh.triangles[i][1];
    auto i2 = mesh.triangles[i][2];

    auto p0 = glm::vec3(glm::vec4(mesh.vertices[i0].position, 1.0f));
    auto p1 = glm::vec3(glm::vec4(mesh.vertices[i1].position, 1.0f));
    auto p2 = glm::vec3(glm::vec4(mesh.vertices[i2].position, 1.0f));

    bt_mesh->addTriangle(to_bt(p0), to_bt(p1), to_bt(p2));
  }
  return bt_mesh;
}

}
