#include "lose.hpp"

using namespace engine;

void LoseScene::game_logic(){
    if(Game::instance.input_manager().is_button_down("enter")){
        Game::instance.change_scene("Menu");
    }
}

LoseScene::~LoseScene(){}
