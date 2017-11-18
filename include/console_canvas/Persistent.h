#ifndef PERSISTENT_H
#define PERSISTENT_H

#include "console_canvas/defs.h"
#include <istream>
#include <ostream>

namespace ctm {

class CONSOLE_CANVAS_API Persistent
{
public:
    virtual ~Persistent() {}

    // TODO EG: Implement everywhere
    virtual void write(std::ostream& s) const = 0;
    virtual void read(std::istream& s) = 0;
};

} // namespace ctm

#endif // PERSISTENT_H
