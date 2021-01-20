#include <iostream>
template <class T>
class shared_ptr
{
public:
    shared_ptr(): ptr_(nullptr), use_count_ptr_(nullptr)
    {

    }

    shared_ptr(T* ptr): ptr_(ptr), use_count_ptr_(nullptr)
    {
        use_count_ptr_ = new int;
        *use_count_ptr_ = 1;
    }

    shared_ptr(const shared_ptr<T>& ptr)
    {
        use_count_ptr_ = ptr.use_count_ptr_;
        (*use_count_ptr_)++;
    }

    int use_count()
    {
        return *use_count_ptr_;
    }
private:
    T* ptr_;
    int* use_count_ptr_;
};

int main()
{
    shared_ptr<int> my_null_ptr;
    shared_ptr<int> my_ptr(new int(1));
    shared_ptr<int> my_ptr2(my_ptr);
    std::cout << my_ptr.use_count();
    // *my_ptr = 2;
    return 0;
}