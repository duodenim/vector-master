//
// Created by joseph on 12/23/16.
//

#include "EngineCore.h"

void EngineCore::Init() {
  state = GameState::GAME_STARTUP;
  GLFW_Startup();
  renderer = new Renderer(540, 960);
  inputManager = new InputManager(window);
  objManager = new ObjectManager;
  audioSystem = new AudioSystem;
  world = new World;
}
void EngineCore::BeginGame() {
  state = GameState ::GAME_RUNNING;
  world->CreateWorld();
}
void EngineCore::GameLoop() {
  while (state == GameState::GAME_RUNNING) {
    //Run events
    deltaTime = glfwGetTime();
    glfwSetTime(0.0f);
    inputManager->PollInputs();

    renderer->BeginFrame();
    objManager->Update();

    glfwSwapBuffers(window);
    if(glfwWindowShouldClose(window))
      Quit();

  }
}
void EngineCore::Quit() {
  state = GameState::GAME_SHUTDOWN;
  world->DestroyWorld();
}
void EngineCore::Shutdown() {
  objManager->DestroyAllObjects();
  delete audioSystem;
  delete renderer;
  delete objManager;
  delete inputManager;
  delete world;
  GLFW_Shutdown();
}

void EngineCore::GLFW_Startup() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //glfwWindowHint(GLFW_SAMPLES, 8);
  window = glfwCreateWindow(540, 960, "Game", NULL, NULL);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  return;
}

void EngineCore::GLFW_Shutdown() {
  glfwDestroyWindow(window);
  glfwTerminate();

  return;
}

//TODO - Try to remove singleton design from engine
EngineCore *EngineCore::engine = 0;
EngineCore *EngineCore::GetEngine() {
  if(!engine)
    engine = new EngineCore();
  return engine;
}