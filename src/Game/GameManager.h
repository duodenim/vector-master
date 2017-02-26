//
// Created by joseph on 1/6/17.
//

#ifndef PONGGL_SCOREMANAGER_H
#define PONGGL_SCOREMANAGER_H

#include "../Engine/GameObject.h"
#include "../Engine/Components/AudioSourceComponent.h"
#include "../Engine/Components/InputComponent.h"
#include "../Engine/Components/AudioSourceComponent.h"
#include "ScoreDisplay.h"
#include "Player.h"

enum class GameState {
  GAME_INTRO,
  GAME_PLAY,
  GAME_END
};

class GameManager : public GameObject{
 public:
  GameManager();
  ~GameManager();
  void Update(float deltaTime);
  void SetPlayer(Player* player);
  void EndGame();
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
  bool firstFrame;

  Player* mainPlayer;
  ScoreDisplay* sDisplay;
  GameState state;



};

#endif //PONGGL_SCOREMANAGER_H
