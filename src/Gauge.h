#pragma once

#include "Point.h"
#include "Input.h"
#include "Weapon.h"

typedef struct
{
    int count;
    int max;
    Point* points;
    int mx;
    int my;
}
Gauge;

Gauge xgnew();

void xgfree(const Gauge);

Gauge xgwind(Gauge, const Weapon, const Input);
