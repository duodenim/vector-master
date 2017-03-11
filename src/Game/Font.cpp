#include "Font.h"
GLfloat zeroVerts[] = {
  -0.03f, 0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f,
  0.03f, -0.03f, 0.0f,
  0.03f, 0.03f, 0.0f
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
GLfloat hVerts[] = {
  -0.03f, -0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  0.03f, 0.0f, 0.0f,
  0.03f, 0.03f, 0.0f,
  0.03f ,-0.03f, 0.0f,
  0.03f, 0.0f, 0.0f,
  -0.03f, 0.0f, 0.0f
};
GLfloat dashVerts[] = {
  -0.03f, 0.0f, 0.0f,
  0.03f, 0.0f, 0.0f
};
GLfloat aVerts[] = {
  -0.03f, -0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
  0.03f, -0.03f, 0.0f,
  0.03f, 0.0f, 0.0f,
  -0.03f, 0.0f, 0.0f
};
int aSize = 18;
GLfloat bVerts[] = {
-0.03f, -0.03f, 0.0f,
-0.03f, 0.03f, 0.0f,
0.02f, 0.03f, 0.0f,
0.03f, 0.02f, 0.0f,
0.03f, 0.0f, 0.0f,
-0.03f, 0.0f, 0.0f,
0.03f, 0.0f, 0.0f,
0.03f, -0.02f, 0.0f,
0.02f, -0.03f, 0.0f,
};
int bSize = 27;
GLfloat cVerts[] = {
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f,
  0.03f, -0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f
};
GLfloat dVerts[] = {
  -0.03f, -0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  0.02f, 0.03f, 0.0f,
  0.03f, 0.02f, 0.0f,
  0.03f, -0.02f, 0.0f,
  0.02f, -0.03f, 0.0f
};
int dSize = 18;
GLfloat eVerts[] = {
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  0.03f, 0.0f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  -0.03f, -0.03f, 0.0f,
  0.03f, -0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f, 
  -0.03f, 0.03f, 0.0f
};
int eSize = 27;
GLfloat fVerts[] = {
-0.03f, -0.03f, 0.0f,
-0.03f, 0.0f, 0.0f,
-0.0f, 0.0f, 0.0f,
-0.03f, 0.0f, 0.0f,
-0.03f, 0.03f, 0.0f,
0.015f, 0.03f, 0.0f,
-0.03f, 0.03f, 0.0f,
};
int fSize = 21;
GLfloat iVerts[] = {
  0.03f, 0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  0.0f, 0.03f, 0.0f,
  0.0f, -0.03f, 0.0f,
  0.03f, -0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f,
  0.0f, -0.03f, 0.0f,
  0.0f, 0.03f, 0.0f
};
int iSize = 24;
GLfloat lVerts[] = {
  -0.03f, 0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f,
  0.03f, -0.03f, 0.0f,
  -0.03f, -0.03f, 0.0f
};
int lSize = 12;
GLfloat pVerts[] = {
  -0.03f, -0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
  0.03f, 0.0f, 0.0f,
  -0.03f, 0.0f, 0.0f
};
int pSize = 15;
GLfloat qVerts[] = {
-0.03f, -0.03f, 0.0f,
-0.03f, 0.03f, 0.0f,
0.03f, 0.03f, 0.0f,
0.03f, -0.00f, 0.0f,
0.015f, -0.015f, 0.0f,
0.03f, -0.03f, 0.0f,
0.015f, -0.015f, 0.0f,
0.00f, -0.03f, 0.0f,
};
int qSize = 24;
GLfloat rVerts[] = {
  -0.03f, -0.03f, 0.0f,
  -0.03f, 0.03f, 0.0f,
  0.03f, 0.03f, 0.0f,
  0.03f, 0.0f, 0.0f,
  -0.03f, 0.0f, 0.0f,
  0.03f, -0.03f, 0.0f,
  -0.03f, 0.0f, 0.0f
};
int rSize = 21;
GLfloat sVerts[] = {
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
int sSize = 30;
GLfloat tVerts[] = {
  -0.03f, 0.03f, 0.0f,
  0.0f, 0.03f, 0.0f, 
  0.0f, -0.03f, 0.0f, 
  0.0f, 0.03f, 0.0f,
  0.03f, 0.03f, 0.0f
};
int tSize = 15;
GLfloat uVerts[] = {
-0.03f, 0.03f, 0.0f,
-0.03f, -0.03f, 0.0f,
0.03f, -0.03f, 0.0f,
0.03f, 0.03f, 0.0f,
0.03f, -0.03f, 0.0f,
-0.03f, -0.03f, 0.0f
};
int uSize = 18;
GLfloat xVerts[] = {
-0.02f, 0.03f, 0.0f,
-0.02f, 0.02f, 0.0f,
0.02f, -0.02f, 0.0f,
0.02f, -0.03f, 0.0f,
0.02f, -0.02f, 0.0f,
0.0f, 0.0f, 0.0f,
-0.02f, -0.03f, 0.0f,
0.02f, 0.03f, 0.0f,
0.0f, 0.0f, 0.0f,
-0.02f, 0.02f, 0.0f
};
int xSize = 30;
GLfloat yVerts[] = {
  -0.03f, 0.03f, 0.0f, 
  -0.03f, 0.01f, 0.0f,
  0.03f, 0.01f, 0.0f,
  0.03f, 0.03f, 0.0f,
  0.03f, 0.01f, 0.0f,
  0.0f, 0.01f, 0.0f,
  0.0f, -0.03f, 0.0f,
  0.0f, 0.01f, 0.0f,
  -0.03f, 0.01f, 0.0f
};
int ySize = 27;