//
// Created by Дима on 06.12.2020.
//

#include "Player.h"
#include "RandomPlayer.h"
#include "OptionalPlayer.h"
#include "ConsolePlayer.h"

Player *Player::createPlayer(PlayerType type) {
    Player *gamer = nullptr;
    switch(type)
    {
        case Random:
            gamer = new RandomPlayer();
            break;
        case Optional:
            gamer = new OptionalPlayer();
            break;
        case Interactive:
            gamer = new ConsolePlayer();
            break;
    }
    return gamer;
}