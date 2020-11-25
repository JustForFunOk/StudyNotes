#include <iostream>
#include <memory>

using namespace std;

class Rectangle
{
public:
    explicit Rectangle(int _l, int _w)
    {
        length = _l;
        width = _w;
    }
    ~Rectangle() = default;
    int getArea()
    {
        return length*width;
    }

private:
    int length;
    int width;
};

int main()
{
    unique_ptr<Rectangle> rect_ptr(new Rectangle(6, 6));
    rect_ptr->getArea();

    // unique_ptr<Rectangle> rect_ptr2(rect_ptr);

    unique_ptr<Rectangle> rect_ptr2;
    rect_ptr2 = move(rect_ptr);

    cout << rect_ptr2->getArea() << endl;

    cout << rect_ptr->getArea() << endl;
}