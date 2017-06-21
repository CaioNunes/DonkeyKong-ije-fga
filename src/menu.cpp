#include "menu.hpp"

using namespace engine;

void MenuScene::game_logic(){
    if(Game::instance.input_manager().is_button_down("enter")){
        Game::instance.change_scene("start");
    }
}

MenuScene::~MenuScene(){}
