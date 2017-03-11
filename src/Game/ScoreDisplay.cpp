#include "ScoreDisplay.h"
#include "Font.h"
ScoreDisplay::ScoreDisplay() {
  //Load the font table
  MeshComponent* tmp = new MeshComponent(zeroVerts, 12);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  font.push_back(tmp);
  tmp = new MeshComponent(oneVerts, 6);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  font.push_back(tmp);
  tmp = new MeshComponent(twoVerts, 30);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  font.push_back(tmp);
  tmp = new MeshComponent(threeVerts, 27);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  font.push_back(tmp);
  tmp = new MeshComponent(fourVerts, 12);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  font.push_back(tmp);
  tmp = new MeshComponent(fiveVerts, 30);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  font.push_back(tmp);
  tmp = new MeshComponent(sixVerts, 21);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  font.push_back(tmp);
  tmp = new MeshComponent(sevenVerts, 12);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  font.push_back(tmp);
  tmp = new MeshComponent(eightVerts, 24);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  font.push_back(tmp);
  tmp = new MeshComponent(nineVerts, 15);
  tmp->SetColor(0.2f, 0.8f, 0.1f);

  font.push_back(tmp);

  //Setup hi-score display
  tmp = new MeshComponent(hVerts, 24);
  tmp->position = glm::vec3(-0.35f, 0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(hVerts, 24);
  tmp->position = glm::vec3(-0.25f, 0.7f, 0.0f);
  tmp->rotation = 90.0f;
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(dashVerts, 6);
  tmp->position = glm::vec3(-0.15f, 0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(fiveVerts, 30);
  tmp->position = glm::vec3(-0.05f, 0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(cVerts, 18);
  tmp->position = glm::vec3(0.05f, 0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(zeroVerts, 12);
  tmp->position = glm::vec3(0.15f, 0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(rVerts, 21);
  tmp->position = glm::vec3(0.25f, 0.7f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(threeVerts, 27);
  tmp->position = glm::vec3(0.35f, 0.7f, 0.0f);
  tmp->rotation = 180.0f;
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);

  tmp = new MeshComponent(sVerts, sSize);
  tmp->position = glm::vec3(-0.20f, -0.6f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(cVerts, cSize);
  tmp->position = glm::vec3(-0.10f, -0.6f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(zeroVerts, zeroSize);
  tmp->position = glm::vec3(0.0f, -0.6f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(rVerts, rSize);
  tmp->position = glm::vec3(0.10f, -0.6f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  tmp = new MeshComponent(eVerts, eSize);
  tmp->position = glm::vec3(0.20f, -0.6f, 0.0f);
  tmp->SetColor(0.2f, 0.8f, 0.1f);
  hiScoreDisplay.push_back(tmp);
  score = 0;
  highScore = 0;
  scoreTimer = 0.0f;
  countScore = true;
}

ScoreDisplay::~ScoreDisplay() {
  MeshComponent* tmp;
  while (!font.empty()) {
    tmp = font.back();
    font.pop_back();
    delete tmp;
  }
  while (!hiScoreDisplay.empty()) {
    tmp = hiScoreDisplay.back();
    hiScoreDisplay.pop_back();
    delete tmp;
  }
}

void ScoreDisplay::Update(float deltaTime) {
  scoreTimer += deltaTime;
  
  if (scoreTimer > 1.0f && countScore) {
    score++;
    scoreTimer = 0.0f;
    if (score > highScore) {
      highScore = score;
    }
  }

  int tmp = score;

  //Use temporary character as current character to draw from font
  MeshComponent* digit = font[0];
  for (int i = 0; i < 4; i++) {
    digit = font[tmp % 10];
    digit->position = glm::vec3(0.15f - (0.1f)*i, -0.7f, 0.0f);   
    tmp /= 10;
    digit->Draw();
  }
  for (int i = 0; i < hiScoreDisplay.size(); i++) {
    hiScoreDisplay[i]->Draw();
  }
  tmp = highScore;
  for (int i = 0; i < 4; i++) {
    digit = font[tmp % 10];
    digit->position = glm::vec3(0.15f - (0.1f)*i, 0.6f, 0.0f);
    tmp /= 10;
    digit->Draw();
  }
    
  
}

void ScoreDisplay::ResetScore() {
  score = 0;
}
