#ifndef LOG_H
#define LOG_H

#include "Game.h"

void CreateLog();

void PlayerLog(Game *game, int Rank1, int File1, int Rank2, int File2);

void ComputerLog(Game *game, int Rank1, int File1, int Rank2, int File2);

void LogWin(Game *game);

void OpenLog();

#endif
