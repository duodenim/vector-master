//
// Created by joseph on 1/6/17.
//

#ifndef PONGGL_SCOREMANAGER_H
#define PONGGL_SCOREMANAGER_H

#include "../Engine/GameObject.h"
#include "../Engine/Components/AudioSourceComponent.h"
#include "../Engine/Components/InputComponent.h"
#include "../Engine/Components/AudioSourceComponent.h"
#include "Player.h"

class GameManager : public GameObject{
 public:
  GameManager();
  ~GameManager();
  void Update();
  void SetPlayer(Player* player);
 private:
  int player1Score;
  int player2Score;
  void Reset();
  CameraComponent* camera;
  InputComponent* iComponent;
  AudioSourceComponent* audio;
  float bulletRot;
  float rot;
  float totalTime;
  int spawnBullet;

  Player* mainPlayer;



};

#endif //PONGGL_SCOREMANAGER_H
