#ifndef COLOR_H
#define COLOR_H

#include "def_prop_class.h"

namespace ctm {

using Color = char;

CTM_DEF_PROP_CLASS(WithColor, Color, Color, color, setColor)

} // namespace ctm

#endif // COLOR_H
