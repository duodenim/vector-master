#ifndef MENU_H
#define MENU_H
#include "../Engine/GameObject.h"
#include <vector>
#include "../Engine/Components/MeshComponent.h"
#include "../Engine/Components/InputComponent.h"
class Menu : public GameObject {
public:
  Menu();
  ~Menu();
  void Update(float deltaTime);
  bool active;
  bool gameOverActive;
  bool play;
private:
  std::vector<MeshComponent*> text;
  std::vector<MeshComponent*> gameOverText;
  MeshComponent* selector;
  InputComponent* iComponent;
  glm::vec3 selectorLocations[3];
  int selectorPos;
  bool keyDown;

  float gameOverFade;
  
};

#endif