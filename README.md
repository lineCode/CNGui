# CNGui

CNGui (Chats Noirs Gui) is a graphical user interface (GUI) library using SFML and C++.
It is actually in development by Fatih#6810 (accfldekur@gmail.com) from *Les Chats Noirs du Clair de Lune*.

***
**Prototype example code**

An example code showing how CNGui is user-friendly! 

```cpp
#include <SFML/Graphics.hpp>
#include "CNGui.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 480), "CNGui Example");
    window.setFramerateLimit(60);

    CNGui::EventHandler handleEvent;

    CNGui::Style style;
    style.shape = CNGui::Shape::RoundedRectangle;
    style.fillcolor = sf::Color(200, 200, 200);
    style.hovercolor = sf::Color(100, 100, 100);
    style.selectable = false;
    style.outline = true;

    CNGui::Button button("Button#001", sf::Vector3f(200, 100, 25), handleEvent, style);
    button.setPosition(50, 50);

    while(window.isOpen())
    {
        handleEvent.clear();

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            handleEvent.push(event);
        }

        if(button(sf::Mouse::getPosition(window)))
            button << "I think thats too long hahahahha";

        window.clear();
        window.draw(button);
        window.display();
    }
}
```
![output](https://image.ibb.co/kuH8TK/CNGui_button.png)

***
**Explanations**

`CNGui::EventHolder` class that holds SFML events that you can use further in the code to update your objects.
`CNGui::Style` struct that holds style parameters that the user can modify and apply to an object.
`CNGui::Object` base parent for every objects.
`CNGui::Shape` class that inheritates from `sf::Shape`, you can initialize it with a type of shape as Rectangle, Triangle, Circle or RoundedRectangle.

***
**Creating a new object made easy**

You can easily create a new object by inheriting from the Object class, your class has to contain an uptade() function and a SFML draw() function.

```cpp
class Button : public Object
{
public:
    using Object::Object;

private:
    void update()
    {
        if(mUpdate) 
        {
            //Update object's style here
            mShape.setType(mStyle.shape);
            mShape.setSize(mSize);
            mShape.setFillColor(mStyle.fillcolor);
            mUpdate = false;
        }
        
        //Update the object here
        if(sf::FloatRect(getPosition().x, getPosition().y, mShape.getGlobalBounds().width, mShape.getGlobalBounds().height).contains(mMouse))
        {
            if(mHandleEvent.isActive(sf::Event::MouseButtonPressed))
            {
                mShape.setFillColor(mStyle.clickedcolor);
                mReturn = true; 
            }
            else
            {
                mShape.setFillColor(mStyle.hovercolor);
                mReturn = false;
            }
        }
        else
        {
            mShape.setFillColor(mStyle.fillcolor);
        }
    }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        //Draw your members here
        target.draw(mShape, states);
    }

    Shape mShape; //Background shape
};
```

Check
`CNGui::Object`'s members to see what you can use for your object. If you need more style parameters to customize your object add it to the `CNGui::Style` struct.
