#include "plataform_controller.hpp"

bool PlataformController::init(){return true;}

void PlataformController::update(){
    move_plataform();
}

void PlataformController::move_plataform(){

    //Move Right
    if(Game::instance.input_manager().is_button_down("right"))
        walkRight = true;

    if(Game::instance.input_manager().is_button_up("right"))
        walkRight = false;

    if(walkRight && player->limit == false){
        _main_game_object->main_positionX -= moveSide;
    }
    //Move Left
    if(Game::instance.input_manager().is_button_down("left")){
        walkLeft = true;
    }

    if(Game::instance.input_manager().is_button_up("left"))
        walkLeft = false;

    if(walkLeft && player->limit == false){
        _main_game_object->main_positionX += moveSide;
    }
}

PlataformController::~PlataformController(){}
