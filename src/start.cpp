#include "start.hpp"

using namespace engine;

void StartScene::game_logic(){
    if(Game::instance.input_manager().is_button_down("enter")){
        Game::instance.change_scene("WaterStage");
    }
}

StartScene::~StartScene(){}
