#ifndef __MY_SHAPE_H__
#define __MY_SHAPE_H__

/* 

为下面的Rectangle 和Circle 类重写getArea 虚函数。然后创建一个数组。
使用一个循环，生成10 个Rectangle、10 个Circle，根据循环遍历顺序为它
们设置no 编号，位置、长、宽、半径等其他信息取随机1～10 之间的整数值，
然后将它们加入到创建好的数组中。最后，将这个长度为20 的数组中所有面
积小于50 的形状删除。将剩下的形状组成一个新的数组返回。

注意： 
1. 补齐任务所需的其他函数。2. 考虑正确的内存管理。3. 使用原生数
组，不使用vector 等容器。

*/

class Shape
{
public:
    virtual int getArea() = 0;

private:
    int no;
};

class Point
{
public:
    Point(int xx, int yy)
        : x(xx), y(yy)
    { }

private:
    int x;
    int y;
};

class Rectangle: public Shape
{
public:
    Rectangle(int n, int xx, int yy, int w, int h);
    int getArea();

private:
    int width;
    int height;
    Point leftUp;
};

class Circle: public Shape
{
public:
    Circle(int n, int xx, int yy, int r);
    int getArea();

private:
    Point center;
    int radius;
};

inline int Rectangle::getArea()
{
    return width * height;
}

inline int Circle::getArea()
{
    return M_PI * radius * radius;
}

#endif
