#include "hooks.h"
#include "hydra_types.h"
#include "memory_helpers.h"

#include <rex/logging.h>

void RehydratedHook_SGameInitializeGame(PPCRegister& r3)
{
	const Hydra::GameParams* tParams = Rehydrated::at<Hydra::GameParams>(r3.u32);

	REXLOG_INFO("SGameInitializeGame():\n bValid=0x{:X},\n snoInitialWorld=0x{:X},\n snoInitialQuest=0x{:X},\n nInitialQuestStepUID=0x{:X},\n dword10=0x{:X},\n bResumeFromSave=0x{:X},\n dwSeed=0x{:X},\n eGameType=0x{:X},\n dwCreationFlags=0x{:X},\n szServerAddress={},\n szReplayFileName={},\n szGameName={}",
		tParams->bValid,
		tParams->snoInitialWorld,
		tParams->snoInitialQuest,
		tParams->nInitialQuestStepUID,
		tParams->dword10,
		tParams->bResumeFromSave,
		tParams->dwSeed,
		tParams->eGameType,
		tParams->dwCreationFlags,
		tParams->szServerAddress,
		tParams->szReplayFileName,
		tParams->szGameName);
}
