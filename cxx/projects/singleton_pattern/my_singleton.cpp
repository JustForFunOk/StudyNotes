#include <iostream>

class Singleton
{
public:
    static Singleton& getSingleton()
    {
        static Singleton singleton;
        return singleton;
    }

    static Singleton* getSingletonPtr()
    {
        return &getSingleton();
    }

    void print_log()
    {
        std::cout << "Singleton" << std::endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;
    Singleton& operator=(const Singleton&&) = delete;
private:
    Singleton()
    {
    }
};

int main()
{
    Singleton& singleton = Singleton::getSingleton();
    Singleton* singleton_ptr = Singleton::getSingletonPtr();
    // Singleton singleton;
    singleton_ptr->print_log();
    singleton.print_log();
    return 0;
}