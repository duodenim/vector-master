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
  gameManager = SpawnObject<GameManager>();
  SpawnObject<Tube>();


}
void World::DestroyWorld() {
  objectManager->DestroyAllObjects();
}
