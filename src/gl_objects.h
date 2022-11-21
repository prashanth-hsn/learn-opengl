#ifndef GL_OBJECTS_H
#define GL_OBJECTS_H

class Shader;
class Camera;

bool setUpTriangle (Shader &ourShader);
void DrawTriangle(Shader &ourShader, Camera& camera);
void deleteTriangle();

#endif // GL_OBJECTS_H
