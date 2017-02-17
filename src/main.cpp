
#include "Engine/EngineCore.h"
//#include "Engine/GameObject.h"


int main() {
  EngineCore *core = EngineCore::GetEngine();

  core->Init();
  core->BeginGame();
  core->GameLoop();

  core->Shutdown();
  return 0;
}