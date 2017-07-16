#ifndef VEC_HPP
# define VEC_HPP

template <class T>
class vec2
{
public:
	T x, y;

	vec2(): x(0), y(0) {}
	vec2(T x, T y): x(x), y(y) {}
	vec2(const vec2& v): x(v.x), y(v.y) {}

	vec2& operator=(const vec2& v) {
		x = v.x;
		y = v.y;
		return (*this);
	}
	vec2& operator+(vec2& v) {
		return (vec2(x + v.x, y + v.y));
	}
	vec2& operator-(vec2& v) {
		return (vec2(x - v.x, y - v.y));
	}
	vec2 operator+(double d) {
		return vec2(x + d, y + d);
	}
	vec2 operator-(double d) {
		return vec2(x - d, y - d);
	}
};

template <class T>
class vec3
{
public:
	T x, y, z;

	vec3() : x(0), y(0), z(0) {}
	vec3(T x, T y, T z): x(x), y(y), z(z) {}
	vec3(const vec2<T>&v, T z): x(v.x), y(v.y), z(z) {}
	vec3(T x, const vec2<T>&v): x(x), y(v.x), z(v.y) {}
	vec3(const vec3& v): x(v.x), y(v.y), z(v.z) {}

	vec3& operator=(const vec3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return (*this);
	}
	vec3& operator+(vec3& v) {
		return (vec3(x + v.x, y + v.y, z + v.z));
	}
	vec3& operator-(vec3& v) {
		return (vec3(x - v.x, y - v.y, z - v.z));
	}
	vec3 operator+(double d) {
		return vec3(x + d, y + d, z + d);
	}
	vec3 operator-(double d) {
		return vec3(x - d, y - d, z - d);
	}
};

template <class T>
class vec4
{
public:
	T x, y, z, w;

	vec4() : x(0), y(0), z(0), w(0) {}
	vec4(T x, T y, T z): x(x), y(y), z(z), w(w) {}
	vec4(const vec2<T>&v, T z, T w): x(v.x), y(v.y), z(z), w(w) {}
	vec4(const vec3<T>&v, T w): x(v.x), y(v.y), z(v.z), w(w) {}
	vec4(T x, const vec2<T>&v, T w): x(x), y(v.x), z(v.y), w(w) {}
	vec4(T x, T y, const vec2<T>&v): x(x), y(y), z(v.x), w(v.y) {}
	vec4(T x, const vec3<T>&v): x(x), y(v.x), z(v.y), w(v.z) {}
	vec4(const vec4& v): x(v.x), y(v.y), z(v.z), w(v.w) {}

	vec4& operator=(const vec4& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		z = v.w;
		return (*this);
	}
	vec4& operator+(vec4& v) {
		return (vec4(x + v.x, y + v.y, z + v.z, w + v.w));
	}
	vec4& operator-(vec4& v) {
		return (vec4(x - v.x, y - v.y, z - v.z, w - v.w));
	}
	vec4 operator+(double d) {
		return vec4(x + d, y + d, z + d, w + d);
	}
	vec4 operator-(double d) {
		return vec4(x - d, y - d, z - d, w - d);
	}
};

typedef vec2<int> int2;
typedef vec2<float> float2;
typedef vec2<double> double2;

typedef vec3<int> int3;
typedef vec3<float> float3;
typedef vec3<double> double3;

typedef vec4<int> int4;
typedef vec4<float> float4;
typedef vec4<double> double4;

#endif
