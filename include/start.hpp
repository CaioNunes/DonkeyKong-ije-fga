#include<scene.hpp>
#include "components/animation.hpp"
#include "components/Sound.hpp"
#include "input.hpp"

using namespace engine;
class StartScene : public Scene{
    public:

        StartScene(std::string name):
            Scene(name){}

        ~StartScene();

    void game_logic();
private:
        bool start;
};
