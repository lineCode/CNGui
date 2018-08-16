#ifndef OBJECT_HPP
#define OBJECT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "CNGui/Utilities/Style.hpp"
#include "CNGui/Utilities/EventHandler.hpp"
#include <assert.h>

namespace CNGui
{
////////////////////////////////////////////////////////////
/// \brief Base class for objects
///
////////////////////////////////////////////////////////////
class Object : public sf::Drawable, public sf::Transformable
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
                Object(const std::string& id, const sf::Vector3f& size, EventHandler& handleEvent, Style& style);

    ////////////////////////////////////////////////////////////
    /// \brief Default destructor
    ///
    ////////////////////////////////////////////////////////////
    virtual     ~Object();

    ///////////////////////////////////////////////////////////
    /// Overload of operator << to change the name of the object
    ///
    ////////////////////////////////////////////////////////////
    Object&     operator <<(const std::string& name);

    ///////////////////////////////////////////////////////////
    /// Overload of operator () to get the mouse position
    ///
    ////////////////////////////////////////////////////////////
    bool        operator()(const sf::Vector2f& mouse);

    ///////////////////////////////////////////////////////////
    /// Overload of operator () to get the mouse position
    ///
    ////////////////////////////////////////////////////////////
    bool        operator()(const sf::Vector2i& mouse);

protected:

    ////////////////////////////////////////////////////////////
    /// \brief Set the style of the shape
    ///
    /// \param style Style of the shape
    ///
    /// \see getStyle
    ///
    ////////////////////////////////////////////////////////////
    void            setStyle(Style& style);

    ////////////////////////////////////////////////////////////
    /// \brief Get the style of the shape
    ///
    /// \return The style of the shape
    ///
    /// \see setStyle
    ///
    ////////////////////////////////////////////////////////////
    Style&          getStyle();

    ////////////////////////////////////////////////////////////
    /// \brief Set the id of the shape
    ///
    /// \param id Id of the shape
    ///
    /// \see getId
    ///
    ////////////////////////////////////////////////////////////
    void            setId(const std::string& id);

    ////////////////////////////////////////////////////////////
    /// \brief Get the id of the shape
    ///
    /// \return The id of the shape
    ///
    /// \see setId
    ///
    ////////////////////////////////////////////////////////////
    std::string     getId();

    ////////////////////////////////////////////////////////////
    /// \brief Set the size of the shape
    ///
    /// \param size Size of the shape
    ///
    /// \see getSize
    ///
    ////////////////////////////////////////////////////////////
    void            setSize(const sf::Vector3f& size);

    ////////////////////////////////////////////////////////////
    /// \brief Get the size of the shape
    ///
    /// \return The size of the shape
    ///
    /// \see setSize
    ///
    ////////////////////////////////////////////////////////////
    sf::Vector3f    getSize();

    ////////////////////////////////////////////////////////////
    /// \brief Set the event handler of the shape
    ///
    /// \param handleEvent Event handler of the shape
    ///
    /// \see getEventHandler
    ///
    ////////////////////////////////////////////////////////////
    void            setEventHandler(EventHandler& handleEvent);

    ////////////////////////////////////////////////////////////
    /// \brief Get the event handler of the shape
    ///
    /// \return The event handler of the shape
    ///
    /// \see setEventHandler
    ///
    ////////////////////////////////////////////////////////////
    EventHandler&   getEventHandler();

    ////////////////////////////////////////////////////////////
    /// \brief Parse an id to an index and name
    ///
    /// \param id Id to parse
    /// \param index Index of the id to update
    /// \param name Name of the id to update
    ///
    ////////////////////////////////////////////////////////////
    void            parse(const std::string& id, sf::Uint16& index, std::string& name);

    ////////////////////////////////////////////////////////////
    /// \brief Updates the object
    ///
    ////////////////////////////////////////////////////////////
    virtual void    update();

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    sf::Uint16      mIndex;         ///< Index of the object
    std::string     mName;          ///< Name of the object
    sf::Vector3f    mSize;          ///< Size of the object, z value for radius
    EventHandler&   mHandleEvent;   ///< Event handler
    Style&          mStyle;         ///< Style of the object
    bool            mUpdate;        ///< Needs update?
    bool            mReturn;        ///< Bool conversion value
    sf::Vector2f    mMouse;         ///< Mouse position
};

} // namespace CNGui

#endif // OBJECT_HPP