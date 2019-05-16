[![GitHub license](https://img.shields.io/github/license/morganbengtsson/mos.svg)](https://github.com/morganbengtsson/mos/blob/master/LICENCE.rst)

# Introduction

MOS-CONV contains methods to convert between types from the libraries [MOS](https://github.com/morganbengtsson/mos-skeleton),
 [GLM](https://github.com/g-truc/glm) and [Bullet](https://github.com/bulletphysics/bullet3).

# Example

```cpp
#include <mos/convert.hpp>
#include <mos/gfx/mesh.hpp>
#include <glm/glm.hpp>
#include <btBulletDynamicsCommon.h>

btVector3 v0 = btVector3(0.0f, 0.0f, 1.0f);
glm::vec3 v1 = mos::to_glm(v0);
btVector3 v2 = mos::to_bt(v1);

mos::gfx::Mesh mesh = mos::gfx::Mesh({mos::gfx::Vertex(), mos::gfx::Vertex(), mos::gfx::Vertex()}, {{0,1,2}});
std::unique_ptr<btTriangleMesh> shape = mos::to_bt(mesh);

```

# Companion projects

- [MOS Skeleton](https://github.com/morganbengtsson/mos-skeleton): An example project to quickly get up and running.
- [MOS Blender export](https://github.com/morganbengtsson/mos-blender-export): Export scripts/addon for Blender 2.80, to export
models, levels and other entities.

