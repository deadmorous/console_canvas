#include <iostream>

#include "console_canvas/Box.h"
#include "console_canvas/Shape.h"
#include "console_canvas/shapes/Circle.h"

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
    try {
        // Kaka::Registrator KakaRegistrator("kaka");
        // TODO

        using namespace ctm;
        Box b;
        b << Point(1,2) << Point(10,5);

        auto x = Shape::newInstance("kaka");

        auto c = std::make_shared<shapes::Circle>();
        c->read(cin);

        cout << b << endl;
        cout << "Hello World!" << endl;
        return 0;
    }
    catch(const std::exception& e) {
        cerr << "ERROR: " << e.what() << endl;
        return 1;
    }
}

