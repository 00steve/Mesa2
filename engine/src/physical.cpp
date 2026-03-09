#include "../include/physical.h"

double3 Physical::gravity = double3(0,-9.81,0);

Collision Physical::AABBIntersection(AABB aabb0, AABB aabb1){
    Collision c;
    /*double3 d = double3(
        aabb0.min.x > aabb1.max.x || aabb0.max.x < aabb1.min.x ? 

    );*/
    return c;
}

double3 Physical::Gravity(){
    return gravity;
}

double3 Physical::Gravity(double3 newGravity){
    return gravity = newGravity;
}

Physical::Physical(){
}

//https://copyprogramming.com/howto/intersection-between-line-and-triangle-in-3d
Collision Physical::TriangleLineSegmentIntersection(double3 l0, double3 l1, double3 t0, double3 t1, double3 t2) {
    double3 e0 = t1 - t0;
    double3 e1 = t2 - t0;
    double3 dir = l1 - l0;
    double3 dir_norm = dir.getNormalized();
    double3 h = dir_norm.cross(e1);
    const double a = e0.dot(h);
    if(a > -EPSILON && a < EPSILON){
        return Collision();
    }
    double3 s = l0 - t0;
    const double f = 1 / a;
    const double u = f * s.dot(h);
    if(u < 0 || u > 1){
        return Collision();
    }
    double3 q = s.cross(e0);
    const double v = f * dir_norm.dot(q);
    if(v < 0 || u + v > 1){
        return Collision();
    }
    const double t = f * e1.dot(q);
    const double sq = sqrt(dir.dot(dir));
    if(t <= EPSILON || t >= sq){
        return Collision();
    }
    Collision c;
    c.Point(l0 + dir_norm * t);
    return c;
}

//https://realtimecollisiondetection.net/blog/?p=103
Collision Physical::TriangleSphereIntersection(double3 p, double r, double3 t0, double3 t1, double3 t2) {

    double3 a = t0 - p;
    double3 b = t1 - p;
    double3 c = t2 - p;
    //std::cout << "a (" << a.x << " and " << a.y << " and " << a.z << ")\n";
    //std::cout << "b (" << b.x << " and " << b.y << " and " << b.z << ")\n";
    //std::cout << "c (" << c.x << " and " << c.y << " and " << c.z << ")\n";
    double3 ba = b - a;
    double3 ca = c - a;
    //std::cout << "b-a (" << ba.x << " and " << ba.y << " and " << ba.z << ")\n";
    //std::cout << "c-a (" << ca.x << " and " << ca.y << " and " << ca.z << ")\n";
    double3 v = double3::cross(b - a,c - a);
    //std::cout << "cross(ba,ca) (" << v.x << " and " << v.y << " and " << v.z << ")\n";
    double d = double3::dot(a,v);
    double e = double3::dot(v,v);
    //std::cout << "d: " << d << "\ne: " << e << "\nr: " << r << "\n";
    bool sepl = d * d > r * r * e;
    if(sepl){
        std::cout << "different planes!\n";
        return Collision();
    }

    double aa = double3::dot(a,a);
    double ab = double3::dot(a,b);
    double ac = double3::dot(a,c);
    double bb = double3::dot(b,b);
    double bc = double3::dot(b,c);
    double cc = double3::dot(c,c);
    double rr = r * r;

    //std::cout << "seperated: " << (aa > rr) << " and " << (ab > aa) << " and " << (ac > aa) << "\n";
    //std::cout << "seperated: " << (bb > rr) << " and " << (ab > bb) << " and " << (bc > bb) << "\n";
    //std::cout << "seperated: " << (cc > rr) << " and " << (ac > cc) << " and " << (bc > cc) << "\n";

    bool sepa = (aa > rr) && (ab > aa) && (ac > aa);
    bool sepb = (bb > rr) && (ab > bb) && (bc > bb);
    bool sepc = (cc > rr) && (ac > cc) && (bc > cc);
    bool seperated = sepa || sepb || sepc;
    if(seperated){
        std::cout << "crossing plane, but not intersecting vertices!\n";
        return Collision();
    }

    double3 dab = b - a;
    double3 dbc = c - b;
    double3 dca = a - c;
    double d1 = double3::dot(a,dab);
    double e1 = double3::dot(dab,dab);
    double d2 = double3::dot(b,dbc);
    double e2 = double3::dot(dbc,dbc);
    double d3 = double3::dot(c,dca);
    double e3 = double3::dot(dca,dca);
    double3 q1 = a * e1 - dab * d1;
    double3 qc = c * e1 - q1;
    double3 q2 = b * e2 - dbc * d2;
    double3 qa = a * e2 - q2;
    double3 q3 = c * e3 - dca * d3;
    double3 qb = b * e3 - q3;
    sepa = (double3::dot(q1,q1) > rr * e1 * e1) && (double3::dot(q1,qc) > 0);
    sepb = (double3::dot(q2,q2) > rr * e2 * e2) && (double3::dot(q2,qa) > 0);
    sepc = (double3::dot(q3,q3) > rr * e3 * e3) && (double3::dot(q3,qb) > 0);
    seperated = sepa || sepb || sepc;
    if(seperated){
        std::cout << "not intersecting edges\n";
        return Collision();
    }

    std::cout << "definitely intersecting\n";
    
    Collision col;
    //col.Point(double3(0,0,0));
    return col;
}