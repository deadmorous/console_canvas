#include <iostream>

#include "console_canvas/Box.h"
#include "console_canvas/Shape.h"

using namespace std;
using namespace ctm;

class Kaka :
    public Shape,
    public FactoryMixin<Kaka, Shape>
{
public:
    Kaka() { cout << "Kaka::Kaka" << endl; }
    ~Kaka() { cout << "Kaka::~Kaka" << endl; }
    void paint(Canvas&) const override {}
    Box boundingBox() const override { return Box(); }
    void write(std::ostream& s) const override {}
    void read(std::istream& s) override {}
};

CTM_REGISTER_TYPE(Kaka, "kaka")
// static Kaka::Registrator TheKakaRegistrator("kaka");

int main()
{
    // TODO

    using namespace ctm;
    Box b;
    b << Point(1,2) << Point(10,5);

    auto x = Shape::newInstance("kaka");

    cout << b << endl;
    cout << "Hello World!" << endl;
    return 0;
}

