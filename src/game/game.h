#pragma once

struct GameParams
{
    unsigned int bValid;
    unsigned int snoInitialWorld;
    unsigned int snoInitialQuest;
    unsigned int nInitialQuestStepUID;
    unsigned int dword10;
    unsigned int bResumeFromSave;
    unsigned int dwSeed;
    unsigned int eGameType;
    unsigned int dwCreationFlags;
    unsigned int dword24;
    unsigned int dword28;
    unsigned int dword2C;
    unsigned int nGameParts;
    unsigned int eDifficulty;
    unsigned int nHandicapLevel;
    unsigned int eAct;
    unsigned int dword40;
    unsigned int dword44;
    unsigned int dword48;
    unsigned int dword4C;
    unsigned int dword50;
    unsigned int dword54;
    unsigned int dword58;
    unsigned int dword5C;
    unsigned int dword60;
    unsigned int dword64;
    char szServerAddress[260];
    unsigned int dword16C;
    char szReplayFileName[260];
    char szGameName[260];
    unsigned int dword378;
    unsigned int dword37C;
    unsigned int tGameId[6];
    unsigned int dword398;
    unsigned int uHeroId[2];
    unsigned int uServerAuthToken[2];
    unsigned int idSGame;
    unsigned int dword3B4;
};
