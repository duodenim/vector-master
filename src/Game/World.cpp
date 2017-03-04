//
// Created by joseph on 12/31/16.
//

#include "World.h"
#include "../Engine/EngineCore.h"
#include "Player.h"
#include "Wall.h"
#include "Tube.h"
World::World() {
  objectManager = EngineCore::GetEngine()->GetObjectManager();
}
World::~World() {

}
void World::CreateWorld() {
  //Game init code goes here

  //Spawn all GameObjects
  Player *player1 = SpawnObject<Player>();
  gameManager = SpawnObject<GameManager>();
  SpawnObject<Tube>();
  gameManager->SetPlayer(player1);


  player1->SetPosition(glm::vec3(-0.48f, 0.0f, 0.0f));


}
void World::DestroyWorld() {
  objectManager->DestroyAllObjects();
}
