#include<scene.hpp>
#include "components/animation.hpp"
#include "components/Sound.hpp"

using namespace engine;
class LoseScene : public Scene{
    public:

        LoseScene(std::string name):
            Scene(name){}

        ~LoseScene();

    void game_logic();
};
