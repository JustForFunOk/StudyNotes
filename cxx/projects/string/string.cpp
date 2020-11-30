#include <cstring>
#include <iostream>

namespace test
{

class string
{
public:
    string() : string_ptr_(nullptr), len_(0)
    {

    }
    ~string()
    {
        if(string_ptr_)
        {
            delete[] string_ptr_;
            string_ptr_ = nullptr;
        }
    }
    string(const char* _str_ptr)
    {
        string_ptr_ = new char[strlen(_str_ptr)];
        len_ = strlen(_str_ptr);
        for(int i = 0; i < strlen(_str_ptr); ++i)
        {
            string_ptr_[i] =  _str_ptr[i];
        }
    }
    string(const string& _str)
    {
        string_ptr_ = new char[_str.size()];
        for(int i = 0; i < len_; ++i)
        {
            string_ptr_[i] = _str.string_ptr_[i];
        }
    }
    // operator
    string& operator=(const string& _str)
    {
        // check size
        if(len_ < _str.len_)
        {
            unsigned int new_len = len_;
            if(string_ptr_)
            {
                while(new_len < _str.len_)
                {
                    new_len = new_len * 2;
                }
            }
            else
            {
                new_len = _str.len_;
            }
            // enlarge
            char* new_ptr = new char[new_len];
            // copy previous content
            for(int i = 0; i < len_; ++i)
            {
                new_ptr[i] = string_ptr_[i];
            }
            // release previous heap
            if(string_ptr_)
            {
                delete string_ptr_;
            }

            string_ptr_ = new_ptr;
            len_ = new_len;
        }
        else
        {
            len_ = _str.len_;
        }

        // replace previous content
        for(int i = 0; i < _str.len_; ++i)
        {
            string_ptr_[i] = _str.string_ptr_[i];
        }
        // copy content
        return *this;
    }
    char operator[](unsigned int _index)
    {
        return string_ptr_[_index];
    }

    // function
    unsigned int size() const
    {
        return len_;
    }

    friend std::ostream& operator<<(std::ostream& _out, string& _str)
    {
        _out<< _str.string_ptr_;
        return _out;
    }

private:
    char* string_ptr_;
    unsigned int len_;
};

} // namespace test

int main()
{
    test::string str;
    test::string str1("");
    test::string str2(str1);
    str = str1;
    std::cout << str << std::endl;

    return 0;
}