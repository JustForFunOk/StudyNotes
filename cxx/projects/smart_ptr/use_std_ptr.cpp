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



void func(shared_ptr<Rectangle> rect_ptr)
{
    shared_ptr<Rectangle> rect_ptr3 = rect_ptr;
    cout << rect_ptr3.use_count() << endl;
}

int main()
{
    shared_ptr<Rectangle> rect_ptr(new Rectangle(6, 6));
    cout << rect_ptr->getArea() << endl;

    func(rect_ptr);

    shared_ptr<Rectangle> rect_ptr2;
    rect_ptr2 = rect_ptr;
    cout << rect_ptr2->getArea() << endl;

    cout << rect_ptr.use_count() << endl;
    cout << rect_ptr2.use_count() << endl;

    return 0;
}