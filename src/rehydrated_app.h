#pragma once

#include <rex/app/title_app.h>

#include "generated/default/rehydrated_init.h"

class RehydratedApp : public rex::app::TitleApp
{
public:
	RehydratedApp() : TitleApp("rehydrated", kPPCImageConfig) {}

protected:
	rex::Result<void> OnConfigure(rex::SettingsRegistry& settings) override;
	rex::Result<void> OnInit() override;
};
