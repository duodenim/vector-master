#include "Menu.h"
#include "Font.h"
#include "../Engine/EngineCore.h"
GLfloat selectorBox[] = {
  -0.2f, -0.05f, 0.0f,
  -0.2f, 0.05f, 0.0f,
  0.2f, 0.05f, 0.0f,
  0.2f, -0.05f, 0.0f
};

Menu::Menu() {
  MeshComponent* tmp;

  //Menu Options
  //Play
  tmp = new MeshComponent(pVerts, pSize);
  tmp->position = glm::vec3(-0.15f, 0.2f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(lVerts, lSize);
  tmp->position = glm::vec3(-0.05f, 0.2f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(aVerts, aSize);
  tmp->position = glm::vec3(0.05f, 0.2f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(yVerts, ySize);
  tmp->position = glm::vec3(0.15f, 0.2f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);

  //Quit
  tmp = new MeshComponent(qVerts, qSize);
  tmp->position = glm::vec3(-0.15f, 0.0f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(uVerts, uSize);
  tmp->position = glm::vec3(-0.05f, 0.0f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(iVerts, iSize);
  tmp->position = glm::vec3(0.05f, 0.0f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(tVerts, tSize);
  tmp->position = glm::vec3(0.15f, 0.0f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);

  //Title 
  tmp = new MeshComponent(sVerts, sSize);
  tmp->position = glm::vec3(-0.30f, 0.4f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(tVerts, tSize);
  tmp->position = glm::vec3(-0.20f, 0.4f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(rVerts, rSize);
  tmp->position = glm::vec3(-0.10f, 0.4f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(yVerts, ySize);
  tmp->position = glm::vec3(0.0f, 0.4f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(dVerts, dSize);
  tmp->position = glm::vec3(0.10f, 0.4f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(eVerts, eSize);
  tmp->position = glm::vec3(0.20f, 0.4f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);
  tmp = new MeshComponent(rVerts, rSize);
  tmp->position = glm::vec3(0.30f, 0.4f, 0.0f);
  tmp->SetColor(0.8f, 0.8f, 0.8f);
  text.push_back(tmp);

  //Game Over Text
  tmp = new MeshComponent(gVerts, gSize);
  tmp->position = glm::vec3(-0.15f, 0.2f, 0.0f);
  tmp->SetColor(0.8f, 0.1f, 0.1f);
  gameOverText.push_back(tmp);
  tmp = new MeshComponent(aVerts, aSize);
  tmp->position = glm::vec3(-0.05f, 0.2f, 0.0f);
  tmp->SetColor(0.8f, 0.1f, 0.1f);
  gameOverText.push_back(tmp);
  tmp = new MeshComponent(mVerts, mSize);
  tmp->position = glm::vec3(0.05f, 0.2f, 0.0f);
  tmp->SetColor(0.8f, 0.1f, 0.1f);
  gameOverText.push_back(tmp);
  tmp = new MeshComponent(eVerts, eSize);
  tmp->position = glm::vec3(0.15f, 0.2f, 0.0f);
  tmp->SetColor(0.8f, 0.1f, 0.1f);
  gameOverText.push_back(tmp);
  tmp = new MeshComponent(zeroVerts, zeroSize);
  tmp->position = glm::vec3(-0.15f, 0.0f, 0.0f);
  tmp->SetColor(0.8f, 0.1f, 0.1f);
  gameOverText.push_back(tmp);
  tmp = new MeshComponent(vVerts, vSize);
  tmp->position = glm::vec3(-0.05f, 0.0f, 0.0f);
  tmp->SetColor(0.8f, 0.1f, 0.1f);
  gameOverText.push_back(tmp);
  tmp = new MeshComponent(eVerts, eSize);
  tmp->position = glm::vec3(0.05f, 0.0f, 0.0f);
  tmp->SetColor(0.8f, 0.1f, 0.1f);
  gameOverText.push_back(tmp);
  tmp = new MeshComponent(rVerts, rSize);
  tmp->position = glm::vec3(0.15f, 0.0f, 0.0f);
  tmp->SetColor(0.8f, 0.1f, 0.1f);
  gameOverText.push_back(tmp);

  active = true;
  gameOverActive = false;
  gameOverFade = 0.0f;
  play = false;
  selectorLocations[0] = glm::vec3(0.0f, 0.0f, 0.0f);
  selectorLocations[1] = glm::vec3(0.0f, 0.2f, 0.0f);
  selectorLocations[2] = glm::vec3(0.0f, 0.4f, 0.0f);
  selector = new MeshComponent(selectorBox, 12);
  selector->SetColor(0.1f, 0.7f, 0.1f);
  selectorPos = 1;
  selector->position = selectorLocations[selectorPos];

  keyDown = false;
  
  iComponent = new InputComponent();
  
}

Menu::~Menu() {
  int size = text.size();
  MeshComponent* tmp;
  for (int i = 0; i < size; i++) {
    tmp = text.back();
    delete tmp;
    text.pop_back();
  }
  size = gameOverText.size();
  for (int i = 0; i < size; i++) {
    tmp = gameOverText.back();
    delete tmp;
    gameOverText.pop_back();
  }
  delete selector;
  delete iComponent;
}

void Menu::Update(float deltaTime) {
  
  if (active) {
    bool up, down, select;
    if (glfwJoystickPresent(GLFW_JOYSTICK_1)) {
      int axisCount;
      const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axisCount);
      up = (axes[1] > 0.5f);
      down = (axes[1] < -0.5f);

      int buttonCount;
      const unsigned char* buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
      select = buttons[0];
    }
    else {
      up = iComponent->GetKeyState(GLFW_KEY_W);
      down = iComponent->GetKeyState(GLFW_KEY_S);
      select = iComponent->GetKeyState(GLFW_KEY_SPACE);
    }
    if (select) {
      if (selectorPos == 1) {
        play = true;
      }
      else if (selectorPos == 0) {
        EngineCore::GetEngine()->Quit();  //TODO - Remove this BIG hack
                                          //Object destroys itself then returns?
        return;
      }
    }
    if (up && !keyDown) {
      if (selectorPos < 1) {
        selectorPos++;
      }
      selector->position = selectorLocations[selectorPos];
      keyDown = true;
    }
    else if (down && !keyDown) {
      if (selectorPos > 0) {
        selectorPos--;
      }
      selector->position = selectorLocations[selectorPos];
      keyDown = true;
    }
    else if (!up && !down) {
      keyDown = false;
    }
    for (int i = 0; i < text.size(); i++) {
      text[i]->Draw();
    }
    
    selector->Draw();
  }
  if (gameOverActive) {
    gameOverFade += deltaTime;
    for (int i = 0; i < gameOverText.size(); i++) {
      if (gameOverFade < 1.0f) {
        gameOverText[i]->SetColor(gameOverFade * 8.0f / 10.0f, gameOverFade / 10, gameOverFade / 10);
      }
      else if (gameOverFade > 3.0f) {
        float fade = gameOverFade - 3.0f;
        gameOverText[i]->SetColor(0.8 - (fade * 8.0f / 10.0f), 0.1f - (fade / 10), 0.1f - (fade / 10));
      }
      gameOverText[i]->Draw();
    }
  }
  else {
    gameOverFade = 0.0f;
  }
}