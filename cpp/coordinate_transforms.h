#ifndef _COORDINATE_TRANSFORMS_H_
#define _COORDINATE_TRANSFORMS_H_

using std::vector;
constexpr double pi();
double deg2rad(double x);
double rad2deg(double x);

double distance(double x1, double y1, double x2, double y2);

int ClosestWaypoint(double x, double y, const vector<double> &maps_x, const vector<double> &maps_y);

// Transform from Cartesian x,y coordinates to Frenet s,d coordinates
vector<double> getFrenet(double x, double y, const vector<double> &maps_x, const vector<double> &maps_y);

#endif
