#pragma once

#include <stdexcept>

namespace Vector2{
struct Vector2_d{
    double X;
    double Y;

    double NormSquared();
    double Norm();
    double Dot(const Vector2_d&);

    Vector2_d& SetX(double);
    Vector2_d& SetY(double);
    Vector2_d& Normalize();
    Vector2_d& operator +=(const Vector2_d& Vec)
    {
        X += Vec.X;
        Y += Vec.Y;
        return *this;
    }
    Vector2_d& operator -=(const Vector2_d& Vec)
    {
        X -= Vec.X;
        Y -= Vec.Y;
        return *this;
    }
    Vector2_d& operator *=(const double& Scalar)
    {
        X *= Scalar;
        Y *= Scalar;
        return *this;
    }
    Vector2_d& operator *=(const Vector2_d Vec)
    {
        X *= Vec.X;
        Y *= Vec.Y;
        return *this;
    }
    Vector2_d& operator /=(const double& Scalar)
    {
        if (Scalar == 0)
        {
            throw std::runtime_error("Division by zero");
        }
        X /= Scalar;
        Y /= Scalar;
        return *this;
    }

    Vector2_d GetPerp();
};

inline Vector2_d operator +(const Vector2_d& Left, const Vector2_d& Right)
{
    return {Left.X + Right.X, Left.Y + Right.Y};
}
inline Vector2_d operator -(const Vector2_d& Left, const Vector2_d& Right)
{
    return {Left.X - Right.X, Left.Y - Right.Y};
}
inline Vector2_d operator *(const Vector2_d& Vec, double Scalar)
{
    return {Vec.X * Scalar, Vec.Y * Scalar};
}
inline Vector2_d operator *(const Vector2_d& Left, const Vector2_d& Right)
{
    return {Left.X * Right.X, Left.Y * Right.Y};
}
inline Vector2_d operator /(const Vector2_d& Vec, double Scalar)
{
    return {Vec.X / Scalar, Vec.Y / Scalar};
}
}

using Vec2 = Vector2::Vector2_d;

