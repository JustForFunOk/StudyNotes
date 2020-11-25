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
    // sj::shared_ptr<Rectangle> rect_ptr;
    // cout << rect_ptr.use_count() << endl;  // return 0

    shared_ptr<Rectangle> rect_ptr1(new Rectangle(6, 6));
    cout << rect_ptr1->getArea() << endl;
    cout << rect_ptr1.use_count() << endl;  // return 1

    func(rect_ptr1);

    // shared_ptr<Rectangle> rect_ptr2;
    // rect_ptr2 = rect_ptr;
    // cout << rect_ptr2->getArea() << endl;

    // cout << rect_ptr.use_count() << endl;
    // cout << rect_ptr2.use_count() << endl;

    return 0;
}