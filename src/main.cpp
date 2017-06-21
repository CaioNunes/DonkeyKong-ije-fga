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
#include "alligator_controller.hpp"
#include "lose.hpp"
#include "start.hpp"
#include "win.hpp"

using namespace engine;

int main(int, char **){

    std::pair<int, int> window_size(1280, 768);
    Game::instance.set_properties("Donkey Kong Country",window_size);

    //================================================= MENU =======================================
    MenuScene menu("Menu");
    Game::instance.add_scene(menu);

    GameObject background_menu("background_menu", 1);
    ImageComponent background_menu_image(background_menu,"imageBackground_menu", "assets/sprites/menu.png",1);

    AudioComponent menu_music(background_menu, "menu_music", "assets/music/dk_menu.mp3", true);

    background_menu.add_component(menu_music);
    background_menu.add_component(background_menu_image);

    menu.add_game_object(&background_menu);

    // =========================== LOSE SCREEN ============================
    StartScene start("start");
    Game::instance.add_scene(start);

    GameObject background_start("background_start", 1);

    ImageComponent background_start_image(background_start,"imageBackground_start", "assets/sprites/start.png", 3);

    background_start.add_component(background_start_image);

    start.add_game_object(&background_start);

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
    ImageComponent maps_stage(maps, "maps_stage", "assets/sprites/solo.png",2);

    maps.main_positionY = 0;
    maps_stage.set_back_rect(0, 250, 1280,768);
    maps.add_component(maps_stage);

    // ==================== PLAYER ===========================
    GameObject donkey_player("donkey_player", 3, true, "player");

    AnimationControllerComponent donkeyCtrl(donkey_player, "animationControllerDonkey");

    Animation donkey_walking(donkey_player, "donkey_walking", "assets/sprites/run.png", 1, 2600/20, 93, 20);
    donkey_walking.setDelay(60);

    donkeyCtrl.add_animation("donkey_walking", donkey_walking);

    Animation donkey_idle(donkey_player, "donkey_idle", "assets/sprites/donkey_idle.png", 1, 3825/51 , 83, 51);
    donkey_idle.setDelay(100);

    donkeyCtrl.add_animation("donkey_idle", donkey_idle);

    Animation donkey_die(donkey_player, "donkey_die", "assets/sprites/die_resized.png", 1, 2019/18 , 108, 18);
    donkey_die.setDelay(150);

    donkeyCtrl.add_animation("donkey_die", donkey_die);

    PlayerController player_controller(donkey_player, "donkey_player", &maps_stage, &donkeyCtrl);

    donkey_player.add_component(donkey_idle);
    donkey_player.add_component(donkey_walking);
    donkey_player.add_component(donkey_die);
    donkey_player.add_component(donkeyCtrl);
    donkey_player.add_component(player_controller);

    // ===================== MONSTROS  =========================
    GameObject head1("head1", 3, true, "mob_head");
    head1.main_positionX = 300;
    head1.main_positionY = 320;

    ImageComponent head1Im1(head1, "head1_im1", "assets/sprites/stairs.png", 2);

    head1.add_component(head1Im1);

    GameObject alligator1("alligator1", 3, true, "mob");
    alligator1.main_positionX = 800;

    AnimationControllerComponent alligator1Ctrl(alligator1, "animationControllerJacare1");

    Animation alligator1_walking(alligator1, "alligator1_walking", "assets/sprites/andar_mob.png", 1, 1000/8, 100, 8);
    alligator1_walking.setDelay(100);

    alligator1Ctrl.add_animation("alligator1_walking", alligator1_walking);

    AlligatorController alligator1_controller(alligator1, &head1, "alligator1", &maps_stage, &alligator1Ctrl);
    PlataformController alligator1_fix(alligator1, &player_controller, "alligator1");

    alligator1.add_component(alligator1_fix);
    alligator1.add_component(alligator1_walking);
    alligator1.add_component(alligator1Ctrl);
    alligator1.add_component(alligator1_controller);


    // ===================== COLISORES =========================
    GameObject colisor1("colisor1", 3, true, "ground");
    colisor1.main_positionX = 150;
    colisor1.main_positionY = 385;

    ImageComponent colisorIm1(colisor1, "colisor_im1", "assets/sprites/retangulo_4.png", 2);
    PlataformController pc1(colisor1, &player_controller, "colisor1");

    colisor1.add_component(colisorIm1);
    colisor1.add_component(pc1);

    // GameObject colisor2("colisor2", 3, true, "ground");
    // colisor2.main_positionX = 1550;
    // colisor2.main_positionY = 385;
    //
    // ImageComponent colisorIm2(colisor2, "colisor_im2", "assets/sprites/retangulo_15.png", 2);
    // PlataformController pc2(colisor2, &player_controller, "colisor2");
    //
    // colisor2.add_component(colisorIm2);
    // colisor2.add_component(pc2);
    //
    // GameObject colisor3("colisor3", 3, true, "ground");
    // colisor3.main_positionX = 1640;
    // colisor3.main_positionY = 385;
    //
    // ImageComponent colisorIm3(colisor3, "colisor_im3", "assets/sprites/retangulo_15.png", 2);
    // PlataformController pc3(colisor3, &player_controller, "colisor3");
    //
    // colisor3.add_component(colisorIm3);
    // colisor3.add_component(pc3);

    GameObject colisor4("colisor4", 3, true, "ground");
    colisor4.main_positionX = 1360;
    colisor4.main_positionY = 405;

    ImageComponent colisorIm4(colisor4, "colisor_im4", "assets/sprites/retangulo_4.png", 2);
    PlataformController pc4(colisor4, &player_controller, "colisor4");

    colisor4.add_component(colisorIm4);
    colisor4.add_component(pc4);

    GameObject colisor5("colisor5", 3, true, "ground");
    colisor5.main_positionX = 2750;
    colisor5.main_positionY = 425;

    ImageComponent colisorIm5(colisor5, "colisor_im5", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc5(colisor5, &player_controller, "colisor5");

    colisor5.add_component(colisorIm5);
    colisor5.add_component(pc5);

    // GameObject colisor6("colisor6", 3, true, "ground");
    // colisor6.main_positionX = 3000;
    // colisor6.main_positionY = 425;
    //
    // ImageComponent colisorIm6(colisor6, "colisor_im6", "assets/sprites/retangulo_15.png", 2);
    // PlataformController pc6(colisor6, &player_controller, "colisor6");
    //
    // colisor6.add_component(colisorIm6);
    // colisor6.add_component(pc6);

    GameObject colisor7("colisor7", 3, true, "ground");
    colisor7.main_positionX = 3020;
    colisor7.main_positionY = 425;

    ImageComponent colisorIm7(colisor7, "colisor_im7", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc7(colisor7, &player_controller, "colisor7");

    colisor7.add_component(colisorIm7);
    colisor7.add_component(pc7);

    GameObject colisor8("colisor8", 3, true, "ground");
    colisor8.main_positionX = 3500;
    colisor8.main_positionY = 425;

    ImageComponent colisorIm8(colisor8, "colisor_im8", "assets/sprites/retangulo_1.png", 2);
    PlataformController pc8(colisor8, &player_controller, "colisor8");

    colisor8.add_component(colisorIm8);
    colisor8.add_component(pc8);

    GameObject colisor9("colisor9", 3, true, "ground");
    colisor9.main_positionX = 4300;
    colisor9.main_positionY = 600;

    ImageComponent colisorIm9(colisor9, "colisor_im9", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc9(colisor9, &player_controller, "colisor9");

    colisor9.add_component(colisorIm9);
    colisor9.add_component(pc9);

    GameObject colisor10("colisor10", 3, true, "ground");
    colisor10.main_positionX = 4635;
    colisor10.main_positionY = 650;

    ImageComponent colisorIm10(colisor10, "colisor_im10", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc10(colisor10, &player_controller, "colisor10");

    colisor10.add_component(colisorIm10);
    colisor10.add_component(pc10);

    GameObject colisor11("colisor11", 3, true, "ground");
    colisor11.main_positionX = 4800;
    colisor11.main_positionY = 500;

    ImageComponent colisorIm11(colisor11, "colisor_im11", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc11(colisor11, &player_controller, "colisor11");

    colisor11.add_component(colisorIm11);
    colisor11.add_component(pc11);

    GameObject colisor12("colisor12", 3, true, "ground");
    colisor12.main_positionX = 5150;
    colisor12.main_positionY = 520;

    ImageComponent colisorIm12(colisor12, "colisor_im12", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc12(colisor12, &player_controller, "colisor12");

    colisor12.add_component(colisorIm12);
    colisor12.add_component(pc12);

    GameObject colisor13("colisor13", 3, true, "ground");
    colisor13.main_positionX = 5310;
    colisor13.main_positionY = 340;

    ImageComponent colisorIm13(colisor13, "colisor_im13", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc13(colisor13, &player_controller, "colisor13");

    colisor13.add_component(colisorIm13);
    colisor13.add_component(pc13);

    GameObject colisor14("colisor14", 3, true, "ground");
    colisor14.main_positionX = 5580;
    colisor14.main_positionY = 190;

    ImageComponent colisorIm14(colisor14, "colisor_im14", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc14(colisor14, &player_controller, "colisor14");

    colisor14.add_component(colisorIm14);
    colisor14.add_component(pc14);

    GameObject colisor15("colisor15", 3, true, "ground");
    colisor15.main_positionX = 5860;
    colisor15.main_positionY = 120;

    ImageComponent colisorIm15(colisor15, "colisor_im15", "assets/sprites/retangulo_15.png", 2);
    PlataformController pc15(colisor15, &player_controller, "colisor15");

    colisor15.add_component(colisorIm15);
    colisor15.add_component(pc15);

    GameObject colisor16("colisor16", 3, true, "ground");
    colisor16.main_positionX = 5960;
    colisor16.main_positionY = 120;

    ImageComponent colisorIm16(colisor16, "colisor_im16", "assets/sprites/retangulo_29.png", 2);
    PlataformController pc16(colisor16, &player_controller, "colisor16");

    colisor16.add_component(colisorIm16);
    colisor16.add_component(pc16);

    GameObject colisor17("colisor17", 3, true, "ground");
    colisor17.main_positionX = 6240;
    colisor17.main_positionY = 660;

    ImageComponent colisorIm17(colisor17, "colisor_im17", "assets/sprites/retangulo_29.png", 2);
    PlataformController pc17(colisor17, &player_controller, "colisor17");

    colisor17.add_component(colisorIm17);
    colisor17.add_component(pc17);

    GameObject colisor18("colisor18", 3, true, "ground");
    colisor18.main_positionX = 6450;
    colisor18.main_positionY = 520;

    ImageComponent colisorIm18(colisor18, "colisor_im18", "assets/sprites/retangulo_22.png", 2);
    PlataformController pc18(colisor18, &player_controller, "colisor18");

    colisor18.add_component(colisorIm18);
    colisor18.add_component(pc18);

    GameObject colisor19("colisor19", 3, true, "ground");
    colisor19.main_positionX = 6550;
    colisor19.main_positionY = 600;

    ImageComponent colisorIm19(colisor19, "colisor_im19", "assets/sprites/retangulo_30.png", 2);
    PlataformController pc19(colisor19, &player_controller, "colisor19");

    colisor19.add_component(colisorIm19);
    colisor19.add_component(pc19);

    GameObject colisor20("colisor20", 3, true, "ground");
    colisor20.main_positionX = 7170;
    colisor20.main_positionY = 520;

    ImageComponent colisorIm20(colisor20, "colisor_im20", "assets/sprites/retangulo_30.png", 2);
    PlataformController pc20(colisor20, &player_controller, "colisor20");

    colisor20.add_component(colisorIm20);
    colisor20.add_component(pc20);

    GameObject colisor21("colisor21", 3, true, "ground");
    colisor21.main_positionX = 7500;
    colisor21.main_positionY = 650;

    ImageComponent colisorIm21(colisor21, "colisor_im21", "assets/sprites/retangulo_30.png", 2);
    PlataformController pc21(colisor21, &player_controller, "colisor21");

    colisor21.add_component(colisorIm21);
    colisor21.add_component(pc21);

    GameObject plataform1("plataform1", 3, true, "ground");
    plataform1.main_positionX = 1240;
    plataform1.main_positionY = 260;

    ImageComponent plataformIm1(plataform1, "plataform_im1", "assets/sprites/redim.png", 2);
    PlataformController ps1(plataform1, &player_controller, "plataform1");

    plataform1.add_component(plataformIm1);
    plataform1.add_component(ps1);

    GameObject plataform2("plataform2", 3, true, "ground");
    plataform2.main_positionX = 1540;
    plataform2.main_positionY = 120;

    ImageComponent plataformIm2(plataform2, "plataform_im2", "assets/sprites/min.png", 2);
    PlataformController ps2(plataform2, &player_controller, "plataform2");

    plataform2.add_component(plataformIm2);
    plataform2.add_component(ps2);

    GameObject plataform3("plataform3", 3, true, "ground");
    plataform3.main_positionX = 1950;
    plataform3.main_positionY = 250;

    ImageComponent plataformIm3(plataform3, "plataform_im3", "assets/sprites/plataform2.png", 2);
    PlataformController ps3(plataform3, &player_controller, "plataform3");

    plataform3.add_component(plataformIm3);
    plataform3.add_component(ps3);

    GameObject plataform4("plataform4", 3, true, "ground");
    plataform4.main_positionX = 2200;
    plataform4.main_positionY = 250;

    ImageComponent plataformIm4(plataform4, "plataform_im4", "assets/sprites/plataform2.png", 2);
    PlataformController ps4(plataform4, &player_controller, "plataform4");

    plataform4.add_component(plataformIm4);
    plataform4.add_component(ps4);

    GameObject plataform5("plataform5", 3, true, "ground");
    plataform5.main_positionX = 2530;
    plataform5.main_positionY = 270;

    ImageComponent plataformIm5(plataform5, "plataform_im5", "assets/sprites/plataform2.png", 2);
    PlataformController ps5(plataform5, &player_controller, "plataform5");

    plataform5.add_component(plataformIm5);
    plataform5.add_component(ps5);

    GameObject plataform6("plataform6", 3, true, "ground");
    plataform6.main_positionX = 2750;
    plataform6.main_positionY = 270;

    ImageComponent plataformIm6(plataform6, "plataform_im6", "assets/sprites/plataform2.png", 2);
    PlataformController ps6(plataform6, &player_controller, "plataform6");

    plataform6.add_component(plataformIm6);
    plataform6.add_component(ps6);

    GameObject plataform7("plataform7", 3, true, "ground");
    plataform7.main_positionX = 3000;
    plataform7.main_positionY = 270;

    ImageComponent plataformIm7(plataform7, "plataform_im7", "assets/sprites/plataform2.png", 2);
    PlataformController ps7(plataform7, &player_controller, "plataform7");

    plataform7.add_component(plataformIm7);
    plataform7.add_component(ps7);

    GameObject stairs1("stairs1", 3, true, "ground");
    stairs1.main_positionX = 6180;
    stairs1.main_positionY = 370;

    ImageComponent stairsIm1(stairs1, "stairs_im1", "assets/sprites/stairs.png", 2);
    PlataformController s1(stairs1, &player_controller, "stairs1");

    stairs1.add_component(stairsIm1);
    stairs1.add_component(s1);

    GameObject stairs2("stairs2", 3, true, "ground");
    stairs2.main_positionX = 6190;
    stairs2.main_positionY = 520;

    ImageComponent stairsIm2(stairs2, "stairs_im2", "assets/sprites/stairs.png", 2);
    PlataformController s2(stairs2, &player_controller, "stairs2");

    stairs2.add_component(stairsIm2);
    stairs2.add_component(s2);

    GameObject rect1("rect1", 3, true, "exit");
    rect1.main_positionX = 7850;
    rect1.main_positionY = 620;

    ImageComponent rectIm1(rect1, "rect_im1", "assets/sprites/placa_exit.png", 2);
    PlataformController r1(rect1, &player_controller, "rect1");

    rect1.add_component(rectIm1);
    rect1.add_component(r1);

    stage.add_game_object(&music_background);
    stage.add_game_object(&maps);
    stage.add_game_object(&donkey_player);
    stage.add_game_object(&background_stage);
    stage.add_game_object(&alligator1);
    stage.add_game_object(&colisor1);
    // stage.add_game_object(&colisor2);
    // stage.add_game_object(&colisor3);
    stage.add_game_object(&colisor4);
    stage.add_game_object(&colisor5);
    // stage.add_game_object(&colisor6);
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
    stage.add_game_object(&colisor20);
    stage.add_game_object(&colisor21);
    stage.add_game_object(&plataform1);
    stage.add_game_object(&plataform2);
    stage.add_game_object(&plataform3);
    stage.add_game_object(&plataform4);
    stage.add_game_object(&plataform5);
    stage.add_game_object(&plataform6);
    stage.add_game_object(&plataform7);
    stage.add_game_object(&stairs1);
    stage.add_game_object(&stairs2);
    stage.add_game_object(&head1);
    stage.add_game_object(&rect1);

// =========================== LOSE SCREEN ============================
    LoseScene lose("Lose");
    Game::instance.add_scene(lose);

    GameObject music_background_lose("music_background_lose", 4);

    GameObject background_lose("background_lose", 1);

    AudioComponent lose_music(background_lose, "lose_music", "assets/music/lose.mp3", true);
    ImageComponent background_lose_image(background_lose,"imageBackground_lose", "assets/sprites/lose_screen.png", 3);

    background_lose.add_component(background_lose_image);
    background_lose.add_component(lose_music);

    lose.add_game_object(&background_lose);
    lose.add_game_object(&music_background_lose);
// =======================================================================

    WinScene win("Win");
    Game::instance.add_scene(win);

    GameObject background_win("background_win", 1);

    ImageComponent background_win_image(background_win,"imageBackground_win", "assets/sprites/win.png", 3);

    background_win.add_component(background_win_image);

    win.add_game_object(&background_win);

    Game::instance.run();

    return 0;
}
