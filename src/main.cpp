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
#include "plataform_controller.hpp"

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
    maps_stage.set_back_rect(0, 250, 640,480);
    // maps_stage.set_back_rect(0, 0, 840,640);

    GameObject colisor1("colisor1", 3, true, "ground");
    colisor1.main_positionX = 150;
    colisor1.main_positionY = 250;
    // colisor1.main_positionY = 200;
    ImageComponent colisorIm(colisor1, "colisor_im", "assets/sprites/plataform.png", 2);
    PlataformController pc(colisor1, "colisor1");

    colisor1.add_component(colisorIm);
    colisor1.add_component(pc);
    maps.add_component(maps_stage);

    GameObject donkey_player("donkey_player", 3);
    donkey_player.main_positionX = 150;
    donkey_player.main_positionY = 200;

    AnimationControllerComponent donkeyCtrl(donkey_player, "animationControllerDonkey");

    PlayerController player_controller(donkey_player, "donkey_player", &maps_stage);

    // =============== ANIMATIONS =========================
    Animation donkey_walking(donkey_player, "donkey_walking", "assets/sprites/walking.png", 1, 980/20, 44, 20);
    donkey_walking.setDelay(60);

    donkeyCtrl.add_animation("donkey_walking", donkey_walking);

    Animation donkey_idle(donkey_player, "donkey_idle", "assets/sprites/donkey_idle.png", 1, 2499/51 , 54, 51);
    donkey_idle.setDelay(100);

    donkeyCtrl.add_animation("donkey_idle", donkey_idle);

    donkey_player.add_component(donkey_walking);
    donkey_player.add_component(donkey_idle);
    donkey_player.add_component(donkeyCtrl);
    donkey_player.add_component(player_controller);

    stage.add_game_object(&music_background);
    stage.add_game_object(&maps);
    stage.add_game_object(&donkey_player);
    stage.add_game_object(&background_stage);
    stage.add_game_object(&colisor1);

    stage.print_scene_objects();
    Game::instance.run();

    return 0;
}
