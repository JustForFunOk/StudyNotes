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

namespace sj
{
template <class T>
class shared_ptr
{
public:
    shared_ptr(T* _p = nullptr)
    {
        ptr = _p;
        if(_p)
        {
            count++;
        }
    }
    ~shared_ptr()
    {
        count--;
        if(count <= 0)
        {
            delete ptr;
        }
    }
    shared_ptr(const T& _p)
    {

    }
    T& operator=(const T& _p)
    {

    }
    T& operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }
    int use_count()
    {

    }
    static int count;
private:
    T* ptr;
};

} // namespace sj

sj::shared_ptr::count = 0;

void func(sj::shared_ptr<Rectangle> rect_ptr)
{
    sj::shared_ptr<Rectangle> rect_ptr3 = rect_ptr;
    cout << rect_ptr3.use_count() << endl;
}

int main()
{
    sj::shared_ptr<Rectangle> rect_ptr(new Rectangle(6, 6));
    cout << rect_ptr->getArea() << endl;

    func(rect_ptr);

    sj::shared_ptr<Rectangle> rect_ptr2;
    rect_ptr2 = rect_ptr;
    cout << rect_ptr2->getArea() << endl;

    cout << rect_ptr.use_count() << endl;
    cout << rect_ptr2.use_count() << endl;

    return 0;
}