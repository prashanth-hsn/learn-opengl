#ifndef CAMERA_H
#define CAMERA_H

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Camera {

public:
    Camera() {
        cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
        cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
    }
    void front(float cameraSpeed) {
        cameraPos += cameraSpeed * cameraFront;
    }
    void back(float cameraSpeed) {
        cameraPos -= cameraSpeed * cameraFront;
    }
    void left (float cameraSpeed) {
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
    void right(float cameraSpeed) {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
    glm::mat4 view() {
        return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    }
private:
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
};

#endif // !CAMERA_H

