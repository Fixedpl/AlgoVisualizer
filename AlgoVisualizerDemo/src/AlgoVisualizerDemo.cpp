﻿#include <iostream>

#include "Test/TestingEnvironment.h"
#include "tests/CircleTest.h"
#include "tests/CircleGridTest.h"
#include "tests/RectangleTest.h"
#include "tests/TextTest.h"
#include "tests/RenderersTest.h"
#include "tests/ShadertoyTest.h"
#include "tests/EasingTest.h"
#include "tests/ArrayTest.h"
#include "tests/NodeTest.h"




int main()
{
    WindowSettings window_settings;
    window_settings.opengl_debug = false;

    TestingEnvironment env(window_settings);

    env.registerTest<CircleTest>("Circle");
    env.registerTest<CircleGridTest>("Circle grid");
    env.registerTest<RectangleTest>("Rectangle");
    env.registerTest<TextTest>("Text");
    env.registerTest<RenderersTest>("Renderers");
    env.registerTest<ShadertoyTest>("Shadertoy");
    env.registerTest<EasingTest>("Easing");
    env.registerTest<ArrayTest>("Array");
    env.registerTest<NodeTest>("Node");

    env.loadTest("Node");

    env.run();

    return 0;
}

