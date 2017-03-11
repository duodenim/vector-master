//
// Created by joseph on 1/6/17.
//

#include "GameManager.h"
#include "../Engine/EngineCore.h"
#include "Bullet.h"
#include "Enemy.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
glm::vec3 enemyPositions[8] = {
  glm::vec3(-0.48f, 0.0f, -4.0f),
  glm::vec3(0.48f, 0.0f, -4.0f),
  glm::vec3(0.0f, 0.48f, -4.0f),
  glm::vec3(0.0f, -0.48f, -4.0f),
  glm::vec3(0.24f, 0.24f, -4.0f),
  glm::vec3(-0.24f, 0.24f, -4.0f),
  glm::vec3(-0.24f, -0.24f, -4.0f),
  glm::vec3(0.24f, -0.24f, -4.0f)
};
GameManager::GameManager() {
  player1Score = 0;
  player2Score = 0;
  camera = new CameraComponent;
  camera->SetAsMainCamera();
  iComponent = new InputComponent;
  bulletRot = 0.0f;
  rot = 0.0f;
  totalTime = 0.0f;
  srand(time(NULL));
  state = GameState::GAME_INTRO;

  World* world = EngineCore::GetEngine()->GetWorld();
  sDisplay = world->SpawnObject<ScoreDisplay>();
  sDisplay->countScore = false;

  mainMenu = world->SpawnObject<Menu>();

}
GameManager::~GameManager() {
	delete camera;
  delete iComponent;

}
void GameManager::Update(float deltaTime) {
  World* world = EngineCore::GetEngine()->GetWorld();
  totalTime += deltaTime;
  if (state == GameState::GAME_PLAY) {
    int spawnFactor = 50;
    if (totalTime > 300) {
      spawnFactor = 20;
    }
    else {
      spawnFactor = 50 - (5.0f / 30.0f) * (totalTime);
    }
    if (rand() % spawnFactor == 0) {
      Enemy* enemy = world->SpawnObject<Enemy>();
      enemy->SetPosition(enemyPositions[rand() % 8]);
      enemy->SetSpeed(1.0f + totalTime / 100.0f);
    }

    camera->position.y = 0.05 * sin(totalTime);
    camera->position.x = 0.05 * cos(totalTime);
    camera->RecalulatePosition();
  }
  else if (state == GameState::GAME_END){
    bool reset = false;
    if (glfwJoystickPresent(GLFW_JOYSTICK_1) == GLFW_TRUE) {
      int buttonCount;
      const unsigned char *buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
      reset = buttons[3];
    }
    else {
      reset = iComponent->GetKeyState(GLFW_KEY_Y);
    }
    if (mainMenu->play) {
      Reset();
    }
  }
  else {
    //Show game menu
    if (mainMenu->play) {
      Reset();
    }
  }
}

void GameManager::SetPlayer(Player * player) {
  mainPlayer = player;
}

void GameManager::EndGame(){
  sDisplay->countScore = false;
  state = GameState::GAME_END;
  mainMenu->active = true;
  mainPlayer->Destroy();

}

void GameManager::Reset() {
  mainPlayer = EngineCore::GetEngine()->GetWorld()->SpawnObject<Player>();
  mainPlayer->SetPosition(glm::vec3(-0.48f, 0.0f, 0.0f));
  sDisplay->ResetScore();
  sDisplay->countScore = true;
  state = GameState::GAME_PLAY;
  totalTime = 0.0f;
  mainMenu->active = false;
  mainMenu->play = false;
}
