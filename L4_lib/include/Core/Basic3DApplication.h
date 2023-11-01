#pragma once
#include "Application.h"
#include "dll.h"
#include "Controller3D.h"


class Basic3DApplication : public Application
{
public:

    L4_API Basic3DApplication(const WindowSettings& window_settings);

    L4_API void run() override;

protected:

    L4_API void loop() override;

    L4_API virtual void onUpdate(const float& dt) = 0;

private:

    Controller3D* m_controller3D;

};