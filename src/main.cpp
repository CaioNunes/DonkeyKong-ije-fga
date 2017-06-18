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
    std::pair<int, int> window_size(640, 480);
    Game::instance.set_properties("Donkey Kong Country",window_size);

    // //================================================= MENU =======================================
    // MenuScene menu("Menu");
    // Game::instance.add_scene(menu);
    //
    // GameObject background_menu("background_menu");
    // ImageComponent background_menu_image(background_menu,"imageBackground_menu", "assets/sprites/menu.png",1);
    //
    // //Objeto atrelado, ID para audio, caminho, is_music e play_on_start(default é true)
    // AudioComponent menu_music(background_menu, "menu_music", "assets/music/dk_menu.mp3", true);
    //
    // background_menu.add_component(menu_music);
    // background_menu.add_component(background_menu_image);
    //
    // menu.add_game_object(background_menu);

    //================================================= STAGE =======================================
    StageScene stage("WaterStage");
    Game::instance.add_scene(stage);

    GameObject music_background("music_background", 4);

    GameObject background_stage("background_stage", 1);
    ImageComponent background_stage_image(background_stage,"imageBackground_stage", "assets/sprites/background_stage.png", 3);

    AudioComponent stage_music(music_background, "stage_music", "assets/music/dk_solo.mp3", true);

    music_background.add_component(stage_music);
    background_stage.add_component(background_stage_image);

    GameObject maps("maps", 2);
    // ImageComponent maps_stage(maps, "maps_stage", "assets/sprites/maps_resized.png",2);
    ImageComponent maps_stage(maps, "maps_stage", "assets/sprites/solo_stage_resized.png",2);

    maps.main_positionY = 0;

    maps_stage.set_back_rect(0, 0, 640,480);
    // maps_stage.set_back_rect(0, 0, 840,640);

    maps.add_component(maps_stage);

    GameObject donkey_player("donkey_player", 3);
    AnimationControllerComponent donkeyCtrl(donkey_player, "animationControllerDonkey");

    PlayerController player_controller(donkey_player, "donkey_player", &maps_stage);

    Animation donkey_swim(donkey_player, "donkey_swim", "assets/sprites/donkey_idle.png", 1, 2499/51 , 54, 51);
    donkey_swim.setDelay(100);

    donkeyCtrl.add_animation("donkey_swim", donkey_swim);

    donkey_player.add_component(donkey_swim);
    donkey_player.add_component(donkeyCtrl);
    donkey_player.add_component(player_controller);

    donkey_player.main_positionX = 150;
    donkey_player.main_positionY = 100;

    stage.add_game_object(&music_background);
    stage.add_game_object(&maps);
    stage.add_game_object(&donkey_player);
    stage.add_game_object(&background_stage);

    stage.print_scene_objects();
    Game::instance.run();

    return 0;
}
