#include "rehydrated_app.h"

#include "recomp/network/pc_proxy.h"

#include "generated/default/rehydrated_init.h"

std::unique_ptr<rex::ui::WindowedApp> RehydratedApp::Create(rex::ui::WindowedAppContext& ctx)
{
    return std::unique_ptr<RehydratedApp>(new RehydratedApp(ctx, "rehydrated", PPCImageConfig));
}

void RehydratedApp::OnPostSetup()
{
    PCProxy::Instance().Initialize();
}
