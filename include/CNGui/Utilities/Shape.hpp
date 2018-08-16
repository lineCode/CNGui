#ifndef SHAPE_HPP
#define SHAPE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector3.hpp>
#include "math.h"

namespace CNGui
{
////////////////////////////////////////////////////////////
/// \brief Class that creates a custom shape
///
////////////////////////////////////////////////////////////
class Shape : public sf::Shape
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Enumeration of the different shape types
    ///
    ////////////////////////////////////////////////////////////
    enum                    Type
    {
        Triangle,
        Rectangle,
        RoundedRectangle,
        Circle
    };

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
                            Shape(Type type = Type::Rectangle, sf::Vector3f size = sf::Vector3f(100, 50, 20));

    ////////////////////////////////////////////////////////////
    /// \brief Default destructor
    ///
    ////////////////////////////////////////////////////////////
    virtual                 ~Shape();

    ////////////////////////////////////////////////////////////
    /// \brief Set the type of the shape
    ///
    /// \param type Type of the shape
    ///
    /// \see getType
    ///
    ////////////////////////////////////////////////////////////
    void                    setType(Type type);

    ////////////////////////////////////////////////////////////
    /// \brief Get the type of the shape
    ///
    /// \return The type of the shape
    ///
    /// \see setType
    ///
    ////////////////////////////////////////////////////////////
    Type                    getType();

    ////////////////////////////////////////////////////////////
    /// \brief Set the size of the shape
    ///
    /// \param size Size of the shape
    ///
    /// \see getSize
    ///
    ////////////////////////////////////////////////////////////
    void                    setSize(sf::Vector3f size);

    ////////////////////////////////////////////////////////////
    /// \brief Get the size of the shape
    ///
    /// \return The size of the shape
    ///
    /// \see setSize
    ///
    ////////////////////////////////////////////////////////////
    sf::Vector3f            getSize();

    ////////////////////////////////////////////////////////////
    /// \brief Get the number of points defining the shape
    ///
    /// \return Number of points of the shape
    ///
    ////////////////////////////////////////////////////////////
    virtual std::size_t     getPointCount() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get a point of the rectangle
    ///
    /// The returned point is in local coordinates, that is,
    /// the shape's transforms (position, rotation, scale) are
    /// not taken into account.
    /// The result is undefined if \a index is out of the valid range.
    ///
    /// \param index Index of the point to get
    ///
    /// \return index-th point of the shape
    ///
    ////////////////////////////////////////////////////////////
    virtual sf::Vector2f    getPoint(std::size_t index) const;

protected:

private:
    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    Type            mType;  ///< Type of the shape
    sf::Vector3f    mSize;  ///< Size of the shape, z value for radius
};

} // namespace CNGui

#endif // SHAPE_HPP