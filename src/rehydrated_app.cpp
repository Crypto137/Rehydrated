#include "rehydrated_app.h"

#include <rex/logging/logger.h>

#include "recomp/input_manager.h"
#include "recomp/network/pc_proxy.h"

namespace
{

void SetTitleSetting(rex::SettingsRegistry& settings, std::string_view name, std::string_view text)
{
    auto result = settings.SetText(rex::SettingLayer::kTitle, name, text);
    if (!result)
        REXLOG_WARN("Failed to set {} to {}", name, text);
}

}

rex::Result<void> RehydratedApp::OnConfigure(rex::SettingsRegistry& settings)
{
    SetTitleSetting(settings, "app.root", "./");
    SetTitleSetting(settings, "app.user_root", "./save");
    SetTitleSetting(settings, "app.cache_root", "./cache");
    SetTitleSetting(settings, "app.log_root", "./logs");

    SetTitleSetting(settings, "title.game_root", "./assets");

    // This fixes the black screen instead of 3D graphics issue on the D3D12 backend.
    SetTitleSetting(settings, "gpu.xenos.execute_unclipped_draw_vs_on_cpu", "true");

    // Default value causes the game to not boot properly for some reason.
    SetTitleSetting(settings, "runtime.title_memory_mb", "0");

    return rex::Ok();
}

rex::Result<void> RehydratedApp::OnInit()
{
    PCProxy::Instance().Initialize();
    //InputManager::Instance().Initialize(window());

    return rex::Ok();
}
