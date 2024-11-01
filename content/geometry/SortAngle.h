/**
 * Author: Simon Lindholm
 * Date: 2015-01-31
 * License: CC0
 * Source: me
 * Description: Sort the points in counter-clockwise order w.r.t a given point
 * Status: Used, works well
 */
#pragma once

#include "Point.h"
typedef Point<ll> P;

bool ccw(const P &pivot, const P &a, const P &b) {
    // >= 0 if accept collinear
    return (a - pivot).cross(b - pivot) > 0;
}

vector <P> ccwOrder(vector <P> &v, P &pivot) {
    int n = sz(v);
    vector <P> up, down;
    rep(i, 0, n) {
        if(v[i].y > pivot.y || (v[i].y == pivot.y && v[i].x > pivot.x)) up.push_back(v[i]);
        else down.push_back(v[i]);
    }

    auto cmpCCW = [&](const P &u, const P &v) {
        return ccw(pivot, u, v);
    }

    sort(all(up), cmpCCW);
    sort(all(down), cmpCCW);
    vector <P> cur = up;
    cur.insert(cur.end(), all(down));
    return cur;
}