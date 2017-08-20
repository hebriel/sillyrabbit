#include "sillyrabbit/Application.hpp"

namespace sr {

Application::Application(const wchar_t* title, unsigned int width, unsigned int height,
                         const sf::Uint32& style, const sf::ContextSettings& settings)
                            : window(new sf::Window(sf::VideoMode(width, height), title, style, settings)), m_isRunning(true), m_isMouseLocked(false)
{ }

Application::Application(const char* title, unsigned int width, unsigned int height,
                         const sf::Uint32& style, const sf::ContextSettings& settings)
                            : window(new sf::Window(sf::VideoMode(width, height), title, style, settings)), m_isRunning(true), m_isMouseLocked(false)
{ }

Application::~Application()
{
    delete window;
    #ifdef SILLYRABBIT_DEBUG
        std::cout << "SILLYRABBIT DEBUG MODE : Application ended." << std::endl;
    #endif // SILLYRABBIT_DEBUG
}

bool Application::init()
{
    return true;
}

void Application::cleanup()
{ }

int Application::run()
{
    if(!init())
    {
        std::cerr << "Error while initializing application [1]" << std::endl;
        return 1;
    }

    while(m_isRunning)
    {
        if(!m_states.empty())
        {
            m_states.top()->run();
        }
        else
        {
            std::cerr << "No game states to run [3]" << std::endl;
            return 3;
        }
    }

    return 0;
}

void Application::quit()
{
    m_isRunning = false;
    window->close();
}
void Application::pushState(GameState* state)
{
    m_states.push(state);
}

void Application::popState()
{
    m_states.pop();
}

void Application::lockMouse()
{
    m_isMouseLocked = true;
    window->setMouseCursorGrabbed(true);
}

void Application::unlockMouse()
{
    m_isMouseLocked = false;
    window->setMouseCursorGrabbed(false);
}

void Application::setMouseDelta(const sf::Vector2i& newDelta)
{
    m_mouseDelta = newDelta;
}

}
