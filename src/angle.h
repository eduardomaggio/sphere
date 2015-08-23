// Copyright (c) 2015 Eduardo Gomes Ribeiro Maggio
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#define _USE_MATH_DEFINES

#include <math.h>

namespace maggio
{

// converts angle magnitude from Degree to Radians
#define DEG2RAD(A) (A*M_PI/180.0)

// converts angle magnitude from Radians to Degrees
#define RAD2DEG(A) (A*180.0*M_1_PI)

// some definitions 

#define DEGREE_FULL_ARC (360.0)
#define DEGREE_HALF_ARC (180.0)

#define RADIAN_FULL_ARC (M_PI*2.0)
#define RADIAN_HALF_ARC (M_PI)


// general wrap
inline double NormalizeAngle( 
  double angle, 
  const double offset,
  const double full_arc,
  const double half_arc)
  {
    double resp = fmod(angle,full_arc) + offset;
    if ( resp < 0 )
      resp += full_arc;
    return resp - offset;
  }


// wrap angle (deg) to the interval [0, 360.0)
inline double UnsignedAngleDeg( double angle )
{
  return NormalizeAngle(
    angle,
    0,
    DEGREE_FULL_ARC,
    DEGREE_HALF_ARC);
}


// wrap angle (deg) to the interval [-180.0, 180.0)
inline double NormalizeAngleDeg( double angle )
{
  return NormalizeAngle(
    angle,
    -DEEGREE_HALF_ARC,
    DEGREE_FULL_ARC,
    DEGREE_HALF_ARC);
}


// wrap angle (rad) to the interval [0, 2PI)
inline double UnsignedAngleRad( double angle )
{
  return NormalizeAngle(
    angle,
    0,
    RADIAN_FULL_ARC,
    RADIAN_HALF_ARC);
}


// wrap angle (rad) to the interval [-PI, PI)
inline double NormalizeAngleRad( double angle )
{
  return NormalizeAngle(
    angle,
    -RADIAN_HALF_ARC,
    RADIAN_FULL_ARC,
    RADIAN_HALF_ARC);
}
