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
  glm::vec3(-0.24f, 0.0f, -4.0f),
  glm::vec3(0.24f, 0.0f, -4.0f),
  glm::vec3(0.0f, 0.24f, -4.0f),
  glm::vec3(0.0f, -0.24f, -4.0f),
  glm::vec3(0.12f, 0.12f, -4.0f),
  glm::vec3(-0.12f, 0.12f, -4.0f),
  glm::vec3(-0.12f, -0.12f, -4.0f),
  glm::vec3(0.12f, -0.12f, -4.0f)
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
  spawnBullet = 1;
  srand(time(NULL));
}
GameManager::~GameManager() {
	delete camera;
  delete iComponent;

}
void GameManager::Update(float deltaTime) {
  World* world = EngineCore::GetEngine()->GetWorld();
  totalTime += deltaTime;
  if(spawnBullet) {
    if (iComponent->GetKeyState(GLFW_KEY_Q)) {
      rot += 0.1f;
    }
    if (iComponent->GetKeyState(GLFW_KEY_E)) {
      rot -= 0.1f;
    }
    bulletRot += rot;
    spawnBullet--;
    
  }
  if (rand() % 100 == 0) {
    Enemy* enemy = world->SpawnObject<Enemy>();
    enemy->SetPosition(enemyPositions[rand() % 8]);
  }
  
  camera->position.y = 0.05 * sin(totalTime);
  camera->position.x = 0.05 * cos(totalTime);
  camera->RecalulatePosition();
}

void GameManager::SetPlayer(Player * player) {
  mainPlayer = player;
}

void GameManager::Reset() {
}
