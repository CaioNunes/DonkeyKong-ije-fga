#include "player.hpp"

bool Player::init(){return true;}

// ================================================= GAME LOGIC ====================================================
void Player::update(){

    animCtrl->play_animation("donkey_swim");
}

Player::~Player(){}
