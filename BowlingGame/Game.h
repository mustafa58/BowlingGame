//
// Created by mustafa58 on 16.08.2022.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

extern void* newGame();
extern void delGame(void* game);
extern void game_Roll(void* game, int pins);
extern int game_Score(void* game);

#endif //UNTITLED_GAME_H
