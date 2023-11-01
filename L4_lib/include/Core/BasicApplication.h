#pragma once
#include "Application.h"
#include "dll.h"



class BasicApplication : public Application
{
public:

    L4_API BasicApplication(const WindowSettings& window_settings);

    L4_API void run() override;

protected:

    L4_API void loop() override;

    L4_API virtual void onUpdate(const float& dt) = 0;

};

