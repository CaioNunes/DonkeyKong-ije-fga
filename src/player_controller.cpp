#include "player_controller.hpp"

double moveForceUp = 7;
double moveForceDown = 2;
double moveSide = 3;

bool PlayerController::init() { return true; }

void PlayerController::update(){
    move_player();
}

void PlayerController::move_player(){
    //Move down
    if(Game::instance.input_manager().is_button_down("down"))
        walkDown = true;

    if(Game::instance.input_manager().is_button_up("down"))
        walkDown = false;

    if(walkDown)
        _main_game_object->main_positionY += moveForceDown;

    //Move Up
    if(Game::instance.input_manager().is_button_down("up"))
        walkUp = true;

    if(Game::instance.input_manager().is_button_up("up"))
        walkUp = false;

    if(walkUp)
        _main_game_object->main_positionY -= moveForceUp;

    //Move Right
    if(Game::instance.input_manager().is_button_down("right"))
        walkRight = true;

    if(Game::instance.input_manager().is_button_up("right"))
        walkRight = false;

    if(walkRight)
        _main_game_object->main_positionX += moveSide;

    //Move Left
    if(Game::instance.input_manager().is_button_down("left"))
        walkLeft = true;

    if(Game::instance.input_manager().is_button_up("left"))
        walkLeft = false;

    if(walkLeft)
        _main_game_object->main_positionX -= moveSide;
}

PlayerController::~PlayerController(){}
