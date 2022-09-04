//
// Created by mustafa58 on 16.08.2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define PUBLIC
#define PRIVATE static

#define nextBallForSpare(firstInFrame) game->rolls[firstInFrame + 2]
#define twoBallsInFrame(firstInFrame) \
game->rolls[firstInFrame] + game->rolls[firstInFrame+1]
#define nextTwoBallsForStrike(firstInFrame) \
game->rolls[firstInFrame+1] + game->rolls[firstInFrame+2]

struct Game {
    int rolls[21];
    int currentRoll;
};

PUBLIC struct Game* newGame() {
    struct Game* pGame = NULL;
    pGame = (struct Game *)malloc(sizeof(struct Game));
    if(pGame == NULL) perror("No memory.\n");
    else {
        for (int i = 0; i < 21; ++i)
            pGame->rolls[i] = 0;
        pGame->currentRoll = 0;
    }
    return pGame;
}

PUBLIC void delGame(struct Game* game) {
    free(game);
}

PUBLIC void game_Roll(struct Game* game, int pins) {
    game->rolls[game->currentRoll++] = pins;
}

PRIVATE inline bool isSpare(const struct Game *game, int firstInFrame) {
    return game->rolls[firstInFrame] + game->rolls[firstInFrame + 1] == 10;
}

PRIVATE inline bool isStrike(const struct Game *game, int firstInFrame) {
    return game->rolls[firstInFrame] == 10;
}

PUBLIC int game_Score(struct Game* game) {
    int score = 0;
    int firstInFrame = 0;
    for (int frame = 0; frame < 10; ++frame) {
        if(isStrike(game, firstInFrame)) {
            score += 10 + nextTwoBallsForStrike(firstInFrame);
            firstInFrame += 1;
        } else if(isSpare(game, firstInFrame)) {
            score += 10 + nextBallForSpare(firstInFrame);
            firstInFrame += 2;
        } else {
            score += twoBallsInFrame(firstInFrame);
            firstInFrame += 2;
        }
    }
    return score;
}