#include <stdexcept>
#include <cmath>
#include "Vector2.h"

double Vector2::Vector2_d::NormSquared()
{
    return X * X + Y * Y;
}
double Vector2::Vector2_d::Norm()
{
    return std::sqrt(NormSquared());
}
double Vector2::Vector2_d::Dot(const Vector2::Vector2_d& Vec)
{
    return X * Vec.X + Y * Vec.Y;
}
Vector2::Vector2_d& Vector2::Vector2_d::SetX(double X)
{
    this -> X = X;
    return *this;
}
Vector2::Vector2_d& Vector2::Vector2_d::SetY(double Y)
{
    this -> Y = Y;
    return *this;
}
Vector2::Vector2_d& Vector2::Vector2_d::Normalize()
{
    double Len = Norm();
    if (Len == 0)
    {
        throw std::runtime_error("Division by zero");
    }
    this -> X /= Len;
    this -> Y /= Len;
    return *this;
}
Vector2::Vector2_d Vector2::Vector2_d::GetPerp()
{
    return {-Y, X};
}
