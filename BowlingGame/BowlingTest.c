//
// Created by mustafa58 on 16.08.2022.
//
#include "Game.h"
#include "../test.h"
#define PUBLIC
#define PRIVATE static

PRIVATE void *game;

/* @Test */
PUBLIC void canCreateGame() {
    game = newGame();
}

/* @Test */
PUBLIC void canRoll() {
    game_Roll(game, 0);
}

PRIVATE inline void rollMany(int n, int pins) {
    int i;
    for (i = 0; i < n; ++i) {
        game_Roll(game, pins);
    }
}

/* @Test */
PUBLIC void gutterGame() {
    rollMany(20, 0);
    assertEquals(game_Score(game), 0);
    delGame(game);
}

/* @Test */
PUBLIC void allOnes() {
    game = newGame();
    rollMany(20, 1);
    assertEquals(game_Score(game), 20);
    delGame(game);
}

PUBLIC void rollSpare() {
    game_Roll(game, 5);
    game_Roll(game, 5);
}

/* @Test */
void oneSpare() {
    game = newGame();
    rollSpare();
    game_Roll(game, 3);
    rollMany(17, 0);
    assertEquals(game_Score(game), 16);
    delGame(game);
}

PUBLIC void rollStrike() {
    game_Roll(game, 10);
}

/* @Test */
PUBLIC void oneStrike() {
    game = newGame();
    rollStrike();
    game_Roll(game, 3);
    game_Roll(game, 4);
    rollMany(16, 0);
    assertEquals(game_Score(game), 24);
    delGame(game);
}

/* @Test */
PUBLIC void perfectGame() {
    game = newGame();
    rollMany(12, 10);
    assertEquals(game_Score(game), 300);
    delGame(game);
}
