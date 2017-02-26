#include "ScoreDisplay.h"
GLfloat zeroVerts[] = {
  0.03f, -0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f
};
GLfloat oneVerts[] = {
  0.03f, -0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
};
GLfloat twoVerts[] = {
  0.03f, -0.03f, 0.0f, 
  -0.03f, -0.03f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  0.03f, 0.0f, 0.0f,
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
  0.03f, 0.0f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  -0.03f, -0.03f, 0.0f
};
GLfloat threeVerts[] = {
  0.03f, -0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f,
  0.03f, -0.03f, 0.0f,
  0.03f, 0.0f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  0.03f, 0.0f, 0.0f,
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  0.03f, 0.03f, 0.0f
}; 
GLfloat fourVerts[] = {
  0.03f, -0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  0.03f, 0.0f, 0.0f
};
GLfloat fiveVerts[] = {
  -0.03f, -0.03f, 0.0f,
  0.03f, -0.03f, 0.0f,
  0.03f, 0.0f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  0.03f, 0.0f, 0.0f,
  0.03f, -0.03f, 0.0f
};
GLfloat sixVerts[] = {
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f,
  0.03f, -0.03f, 0.0f, 
  0.03f, 0.0f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  -0.03, 0.03f, 0.0f
};
GLfloat sevenVerts[] = {
  -0.03f, 0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
  0.03f, -0.03f, 0.0f,
  0.03f, 0.03f, 0.0f
};
GLfloat eightVerts[] = {
  0.03f, 0.0f, 0.0f,
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  0.03f, 0.0f, 0.0f,
  0.03f, -0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f,
  -0.03f, 0.0f, 0.0f,
};
GLfloat nineVerts[] = {
  0.03f, -0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  0.03f, 0.0f, 0.0f,
};

ScoreDisplay::ScoreDisplay() {
  MeshComponent* tmp = new MeshComponent(zeroVerts, 12);
  tmp->position = glm::vec3(0.2f, -0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  text.push_back(tmp);
  tmp = new MeshComponent(zeroVerts, 12);
  tmp->position = glm::vec3(0.1f, -0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  text.push_back(tmp);
  tmp = new MeshComponent(zeroVerts, 12);
  tmp->position = glm::vec3(0.0f, -0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  text.push_back(tmp);
  tmp = new MeshComponent(zeroVerts, 12);
  tmp->position = glm::vec3(-0.1f, -0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  text.push_back(tmp);
  score = 0;
  scoreTimer = 0.0f;
  countScore = true;
}

ScoreDisplay::~ScoreDisplay() {
  MeshComponent* tmp;
  while (!text.empty()) {
    tmp = text.back();
    text.pop_back();
    delete tmp;
  }
}

void ScoreDisplay::Update(float deltaTime) {
  scoreTimer += deltaTime;
  
  if (scoreTimer > 1.0f && countScore) {
    score++;
    scoreTimer = 0.0f;
  }
  int tmp = score;
  for (int i = 0; i < 4; i++) {
    delete text[i];
    switch (tmp % 10) {
    case 0:
      text[i] = new MeshComponent(zeroVerts, 12);
      text[i]->position = glm::vec3(0.2f - (0.1f)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    case 1:
      text[i] = new MeshComponent(oneVerts, 6);
      text[i]->position = glm::vec3(0.2f - (0.1)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    case 2:
      text[i] = new MeshComponent(twoVerts, 30);
      text[i]->position = glm::vec3(0.2f - (0.1f)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    case 3:
      text[i] = new MeshComponent(threeVerts, 27);
      text[i]->position = glm::vec3(0.2f - (0.1f)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    case 4:
      text[i] = new MeshComponent(fourVerts, 12);
      text[i]->position = glm::vec3(0.2f - (0.1f)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    case 5:
      text[i] = new MeshComponent(fiveVerts, 30);
      text[i]->position = glm::vec3(0.2f - (0.1f)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    case 6:
      text[i] = new MeshComponent(sixVerts, 21);
      text[i]->position = glm::vec3(0.2f - (0.1f)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    case 7:
      text[i] = new MeshComponent(sevenVerts, 12);
      text[i]->position = glm::vec3(0.2f - (0.1f)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    case 8:
      text[i] = new MeshComponent(eightVerts, 24);
      text[i]->position = glm::vec3(0.2f - (0.1f)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    case 9:
      text[i] = new MeshComponent(nineVerts, 15);
      text[i]->position = glm::vec3(0.2f - (0.1f)*i, -0.7f, 0.0f);
      text[i]->SetColor(0.2f, 0.8f, 0.1f);
      break;
    }
    tmp /= 10;
  }
  for (int i = 0; i < text.size(); i++) {
    text[i]->Draw();
  }
}

void ScoreDisplay::ResetScore() {
  score = 0;
}
