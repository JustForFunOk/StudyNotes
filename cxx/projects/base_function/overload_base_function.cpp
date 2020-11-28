#include <iostream>

using namespace std;

class Rectangle
{
public:
    explicit Rectangle(int _l, int _w)
    {
        cout << "constructor" << endl;
        length = _l;
        width = _w;
    }
    ~Rectangle()
    {
        cout << "destructor" << endl;
    }
    Rectangle(const Rectangle& _rect)
    {
        cout << "copy constructor" << endl;
        length = _rect.length;
        width = _rect.width;
    }
    Rectangle& operator=(const Rectangle& _rect)
    {
        cout << "copy assign operator" << endl;
        length = _rect.length;
        width = _rect.width;
        return *this;
    }
    Rectangle(Rectangle&& _rect) noexcept
    {
        cout << "move constructor" << endl;
        length = _rect.length;
        width = _rect.width;
    }
    Rectangle& operator=(Rectangle&& _rect) noexcept
    {
        cout << "move assign operator" << endl;
        length = _rect.length;
        width = _rect.width;
        return * this;
    }
private:
    int length;
    int width;
};

int main()
{
    Rectangle rect1(6, 6);
    Rectangle rect2(rect1);
    Rectangle rect3 = rect1;

    Rectangle rect4(8, 8);
    rect3 = rect4;
    rect3.operator=(rect4);

    (rect3 = rect4) = rect1;
    rect3.operator=(rect4).operator=(rect1);

    Rectangle rect5(move(rect1));
    rect5 = move(rect4);

    return 0;
}