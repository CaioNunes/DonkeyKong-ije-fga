#include<scene.hpp>
#include "components/animation.hpp"
#include "components/Sound.hpp"
#include "input.hpp"

using namespace engine;
class WinScene : public Scene{
    public:

        WinScene(std::string name):
            Scene(name){}

        ~WinScene();

    void game_logic();
private:
        bool start;
};
