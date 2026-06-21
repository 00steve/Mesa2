#include "../include/quaternion.h"

double quaternion::magnitude(){
    return std::sqrt(w*w + x*x + y*y + z*z);
}

double* quaternion::matrix(){
    double m[16];
    m[0] = 1-2*y*y-2*z*z;   m[1] = 2*x*y-2*w*z;     m[2] = 2*x*z+2*w*y;     m[3] = 0;
    m[4] = 2*x*y+2*w*z;     m[5] = 1-2*x*x-2*z*z;   m[6] = 2*y*z+2*w*x;     m[7] = 0;
    m[8] = 2*x*z-2*w*y;     m[9] = 2*y*z-2*w*x;     m[10] = 1-2*x*x-2*y*y;  m[11] = 0;
    m[12] = 0;              m[13] = 0;              m[14] = 0;              m[15] = 1;
    return m;
}

void quaternion::normalize(){
    double m = magnitude();
    w /= m;
    x /= m;
    y /= m;
    z /= m;
}

quaternion::quaternion(){
    w = 1;
    x = 0;
    y = 0;
    z = 0;
}

quaternion::quaternion(double w, double x, double y, double z) : 
        w(w), x(x), y(y), z(z) {
}

quaternion quaternion::operator * (const quaternion o){
    return quaternion(
        w*o.w - x*o.x - y*o.y - z*o.z,
        w*o.x + x*o.w + y*o.z - z*o.y,
        w*o.y - x*o.z + y*o.w + z*o.x,
        w*o.z + x*o.y - y*o.x + z*o.w
    );
}

void quaternion::rotateX(double angle){

}

void quaternion::rotateY(double angle){

}

void quaternion::rotateZ(double angle){

}

quaternion quaternion::slerp(quaternion a, quaternion b, double t){
	quaternion m;
	double cosHalfTheta = a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
	if (std::abs(cosHalfTheta) >= 1.0){
		m.w = a.w;m.x = a.x;m.y = a.y;m.z = a.z;
		return m;
	}
	double halfTheta = std::acos(cosHalfTheta);
	double sinHalfTheta = std::sqrt(1.0 - cosHalfTheta*cosHalfTheta);
	if (std::fabs(sinHalfTheta) < 0.001){ 
		m.w = (a.w * 0.5 + b.w * 0.5);
		m.x = (a.x * 0.5 + b.x * 0.5);
		m.y = (a.y * 0.5 + b.y * 0.5);
		m.z = (a.z * 0.5 + b.z * 0.5);
		return m;
	}
	double ratioA = std::sin((1 - t) * halfTheta) / sinHalfTheta;
	double ratioB = std::sin(t * halfTheta) / sinHalfTheta; 
	m.w = (a.w * ratioA + b.w * ratioB);
	m.x = (a.x * ratioA + b.x * ratioB);
	m.y = (a.y * ratioA + b.y * ratioB);
	m.z = (a.z * ratioA + b.z * ratioB);
	return m;
}

quaternion quaternion::slerp(quaternion a, quaternion b, double min, double max, double t){
    return slerp(a, b, t-min / (max-min));
}