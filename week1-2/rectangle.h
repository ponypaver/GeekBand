#ifndef __MY_RECTANGLE__
#define __MY_RECTANGLE__

class Shape
{
private:
    int no;
};

class Point
{
public:
    Point(int x, int y)
        : x(x), y(y)
    {
    }
private:
    int x;
    int y;
};

class Rectangle : public Shape
{
public:
    Rectangle(int width, int height, int x, int y);
    Rectangle(const Rectangle& other);
    Rectangle& operator = (const Rectangle& other);

    ~Rectangle();

private:
    int width, height;
    Point *leftUp;
};

Rectangle::Rectangle(int width, int height, int x, int y)
    : width(width), height(height), leftUp(new Point(x, y))
{
}

Rectangle::Rectangle(const Rectangle& other)
    : width(other.width), height(other.height), leftUp(new Point(*other.leftUp)) 
{ 
}

Rectangle& Rectangle::operator = (const Rectangle& other)
{
    width = other.width;
    height = other.height;
    leftUp = new Point(*other.leftUp);

    return *this;
}

Rectangle::~Rectangle()
{
    delete leftUp;
}

#endif
