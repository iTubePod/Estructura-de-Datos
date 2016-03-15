/*
   Gilberto Echeverria

   Class for a 3D vector, consisting of coordinates in X, Y, Z
*/


class Vector3D {
    private:
        double x;
        double y;
        double z;
    public:
        // Constructors
        Vector3D () {}
        Vector3D (double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}//llama el contrsuctor de la clase papa
        // Operators
        Vector3D operator + (const Vector3D & other);
        Vector3D operator - (const Vector3D & other);
        void operator = (const Vector3D & other);
        bool operator == (const Vector3D & other);
        friend std::ostream& operator<< (std::ostream& stream, const Vector3D& vector3d);
        // Access methods
        double getX() { return this->x; }
        double getY() { return this->y; }
        double getZ() { return this->z; }
        void setX(double _x) { x = _x; }
        void setY(double _y) { y = _y; }
        void setZ(double _z) { z = _z; }
};

/*
   Vector addition
*/
Vector3D Vector3D::operator + (const Vector3D & other)
{
    Vector3D result;
    result.x = x + other.x;
    result.y = y + other.y;
    result.z = z + other.z;
    return result;
}

/*
   Vector substraction
*/
Vector3D Vector3D::operator - (const Vector3D & other)
{
    Vector3D result;
    result.x = x - other.x;
    result.y = y - other.y;
    result.z = z - other.z;
    return result;
}

/*
   Vector comparison
*/
bool Vector3D::operator == (const Vector3D & other)
{
    return (x == other.x && y == other.y && z == other.z);
}

/*
   Vector assignment
*/
void Vector3D::operator = (const Vector3D & other)
{
    x = other.x;
    y = other.y;
    z = other.z;
}

/*
    Overload for output stream operator.
    Based on the example at:
    http://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
*/
std::ostream& operator << (std::ostream &out, const Vector3D &vector3d)
{
    // Since operator<< is a friend of the Point class, we can access
    // Point's members directly.
    out << "(" << vector3d.x << ", " << vector3d.y << ", " << vector3d.z << ")";
    return out;
}
