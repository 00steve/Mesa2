#ifndef UTIL_Int2
#define UTIL_Int2

class int2 {
public:
    int x;
    int y;
    
    int2();
    int2(int x, int y);

    /*order by: 
        operator type ==, !=, *, /, +, - 
        parameter type int2, int
    */
    bool operator == (const int2 other);
    bool operator != (const int2 other);
    int2 operator + (const int2 other);
    int2 operator - (const int2 other);

    bool operator == (const int other);
    bool operator != (const int other);
    int2 operator * (const int other);
    int2 operator / (const int other);
    int2 operator + (const int other);
    int2 operator - (const int other);
};

#endif