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
    // std::pair<int, int> window_size(640, 480);
    std::pair<int, int> window_size(1280, 768);
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

    //================================================= SOLO STAGE =======================================
    StageScene stage("WaterStage");
    Game::instance.add_scene(stage);

    GameObject music_background("music_background", 4);

    GameObject background_stage("background_stage", 1);
    ImageComponent background_stage_image(background_stage,"imageBackground_stage", "assets/sprites/background_stage.png", 3);

    AudioComponent stage_music(music_background, "stage_music", "assets/music/dk_solo.mp3", true);

    music_background.add_component(stage_music);
    background_stage.add_component(background_stage_image);

    GameObject maps("maps", 2);
    // ImageComponent maps_stage(maps, "maps_stage", "assets/sprites/solo_stage_resized.png",2);
    ImageComponent maps_stage(maps, "maps_stage", "assets/sprites/solo_stage_new_2.png",2);

    maps.main_positionY = 0;
    // maps_stage.set_back_rect(0, 250, 640,480);
    maps_stage.set_back_rect(0, 250, 1280,768);
    maps.add_component(maps_stage);

    // ===================== COLISORES =========================

    GameObject colisor1("colisor1", 3, true, "ground");
    colisor1.main_positionX = 150;
    colisor1.main_positionY = 385;

    ImageComponent colisorIm1(colisor1, "colisor_im1", "assets/sprites/retangulo_4.png", 2);
    PlataformController pc1(colisor1, "colisor1");

    colisor1.add_component(colisorIm1);
    colisor1.add_component(pc1);

    GameObject colisor2("colisor2", 3, true, "ground");
    // colisor2.main_positionX = 1557;
    colisor2.main_positionX = 1550;
    colisor2.main_positionY = 385;

    ImageComponent colisorIm2(colisor2, "colisor_im2", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc2(colisor2, "colisor2");

    colisor2.add_component(colisorIm2);
    colisor2.add_component(pc2);

    GameObject colisor3("colisor3", 3, true, "ground");
    // colisor3.main_positionX = 1557;
    colisor3.main_positionX = 1640;
    colisor3.main_positionY = 385;

    ImageComponent colisorIm3(colisor3, "colisor_im3", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc3(colisor3, "colisor3");

    colisor3.add_component(colisorIm3);
    colisor3.add_component(pc3);

    GameObject colisor4("colisor4", 3, true, "ground");
    // colisor3.main_positionX = 1557;
    colisor4.main_positionX = 1360;
    colisor4.main_positionY = 405;

    ImageComponent colisorIm4(colisor4, "colisor_im4", "assets/sprites/retangulo_4.png", 2);
    PlataformController pc4(colisor4, "colisor4");

    colisor4.add_component(colisorIm4);
    colisor4.add_component(pc4);

    GameObject colisor5("colisor5", 3, true, "ground");
    // colisor3.main_positionX = 1557;
    colisor5.main_positionX = 2750;
    colisor5.main_positionY = 425;

    ImageComponent colisorIm5(colisor5, "colisor_im5", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc5(colisor5, "colisor5");

    colisor5.add_component(colisorIm5);
    colisor5.add_component(pc5);

    GameObject colisor6("colisor6", 3, true, "ground");
    // colisor3.main_positionX = 1557;
    colisor6.main_positionX = 3000;
    colisor6.main_positionY = 425;

    ImageComponent colisorIm6(colisor6, "colisor_im6", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc6(colisor6, "colisor6");

    colisor6.add_component(colisorIm6);
    colisor6.add_component(pc6);

    GameObject colisor7("colisor7", 3, true, "ground");
    // colisor3.main_positionX = 1557;
    colisor7.main_positionX = 3100;
    colisor7.main_positionY = 425;

    ImageComponent colisorIm7(colisor7, "colisor_im7", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc7(colisor7, "colisor7");

    colisor7.add_component(colisorIm7);
    colisor7.add_component(pc7);

    GameObject colisor8("colisor8", 3, true, "ground");
    // colisor3.main_positionX = 1558;
    colisor8.main_positionX = 3500;
    colisor8.main_positionY = 425;

    ImageComponent colisorIm8(colisor8, "colisor_im8", "assets/sprites/retangulo_1.png", 2);
    PlataformController pc8(colisor8, "colisor8");

    colisor8.add_component(colisorIm8);
    colisor8.add_component(pc8);

    GameObject colisor9("colisor9", 3, true, "ground");
    // colisor3.main_positionX = 1559;
    colisor9.main_positionX = 4300;
    colisor9.main_positionY = 600;

    ImageComponent colisorIm9(colisor9, "colisor_im9", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc9(colisor9, "colisor9");

    colisor9.add_component(colisorIm9);
    colisor9.add_component(pc9);

    GameObject colisor10("colisor10", 3, true, "ground");
    // colisor3.main_positionX = 15510;
    colisor10.main_positionX = 4635;
    colisor10.main_positionY = 650;

    ImageComponent colisorIm10(colisor10, "colisor_im10", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc10(colisor10, "colisor10");

    colisor10.add_component(colisorIm10);
    colisor10.add_component(pc10);

    GameObject colisor11("colisor11", 3, true, "ground");
    // colisor3.main_positionX = 15511;
    colisor11.main_positionX = 4800;
    colisor11.main_positionY = 500;

    ImageComponent colisorIm11(colisor11, "colisor_im11", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc11(colisor11, "colisor11");

    colisor11.add_component(colisorIm11);
    colisor11.add_component(pc11);

    GameObject colisor12("colisor12", 3, true, "ground");
    // colisor3.main_positionX = 15512;
    colisor12.main_positionX = 5150;
    colisor12.main_positionY = 520;

    ImageComponent colisorIm12(colisor12, "colisor_im12", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc12(colisor12, "colisor12");

    colisor12.add_component(colisorIm12);
    colisor12.add_component(pc12);

    GameObject colisor13("colisor13", 3, true, "ground");
    // colisor3.main_positionX = 15513;
    colisor13.main_positionX = 5310;
    colisor13.main_positionY = 340;

    ImageComponent colisorIm13(colisor13, "colisor_im13", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc13(colisor13, "colisor13");

    colisor13.add_component(colisorIm13);
    colisor13.add_component(pc13);

    GameObject colisor14("colisor14", 3, true, "ground");
    // colisor3.main_positionX = 15514;
    colisor14.main_positionX = 5580;
    colisor14.main_positionY = 190;

    ImageComponent colisorIm14(colisor14, "colisor_im14", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc14(colisor14, "colisor14");

    colisor14.add_component(colisorIm14);
    colisor14.add_component(pc14);

    GameObject colisor15("colisor15", 3, true, "ground");
    // colisor3.main_positionX = 15515;
    colisor15.main_positionX = 5860;
    colisor15.main_positionY = 120;

    ImageComponent colisorIm15(colisor15, "colisor_im15", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc15(colisor15, "colisor15");

    colisor15.add_component(colisorIm15);
    colisor15.add_component(pc15);

    GameObject colisor16("colisor16", 3, true, "ground");
    // colisor3.main_positionX = 16516;
    colisor16.main_positionX = 5960;
    colisor16.main_positionY = 120;

    ImageComponent colisorIm16(colisor16, "colisor_im16", "assets/sprites/retangulo_29.png", 2);
    PlataformController pc16(colisor16, "colisor16");

    colisor16.add_component(colisorIm16);
    colisor16.add_component(pc16);

    GameObject colisor17("colisor17", 3, true, "ground");
    // colisor3.main_positionX = 17517;
    colisor17.main_positionX = 6240;
    colisor17.main_positionY = 660;

    ImageComponent colisorIm17(colisor17, "colisor_im17", "assets/sprites/retangulo_29.png", 2);
    PlataformController pc17(colisor17, "colisor17");

    colisor17.add_component(colisorIm17);
    colisor17.add_component(pc17);

    GameObject colisor18("colisor18", 3, true, "ground");
    // colisor3.main_positionX = 18518;
    colisor18.main_positionX = 6450;
    colisor18.main_positionY = 520;

    ImageComponent colisorIm18(colisor18, "colisor_im18", "assets/sprites/retangulo_22.png", 2);
    PlataformController pc18(colisor18, "colisor18");

    colisor18.add_component(colisorIm18);
    colisor18.add_component(pc18);

    GameObject colisor19("colisor19", 3, true, "ground");
    // colisor3.main_positionX = 19519;
    colisor19.main_positionX = 6550;
    colisor19.main_positionY = 600;

    ImageComponent colisorIm19(colisor19, "colisor_im19", "assets/sprites/retangulo_30.png", 2);
    PlataformController pc19(colisor19, "colisor19");

    colisor19.add_component(colisorIm19);
    colisor19.add_component(pc19);


    // ==================== PLAYER ===========================
    GameObject donkey_player("donkey_player", 3);
    donkey_player.main_positionX = 150;
    donkey_player.main_positionY = 200;

    AnimationControllerComponent donkeyCtrl(donkey_player, "animationControllerDonkey");

    PlayerController player_controller(donkey_player, "donkey_player", &maps_stage);

    // Animation donkey_walking(donkey_player, "donkey_walking", "assets/sprites/walking.png", 1, 980/20, 44, 20);
    Animation donkey_walking(donkey_player, "donkey_walking", "assets/sprites/walking_resized.png", 1, 2040/20, 92, 20);
    donkey_walking.setDelay(60);

    donkeyCtrl.add_animation("donkey_walking", donkey_walking);

    Animation donkey_idle(donkey_player, "donkey_idle", "assets/sprites/donkey_idle.png", 1, 2499/51 , 54, 51);
    donkey_idle.setDelay(100);

    donkeyCtrl.add_animation("donkey_idle", donkey_idle);

    donkey_player.add_component(donkey_walking);
    donkey_player.add_component(donkey_idle);
    donkey_player.add_component(donkeyCtrl);
    donkey_player.add_component(player_controller);

    // stage.add_game_object(&music_background);
    stage.add_game_object(&maps);
    stage.add_game_object(&donkey_player);
    stage.add_game_object(&background_stage);
    stage.add_game_object(&colisor1);
    stage.add_game_object(&colisor2);
    stage.add_game_object(&colisor3);
    stage.add_game_object(&colisor4);
    stage.add_game_object(&colisor5);
    stage.add_game_object(&colisor6);
    stage.add_game_object(&colisor7);
    stage.add_game_object(&colisor8);
    stage.add_game_object(&colisor9);
    stage.add_game_object(&colisor10);
    stage.add_game_object(&colisor11);
    stage.add_game_object(&colisor12);
    stage.add_game_object(&colisor13);
    stage.add_game_object(&colisor14);
    stage.add_game_object(&colisor15);
    stage.add_game_object(&colisor16);
    stage.add_game_object(&colisor17);
    stage.add_game_object(&colisor18);
    stage.add_game_object(&colisor19);

// ========================================= WATER STAGE =================================
    // StageScene stage("WaterStage");
    // Game::instance.add_scene(stage);
    //
    // GameObject music_background("music_background", 4);
    //
    // GameObject background_stage("background_stage", 1);
    // ImageComponent background_stage_image(background_stage,"imageBackground_stage", "assets/sprites/background_stage.png", 3);
    //
    // AudioComponent stage_music(music_background, "stage_music", "assets/music/dk_stage.mp3", true);
    //
    // music_background.add_component(stage_music);
    // background_stage.add_component(background_stage_image);
    //
    // GameObject maps("maps", 2);
    // ImageComponent maps_stage(maps, "maps_stage", "assets/sprites/maps_resized.png",2);
    // // maps.main_positionY = -2200;
    // maps_stage.set_back_rect(0, 2200, 1280,768);
    // maps.add_component(maps_stage);
    //
    // // ==================== PLAYER ===========================
    // GameObject donkey_player("donkey_player", 3);
    // donkey_player.main_positionX = 150;
    // donkey_player.main_positionY = 200;
    //
    // AnimationControllerComponent donkeyCtrl(donkey_player, "animationControllerDonkey");
    //
    // PlayerController player_controller(donkey_player, "donkey_player", &maps_stage);
    //
    // Animation donkey_swimming(donkey_player, "donkey_walking", "assets/sprites/donkey.png", 1, 2790/15, 141, 15);
    // donkey_swimming.setDelay(100);
    //
    // donkeyCtrl.add_animation("donkey_swimming", donkey_swimming);
    //
    // // Animation donkey_idle(donkey_player, "donkey_idle", "assets/sprites/donkey_idle.png", 1, 2499/51 , 54, 51);
    // // donkey_idle.setDelay(100);
    //
    // // donkeyCtrl.add_animation("donkey_idle", donkey_idle);
    //
    // donkey_player.add_component(donkey_swimming);
    // // donkey_player.add_component(donkey_idle);
    // donkey_player.add_component(donkeyCtrl);
    // donkey_player.add_component(player_controller);
    //
    // stage.add_game_object(&music_background);
    // stage.add_game_object(&maps);
    // stage.add_game_object(&donkey_player);
    // stage.add_game_object(&background_stage);


    stage.print_scene_objects();
    Game::instance.run();

    return 0;
}
