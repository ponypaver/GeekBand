#ifndef __MY_RECTANGLE__
#define __MY_RECTANGLE__

class Shape
{
public:
    Shape(int n)
     : no(n)
    { }
    Shape& operator = (const Shape& o)
    {
        no = o.no;
    }
private:
    int no;
};

class Point
{
public:
    Point(int x, int y)
        : x(x), y(y)
    { }
    bool operator == (Point &p)
    {
        return (x == p.x && y == p.y); 
    }

private:
    int x;
    int y;
};

class Rectangle : public Shape
{
public:
    Rectangle(int n, int width, int height, int x, int y);
    Rectangle(const Rectangle& other);
    bool operator == (const Rectangle& other);
    Rectangle& operator = (const Rectangle& other);

    ~Rectangle();

private:
    int width, height;
    Point *leftUp;
};

inline Rectangle::Rectangle(int n, int width, int height, int x, int y)
    : width(width), height(height), leftUp(new Point(x, y)), Shape(n)
{ }

inline Rectangle::Rectangle(const Rectangle& other)
    : Shape(other), width(other.width), height(other.height)
{ 
    if (NULL == other.leftUp)
        leftUp = NULL;
    else
        leftUp = new Point(*other.leftUp);

}

inline Rectangle& Rectangle::operator = (const Rectangle& other)
{
    if (*this == other)
        return *this;

    width = other.width;
    height = other.height;
    if (NULL == other.leftUp)
        leftUp = NULL;
    else
        leftUp = new Point(*other.leftUp);

    Shape::operator = (other);

    return *this;
}

inline bool Rectangle::operator == (const Rectangle& other)
{
    
    return (width == other.width && height == other.height && *leftUp == *other.leftUp);
}

Rectangle::~Rectangle()
{
    delete leftUp;
}

#endif
