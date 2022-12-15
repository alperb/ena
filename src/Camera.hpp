#pragma once

#include <vector>
#include <string>
#include <glm/vec4.hpp>

class MainCamera {
public:
    MainCamera(){
        currentScene = nullptr;
    }
    ~MainCamera() {
        for(auto Scene : m_Scenes) {
            delete Scene;
        }
    }

    class Scene {
    public:
        Scene(std::string name, glm::vec4 cameraPosition) : name(name), cameraPosition(cameraPosition) {

        }
        void setLookAt(glm::vec4 position) {
            this->lookAt = position;
        }
        ~Scene() = default;
    private:
        std::string name;
        glm::vec4 cameraPosition;
        glm::vec4 lookAt;
    };

    int addScene(Scene* Scene) {
        m_Scenes.push_back(Scene);
        return m_Scenes.size() - 1;
    }

    int setScene(int index) {
        if(index < 0 || index >= m_Scenes.size()) {
            return -1;
        }

        currentScene = m_Scenes[index];
        return 1;
    }

private:
    Scene* currentScene;
    std::vector<Scene*> m_Scenes;
};