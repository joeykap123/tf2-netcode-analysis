#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "Position.h"

Position linearInterp(const Position& startPoint, const Position& endPoint, double time);

Position cubicHermiteInterp(const Position& startPoint, const Position& endPoint, const Position& tangentStart, const Position& tangentEnd, double time);


#endif interpolation_h