#include "game.hpp"
#include "gameobject.hpp"
#include "scene.hpp"
#include "components/image.hpp"
#include "components/animation.hpp"
#include "components/animation_controller.hpp"
#include "components/audio.hpp"
#include "sdl2core.hpp"
#include "stage.hpp"
#include "menu.hpp"

using namespace engine;

int main(int, char **){

    //Configurando nome e tamanho
    std::pair<int, int> window_size(800, 600);
    Game::instance.set_properties("Donkey Kong Country",window_size);

    //================================================= MENU =======================================
    MenuScene menu("Menu");
    Game::instance.add_scene(menu);

    GameObject background_menu("background_menu");
    ImageComponent background_menu_image(background_menu,"imageBackground_menu", "assets/sprites/menu.png");

    //Objeto atrelado, ID para audio, caminho, is_music e play_on_start(default é true)
    AudioComponent menu_music(background_menu, "menu_music", "assets/music/dk_menu.mp3", true);

    background_menu.add_component(menu_music);
    background_menu.add_component(background_menu_image);

    menu.add_game_object(background_menu);

    //================================================= STAGE =======================================
    StageScene stage("WaterStage");
    Game::instance.add_scene(stage);

    GameObject background_stage("background_stage");
    ImageComponent background_stage_image(background_stage,"imageBackground_stage", "assets/sprites/background_stage.png");

    AudioComponent stage_music(background_stage, "stage_music", "assets/music/dk_stage.mp3", true);


    background_stage.add_component(stage_music);
    background_stage.add_component(background_stage_image);

    stage.add_game_object(background_stage);

    Game::instance.run();

    return 0;
}
