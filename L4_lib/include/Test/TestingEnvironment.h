#pragma once
#include <unordered_map>

#include "Core/ImGuiApplication.h"
#include "Test/Test.h"

class TestingEnvironment : public ImGuiApplication
{
public:

    L4_API TestingEnvironment(const WindowSettings& window_settings);

    template<typename T>
    void registerTest(const std::string& name);

    L4_API void loadTest(const std::string& name);

protected:

    L4_API void onUpdate(const float& dt) override;

    L4_API void onImGuiUpdate() override;

private:

    void testEndCallback() {
        Test* buffer = m_current_test;
        m_current_test = &m_empty_test;
        delete buffer;
    }

private:

    Test m_empty_test;

    Test* m_current_test;

    std::unordered_map<std::string, std::function<Test* ()>> m_tests;

};

template<typename T>
inline void TestingEnvironment::registerTest(const std::string& name)
{
    m_tests[name] = [this]() {
        Test* new_test = new T(&m_window);
        new_test->m_on_test_end_callback = [this]() { this->testEndCallback(); };
        return new_test;
    };
}