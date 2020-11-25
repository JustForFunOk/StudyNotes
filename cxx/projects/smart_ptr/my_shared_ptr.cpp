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
    shared_ptr(T* _p = nullptr) : ptr(nullptr), count_ptr_(nullptr)
    {
        if(_p)
        {
            ptr = _p;
            count_ptr_ = new int(1);
            *count_ptr_ = 1;
        }
    }
    ~shared_ptr()
    {
        if (count_ptr_)
        {
            (*count_ptr_)--;
            if(count_ptr_ <= 0)
            {
                delete ptr;
                delete count_ptr_;
            }
        }
    }
    shared_ptr(const shared_ptr<T>& _p)
    {
        ptr = _p.ptr;
        count_ptr_ = _p.count_ptr_;
        (*count_ptr_)++;
    }
    shared_ptr<T>& operator=(const shared_ptr<T>& _shared_ptr)
    {
        if(ptr != _shared_ptr.ptr)
        {
            if (count_ptr_)
            {
                (*count_ptr_)--;
                if(count_ptr_ <= 0)
                {
                    delete ptr;
                    delete count_ptr_;
                }
                ptr = _shared_ptr.ptr;
                count_ptr_ = _shared_ptr.count_ptr_;
                (*count_ptr_)++;
            }
            else
            {
                count_ptr_ = new int(1);
                count_ptr_ = _shared_ptr.count_ptr_;
                ptr = _shared_ptr.ptr;
                (*count_ptr_)++;
            }

        }
        return *this;
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
        return count_ptr_ ? *count_ptr_ : 0;
    }
private:
    T* ptr;
    int* count_ptr_;
};

} // namespace sj


void func(sj::shared_ptr<Rectangle>& rect_ptr)
{
    sj::shared_ptr<Rectangle> rect_ptr3 = rect_ptr;
    cout << rect_ptr3.use_count() << endl;
}

int main()
{
    sj::shared_ptr<Rectangle> rect_ptr;
    cout << rect_ptr.use_count() << endl;  // return 0

    sj::shared_ptr<Rectangle> rect_ptr1(new Rectangle(6, 6));
    cout << rect_ptr1->getArea() << endl;
    cout << rect_ptr1.use_count() << endl;  // return 1

    func(rect_ptr1);  // return 2
    cout << rect_ptr1.use_count() << endl;  // return 1

    rect_ptr = rect_ptr1;
    cout << rect_ptr1.use_count() << endl;  // return 2

    // sj::shared_ptr<Rectangle> rect_ptr2;
    // rect_ptr2 = rect_ptr;
    // cout << rect_ptr2->getArea() << endl;

    // cout << rect_ptr.use_count() << endl;
    // cout << rect_ptr2.use_count() << endl;


    return 0;
}