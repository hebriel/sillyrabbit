
# sillyrabbit
## Important notes

Really small OpenGL engine using SFML, please note the following :

 * It's just a way to simplify the code. You STILL need to know OpenGL
 * This is NOT working with OpenGL 3.x, 4.x, ES, or Vulkan.
 * The engine is based on [SFML 2.4.2](http://sfml-dev.org), you need to know this library for some aspects (such as events).

**This project is incomplete.** So I won't do a wiki for a while. I don't recommend you to use sillyrabbit for now, as there is no documentation (some code below to help anyway).

## Code example

This part is far from being done and you probably won't be able to make a project with  the following. Please read the ***Important notes*** section for more information.



```cpp
#include <eyax/Application.hpp> //Will change in future versions

class mainState : public eyax::GameState
{
    public:
    mainState(eyax::Application* parentApplication) //has to be there
        : eyax::GameState(parentApplication)
    { }
    virtual ~mainState() //has to be there
    { }
    bool init() //has to be there
    {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        return true;
    }
    void handleEvents(const sf::Event& e) //has to be there
    {
		//No need to check for sf::Event::Closed, sillyrabbit already handles it
    }
    
    void update(const sf::Time& dt) //has to be there
    {
		//Update code goes here
    }

    void render(const sf::Time& dt) //has to be there
    {
        glClear(GL_COLOR_BUFFER_BIT);
        //No need to swap buffers or display the window, SFML and sillyrabbit already handles everything
    }

    void cleanup() //has to be there
    { }

};

class myGame : public eyax::Application
{
    public:
    myGame(const char* title, unsigned int width, unsigned int height, const sf::Uint32& style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings())
        : eyax::Application(title, width, height, style, settings) //has to be there
    { }

    bool init() //has to be there
    {
        mstate = new mainState(this); //Creating a game state

        pushState(mstate); //pushing the state

        return true;
    }

    void cleanup() //has to be there
    {
        delete mstate; //avoid memory leak
    }

    private:

        mainState* mstate; //You need to create states dynamically because it may take some memory (so it's better to allocate in the heap) and the state should be accessible all the time it's running.

};

int main()
{

    myGame app("Silly Rabbit", 800, 600); //Easy one
    app.window->setFramerateLimit(60); //You can access the SFML window directly

    return app.run(); //It's not mandatory to exit with the Engine status, but it's recommended.
}
```

