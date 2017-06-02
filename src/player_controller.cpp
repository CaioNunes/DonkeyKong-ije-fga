#include "player_controller.hpp"

double moveForceUp = 7;
double moveForceDown = 3;

bool PlayerController::init() { return true; }

void PlayerController::update(){
    move_player();
}

void PlayerController::move_player(){
    if(Game::instance.input_manager().is_button_down("down")){
        walkDown = true;
    }

    if(Game::instance.input_manager().is_button_up("down")){
        walkDown = false;
    }

    if(walkDown){
        _main_game_object->main_positionY += moveForceDown;
    }

    if(Game::instance.input_manager().is_button_down("up")){
        walkUp = true;
    }

    if(Game::instance.input_manager().is_button_up("up")){
        walkUp = false;
    }

    if(walkUp){
        _main_game_object->main_positionY -= moveForceUp;
    }
}

PlayerController::~PlayerController(){}
