#include "game.hpp"
#include "gameobject.hpp"
#include "scene.hpp"
#include "components/image.hpp"
#include "components/animation.hpp"
#include "components/animation_controller.hpp"
#include "components/music.hpp"
#include "sdl2core.hpp"
#include "stage.hpp"

using namespace engine;

int main(int, char **){

    //Configurando nome e tamanho
    std::pair<int, int> window_size(800, 600);
    Game::instance.set_properties("Donkey Kong Country",window_size);

    //================================================= MENU =======================================
    StageScene stage("Water Stage");
    Game::instance.add_scene(stage);

    GameObject background("background");
    ImageComponent backgroundImage(background,"imageBackground", "assets/sprites/background.png");

    Music stage_music(background, "menu_musicBackground", "assets/music/dk_stage.mp3");


    background.add_component(backgroundImage);
    background.add_component(stage_music);

    //adiciona game objects ao menu
    stage.add_game_object(background);

    Game::instance.run();

    return 0;
}
