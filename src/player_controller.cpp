#include "player_controller.hpp"

double moveForce = 3;

bool PlayerController::init() { return true; }

void PlayerController::update(){
    move_player();
}

void PlayerController::move_player(){
    if(Game::instance.input_manager().is_button_down("down")){
        walkDown = true;
    }

    if(walkDown){
        _main_game_object->main_positionY += moveForce;
    }
}

PlayerController::~PlayerController(){}
