#include "rehydrated_app.h"

#include <filesystem>
#include <string>

#include <rex/cvar.h>
#include <rex/logging.h>

#include "recomp/input_manager.h"
#include "recomp/network/pc_proxy.h"

#include "generated/default/rehydrated_init.h"

std::unique_ptr<rex::ui::WindowedApp> RehydratedApp::Create(rex::ui::WindowedAppContext& ctx)
{
    return std::unique_ptr<RehydratedApp>(new RehydratedApp(ctx, "rehydrated", PPCImageConfig));
}

void RehydratedApp::OnPreSetup(rex::RuntimeConfig& config)
{
    if (config.gpu_plugin.empty())
    {
        REXLOG_INFO("No GPU plugin set, defaulting to xenos");
        config.gpu_plugin = "xenos";
    }
}

void RehydratedApp::OnPostSetup()
{
    // This fixed the black screen instead of 3D graphics issue on the D3D12 backend.
    // It needs to be set after the GPU plugin is initialized and the cvar is added to the registry.
    rex::cvar::SetFlagByName("execute_unclipped_draw_vs_on_cpu", "true");

    PCProxy::Instance().Initialize();
}

void RehydratedApp::OnCreateDialogs(rex::ui::ImGuiDrawer* drawer)
{
    InputManager::Instance().Initialize(window());
}

void RehydratedApp::OnConfigurePaths(rex::PathConfig& paths)
{
    std::string appRoot = "./";

    paths.game_data_root = appRoot + "assets";
    paths.user_data_root = appRoot + "save";
    paths.cache_root = appRoot + "cache";

    // fallback for when the build is in the out directory
    if (!std::filesystem::exists(paths.game_data_root))
        paths.game_data_root = appRoot + "../../../assets";
}
