cmake_minimum_required(VERSION 3.5)
project(TMBR CXX)

set(CMAKE_CXX_STANDARD 11)

set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOO "" FORCE)

add_subdirectory(${CMAKE_SOURCE_DIR}/deps/openal)
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/glew-2.0.0/build/cmake)
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/glfw-3.2.1)
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/soil)

set(SOURCE_FILES src/main.cpp
                 src/Engine/EngineCore.cpp
                 src/Engine/EngineCore.h
                 src/Engine/Renderer.cpp
                 src/Engine/Renderer.h
                 src/Engine/GameObject.cpp
                 src/Engine/GameObject.h
                 src/Engine/Shader.cpp
                 src/Engine/Shader.h
                 src/Engine/ObjectManager.cpp
                 src/Engine/ObjectManager.h
                 src/Engine/InputManager.cpp
                 src/Engine/InputManager.h
                 src/Engine/Component.cpp
                 src/Engine/Component.h
                 src/Engine/AudioSystem.cpp
                 src/Engine/AudioSystem.h
                 src/Engine/Components/MeshComponent.cpp
                 src/Engine/Components/MeshComponent.h
                 src/Engine/Components/InputComponent.cpp
                 src/Engine/Components/InputComponent.h
                 src/Engine/Components/AudioSourceComponent.cpp
                 src/Engine/Components/AudioSourceComponent.h
                 src/Engine/Components/CameraComponent.cpp
                 src/Engine/Components/CameraComponent.h
                 src/Engine/Components/CollisionBox2DComponent.cpp
                 src/Engine/Components/CollisionBox2DComponent.h
                 src/Engine/Components/CollisionCircle2DComponent.cpp
                 src/Engine/Components/CollisionCircle2DComponent.h
                 src/Game/GameManager.cpp
                 src/Game/GameManager.h
                 src/Game/Player.cpp
                 src/Game/Player.h
                 src/Game/Bullet.cpp
                 src/Game/Bullet.h
                 src/Game/World.cpp
                 src/Game/World.h
                 src/Game/Wall.cpp
                 src/Game/Wall.h
                 src/Game/Enemy.cpp
                 src/Game/Enemy.h
                 src/Game/Tube.cpp
                 src/Game/Tube.h)

include_directories(${CMAKE_SOURCE_DIR}/deps/openal/include)
include_directories(${CMAKE_SOURCE_DIR}/deps/glew-2.0.0/include/GL)
include_directories(${CMAKE_SOURCE_DIR}/deps/glfw-3.2.1/include)
include_directories(${CMAKE_SOURCE_DIR}/deps/soil/src)
include_directories(${CMAKE_SOURCE_DIR}/deps/glm/glm)


add_executable(TMBR ${SOURCE_FILES})

if(UNIX)
	set(AUDIO_LIB openal)
else()
	set(AUDIO_LIB OpenAL32)
endif()

target_link_libraries(TMBR glew_s SOIL glfw ${AUDIO_LIB})
