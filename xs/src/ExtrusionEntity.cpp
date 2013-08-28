#include "ExtrusionEntity.hpp"

namespace Slic3r {

void
ExtrusionPath::reverse()
{
    this->polyline.reverse();
}

const Point*
ExtrusionPath::first_point() const
{
    return &(this->polyline.points.front());
}

const Point*
ExtrusionPath::last_point() const
{
    return &(this->polyline.points.back());
}

ExtrusionPath*
ExtrusionLoop::split_at_index(int index)
{
    Polyline* poly = this->polygon.split_at_index(index);
    
    ExtrusionPath* path = new ExtrusionPath();
    path->polyline      = *poly;
    path->role          = this->role;
    path->height        = this->height;
    path->flow_spacing  = this->flow_spacing;
    
    delete poly;
    return path;
}

ExtrusionPath*
ExtrusionLoop::split_at_first_point()
{
    return this->split_at_index(0);
}

bool
ExtrusionLoop::make_counter_clockwise()
{
    return this->polygon.make_counter_clockwise();
}

}
