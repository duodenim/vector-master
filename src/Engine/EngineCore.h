//
// Created by joseph on 12/23/16.
//

//Contains State Information for the currently running game

//TODO - Typedef some common data types
#ifndef PONGGL_ENGINECORE_H
#define PONGGL_ENGINECORE_H


#include "Renderer.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "AudioSystem.h"
#include "../Game/World.h"
#include <GLFW/glfw3.h>

enum class GameState {
  GAME_STARTUP,
  GAME_RUNNING,
  GAME_SHUTDOWN
};
class EngineCore {
 public:
  void Init();
  void BeginGame();
  void GameLoop();
  void Quit();
  void Shutdown();

  static EngineCore *GetEngine();
  Renderer *GetRenderer(){return renderer;};
  ObjectManager *GetObjectManager(){return objManager;};
  InputManager *GetInputManager(){return inputManager;};
  AudioSystem *GetAudioSystem() {return audioSystem; };
  World *GetWorld(){return world;};

  //TODO - Move delta-time calculation out of EngineCore
  double deltaTime;

 private:
  static EngineCore *engine;
  Renderer *renderer;
  ObjectManager *objManager;
  InputManager *inputManager;
  AudioSystem *audioSystem;
  World *world;
  GameState state;
  GLFWwindow *window;
  void GLFW_Startup();
  void GLFW_Shutdown();

};



#endif //PONGGL_ENGINECORE_H
