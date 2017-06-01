#include<scene.hpp>
#include "components/animation.hpp"
#include "components/Sound.hpp"
#include "input.hpp"

using namespace engine;
class MenuScene : public Scene{
    public:

        MenuScene(std::string name):
            Scene(name){}

        ~MenuScene();

    void game_logic();

};
