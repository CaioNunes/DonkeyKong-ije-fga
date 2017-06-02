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
#include "player_controller.hpp"

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

    GameObject music_background("music_background");

    GameObject background_stage("background_stage");
    ImageComponent background_stage_image(background_stage,"imageBackground_stage", "assets/sprites/background_stage.png");

    AudioComponent stage_music(music_background, "stage_music", "assets/music/dk_stage.mp3", true);

    music_background.add_component(stage_music);
    background_stage.add_component(background_stage_image);

    GameObject maps("maps");
    ImageComponent maps_stage(maps, "maps_stage", "assets/sprites/maps_resized.png");

    maps.main_positionY = -2220;

    maps.add_component(maps_stage);

    GameObject donkey_player("donkey_player");
    AnimationControllerComponent donkeyCtrl(donkey_player, "animationControllerDonkey");

    PlayerController player_controller(donkey_player, "donkey_player");

    Animation donkey_swim(donkey_player, "donkey_swim", "assets/sprites/donkey_resized.png", 1790/15 , 90, 15);
    donkey_swim.setDelay(100);

    donkeyCtrl.add_animation("donkey_swim", donkey_swim);

    donkey_player.add_component(donkey_swim);
    donkey_player.add_component(donkeyCtrl);
    donkey_player.add_component(player_controller);

    donkey_player.main_positionY = 0;

    stage.add_game_object(music_background);
    stage.add_game_object(maps);
    stage.add_game_object(donkey_player);
    stage.add_game_object(background_stage);

    Game::instance.run();

    return 0;
}
