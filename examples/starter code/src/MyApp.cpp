#include "MyApp.hpp"


MyApp::MyApp(const wchar_t* title, unsigned int width, unsigned int height, const sf::Uint32& style, const sf::ContextSettings& settings)
    : sr::Application(title, width, height, style, settings)
{ }

MyApp::MyApp(const char* title, unsigned int width, unsigned int height, const sf::Uint32& style, const sf::ContextSettings& settings)
    : sr::Application(title, width, height, style, settings)
{ }

MyApp::~MyApp()
{ }

bool MyApp::init()
{
    state = new states::myState(this);

    pushState(state);

    return true;
}

void MyApp::cleanup()
{
    delete state;
}
