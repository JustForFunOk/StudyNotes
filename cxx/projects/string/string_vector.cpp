#include <iostream>
#include <memory>
#include <vector>
#include <cstring>

using namespace std;

namespace test
{

class string
{
public:
    // constructor
    string() = default;
    string(const string& _str)
    {
        str_ = _str.str_;
    }
    string(const char* _str_ptr)
    {
        str_.resize(strlen(_str_ptr));
        for(int i = 0; i < strlen(_str_ptr); ++i)
        {
            str_[i] =  _str_ptr[i];
        }
    }
    // operator
    string& operator=(const string& _str)
    {
        str_.clear();
        str_ = _str.str_;
        return *this;
    }
    string& operator=(const char* _str_ptr)
    {
        str_.clear();
        str_ = string(_str_ptr).str_;
        return *this;
    }
    // function
    unsigned int size()
    {
        return str_.size();
    }
private:
    std::vector<char> str_;
};

} // namespace test

int main()
{
    test::string str;
    test::string str0("Init string");
    test::string str1(str0);

    str = str0;
    str = "Init string";

    return 0;
}