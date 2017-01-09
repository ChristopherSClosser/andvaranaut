#pragma once

#include <stdbool.h>
#include <stdint.h>

struct point
{
    double x, y;
};

double
geom_mag(const struct point point);

double
geom_epercent(const struct point point, uint8_t** enclosure);

struct point
geom_cast(const struct point hero, const double radians, uint8_t** enclosure);

bool
geom_ecoll(const struct point point, uint8_t** enclosure);

int
geom_etile(const struct point point, uint8_t** enclosure);

int
geom_rtile(const struct point point);

int
geom_ctile(const struct point point);

int
geom_ftile(const struct point point);

bool
geom_in(const struct point point);

bool
geom_out(const struct point point);

static inline struct point
geom_sub(const struct point i, const struct point j)
{
    return (struct point){ i.x - j.x, i.y - j.y };
}

static inline struct point
geom_add(const struct point i, const struct point j)
{
    return (struct point){ i.x + j.x, i.y + j.y };
}

static inline struct point
geom_mul(const struct point i, const double n)
{
    return (struct point){ i.x * n, i.y * n };
}

static inline double
geom_mod(const double d)
{
    return d - (int)d;
}
