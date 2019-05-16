cmake_minimum_required (VERSION 3.1.0)
project(mos-phy)

# mos
file(GLOB_RECURSE PHY_SOURCE src/mos/*.cpp)
file(GLOB_RECURSE PHY_HEADER include/mos/*.hpp)

add_library(${PROJECT_NAME} STATIC ${PHY_HEADER} ${PHY_SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC mos BulletDynamics BulletCollision LinearMath ${BULLET_LIBRARIES})
