#include "Geometry.h"
#include <math.h>

namespace gamerize
{
  //Vector2

  float Vector2::Length()
  {
	  return sqrt(x*x + y*y);
  }

  Vector2 & Vector2::Normalize()
  {
	  float lenInv = 1.0f / Length();
	  x *= lenInv;
	  y *= lenInv;

	  return *this;
  }

  Vector2  Vector2::NormalizeM()
  {
	  float lenInv = 1.0f / Length();
	  int _x = x * lenInv;
	  int _y = y * lenInv;

	  return Vector2(_x, _y);
  }

  Vector2 Vector2::operator + (const Vector2 & vector)
  {
	  return Vector2(x + vector.x, y + vector.y);
  }

  Vector2 & Vector2::operator += (const Vector2 & vector)
  {
	  x += vector.x;
	  y += vector.y;

	  return *this;
  }

  Vector2 Vector2::operator - ()
  {
	  return Vector2(-x, -y);
  }

  Vector2 Vector2::operator - (const Vector2 & vector)
  {
	  return Vector2(x - vector.x, y - vector.y);
  }

  Vector2 & Vector2::operator -= (const Vector2 & vector)
  {
	  x -= vector.x;
	  y -= vector.y;

	  return *this;
  }

  Vector2 Vector2::operator * (float k)
  {
	  return Vector2(x * k, y * k);
  }

  Vector2 & Vector2::operator *= (float k)
  {
	  x *= k;
	  y *= k;

	  return *this;
  }

  Vector2 Vector2::operator / (float k)
  {
	  float kInv = 1.0f / k;
	  return Vector2(x * kInv, y * kInv);
  }

  Vector2 & Vector2::operator /= (float k)
  {
	  return operator *= (1.0f / k);
  }

  float Vector2::operator [] (unsigned int idx)
  {
	  return (&x)[idx];
  }

  Vector2 Vector2::Modulate(const Vector2 & vector)
  {
	  return Vector2(x * vector.x, y * vector.y);
  }

  float Vector2::Dot(const Vector2 & vector)
  {
	  return x * vector.x + y * vector.y;
  }

  void Vector2::Set(float x, float y)
  {
	  this->x = x;
	  this->y = y;
  }

  //Vector3

  float Vector3::Length()
  {
	  return sqrt(x*x + y*y + z*z);
  }

  Vector3 & Vector3::Normalize()
  {
	  float lenInv = 1.0f / Length();
	  x *= lenInv;
	  y *= lenInv;
	  z *= lenInv;

	  return *this;
  }

  Vector3 Vector3::operator + (const Vector3 & vector)
  {
	  return Vector3(x + vector.x, y + vector.y, z + vector.z);
  }

  Vector3 & Vector3::operator += (const Vector3 & vector)
  {
	  x += vector.x;
	  y += vector.y;
	  z += vector.z;

	  return *this;
  }

  Vector3 Vector3::operator - ()
  {
	  return Vector3(-x, -y, -z);
  }

  Vector3 Vector3::operator - (const Vector3 & vector)
  {
	  return Vector3(x - vector.x, y - vector.y, z - vector.z);
  }

  Vector3 & Vector3::operator -= (const Vector3 & vector)
  {
	  x -= vector.x;
	  y -= vector.y;
	  z -= vector.z;

	  return *this;
  }

  Vector3 Vector3::operator * (float k)
  {
	  return Vector3(x * k, y * k, z * k);
  }

  Vector3 & Vector3::operator *= (float k)
  {
	  x *= k;
	  y *= k;
	  z *= k;

	  return *this;
  }

  Vector3 Vector3::operator / (float k)
  {
	  float kInv = 1.0f / k;
	  return Vector3(x * kInv, y * kInv, z * kInv);
  }
  	
  Vector3 & Vector3::operator /= (float k)
  {
	  return operator *= (1.0f / k);
  }

  float Vector3::operator [] (unsigned int idx)
  {
	  return (&x)[idx];
  }

  Vector3 Vector3::Modulate(const Vector3 & vector)
  {
	  return Vector3(x * vector.x, y * vector.y, z * vector.z);
  }

  float Vector3::Dot(const Vector3 & vector)
  {
	  return x * vector.x + y * vector.y + z * vector.z;
  }

  Vector3 Vector3::Cross(const Vector3 & vector)
  {
	  return Vector3(y * vector.z -  z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
  }

  //Vector4

  float Vector4::Length()
  {
	  return sqrt(x*x + y*y + z*z + w*w);
  }

  Vector4 & Vector4::Normalize()
  {
	  float lenInv = 1.0f / Length();
	  x *= lenInv;
	  y *= lenInv;
	  z *= lenInv;
	  w *= lenInv;

	  return *this;
  }

  Vector4 Vector4::operator + (const Vector4 & vector)
  {
	  return Vector4(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
  }

  Vector4 & Vector4::operator += (const Vector4 & vector)
  {
	  x += vector.x;
	  y += vector.y;
	  z += vector.z;
	  w += vector.w;

	  return *this;
  }

  Vector4 Vector4::operator - ()
  {
	  return Vector4(-x, -y, -z, -w);
  }

  Vector4 Vector4::operator - (const Vector4 & vector)
  {
	  return Vector4(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
  }

  Vector4 & Vector4::operator -= (const Vector4 & vector)
  {
	  x -= vector.x;
	  y -= vector.y;
	  z -= vector.z;
	  w -= vector.w;

	  return *this;
  }

  Vector4 Vector4::operator * (float k)
  {
	  return Vector4(x * k, y * k, z * k, w * k);
  }

  Vector4 & Vector4::operator *= (float k)
  {
	  x *= k;
	  y *= k;
	  z *= k;
	  w *= k;

	  return *this;
  }

  Vector4 Vector4::operator / (float k)
  {
	  float kInv = 1.0f / k;
	  return Vector4(x * kInv, y * kInv, z * kInv, w * kInv);
  }

  Vector4 & Vector4::operator /= (float k)
  {
	  return operator *= (1.0f / k);
  }

  float Vector4::operator [] (unsigned int idx)
  {
	  return (&x)[idx];
  }

  Vector4 Vector4::Modulate(const Vector4 & vector)
  {
	  return Vector4(x * vector.x, y * vector.y, z * vector.z, w * vector.w);
  }

  float Vector4::Dot(const Vector4 & vector)
  {
	  return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
  }

  //Matrix 4 X 4

  Matrix::Matrix(float val)
  {
	  m[0][0] = val; m[0][1] = val; m[0][2] = val; m[0][3] = val;
	  m[1][0] = val; m[1][1] = val; m[1][2] = val; m[1][3] = val;
	  m[2][0] = val; m[2][1] = val; m[2][2] = val; m[2][3] = val;
	  m[3][0] = val; m[3][1] = val; m[3][2] = val; m[3][3] = val;
  }

  Matrix & Matrix::SetZero()
  {
	  m[0][0] = 0.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	  m[1][0] = 0.0f; m[1][1] = 0.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	  m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 0.0f; m[2][3] = 0.0f;
	  m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 0.0f;

	  return *this;
  }

  Matrix & Matrix::SetIdentity()
  {
	  m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	  m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	  m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	  m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;

	  return *this;
  }

  Matrix & Matrix::SetRotationX(float angle)
  {
	  float s = sinf(angle);
	  float c = cosf(angle);
	  m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	  m[1][0] = 0.0f; m[1][1] =    c; m[1][2] =    s; m[1][3] = 0.0f;
	  m[2][0] = 0.0f; m[2][1] =   -s; m[2][2] =    c; m[2][3] = 0.0f;
	  m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	  return *this;
  }

  Matrix & Matrix::SetRotationY(float angle)
  {
	  float s = sinf(angle);
	  float c = cosf(angle);
	  m[0][0] =    c; m[0][1] = 0.0f; m[0][2] =   -s; m[0][3] = 0.0f;
	  m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	  m[2][0] =    s; m[2][1] = 0.0f; m[2][2] =    c; m[2][3] = 0.0f;
	  m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	  return *this;
  }

  Matrix & Matrix::SetRotationZ(float angle)
  {
	  float s = sinf(angle);
	  float c = cosf(angle);
	  m[0][0] =    c; m[0][1] =    s; m[0][2] = 0.0f; m[0][3] = 0.0f;
	  m[1][0] =   -s; m[1][1] =    c; m[1][2] = 0.0f; m[1][3] = 0.0f;
	  m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	  m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	  return *this;
  }

  Matrix & Matrix::SetRotationAngleAxis( float angle, float x, float y, float z )
  {
	  float sinAngle, cosAngle;
	  float mag = sqrtf(x * x + y * y + z * z);

	  sinAngle = sinf ( angle );
	  cosAngle = cosf ( angle );
	  if ( mag > 0.0f )
	  {
		  float xx, yy, zz, xy, yz, zx, xs, ys, zs;
		  float oneMinusCos;
		  float magInv = 1.0f / mag;

		  x *= magInv;
		  y *= magInv;
		  z *= magInv;

		  xx = x * x;
		  yy = y * y;
		  zz = z * z;
		  xy = x * y;
		  yz = y * z;
		  zx = z * x;
		  xs = x * sinAngle;
		  ys = y * sinAngle;
		  zs = z * sinAngle;
		  oneMinusCos = 1.0f - cosAngle;

		  m[0][0] = (oneMinusCos * xx) + cosAngle;
		  m[1][0] = (oneMinusCos * xy) - zs;
		  m[2][0] = (oneMinusCos * zx) + ys;
		  m[3][0] = 0.0F; 

		  m[0][1] = (oneMinusCos * xy) + zs;
		  m[1][1] = (oneMinusCos * yy) + cosAngle;
		  m[2][1] = (oneMinusCos * yz) - xs;
		  m[3][1] = 0.0F;

		  m[0][2] = (oneMinusCos * zx) - ys;
		  m[1][2] = (oneMinusCos * yz) + xs;
		  m[2][2] = (oneMinusCos * zz) + cosAngle;
		  m[3][2] = 0.0F; 

		  m[0][3] = 0.0F;
		  m[1][3] = 0.0F;
		  m[2][3] = 0.0F;
		  m[3][3] = 1.0F;
		  return * this;
	  }
	  else
		  return SetIdentity();
  }


  Matrix & Matrix::SetScale(float scale)
  {
	  m[0][0] = scale; m[0][1] = 0.0f;  m[0][2] = 0.0f;  m[0][3] = 0.0f;
	  m[1][0] = 0.0f;  m[1][1] = scale; m[1][2] = 0.0f;  m[1][3] = 0.0f;
	  m[2][0] = 0.0f;  m[2][1] = 0.0f;  m[2][2] = scale; m[2][3] = 0.0f;
	  m[3][0] = 0.0f;  m[3][1] = 0.0f;  m[3][2] = 0.0f;  m[3][3] = 1.0f;

	  return *this;
  }

  Matrix & Matrix::SetScale(float scaleX, float scaleY, float scaleZ)
  {
	  m[0][0] = scaleX; m[0][1] = 0.0f;   m[0][2] = 0.0f;   m[0][3] = 0.0f;
	  m[1][0] = 0.0f;   m[1][1] = scaleY; m[1][2] = 0.0f;   m[1][3] = 0.0f;
	  m[2][0] = 0.0f;   m[2][1] = 0.0f;   m[2][2] = scaleZ; m[2][3] = 0.0f;
	  m[3][0] = 0.0f;   m[3][1] = 0.0f;   m[3][2] = 0.0f;   m[3][3] = 1.0f;
	  return *this;
  }

  Matrix & Matrix::SetScale(float * pScale)
  {
	  m[0][0] = pScale[0];   m[0][1] = 0.0f;        m[0][2] = 0.0f;        m[0][3] = 0.0f;
	  m[1][0] = 0.0f;        m[1][1] = pScale[1];   m[1][2] = 0.0f;        m[1][3] = 0.0f;
	  m[2][0] = 0.0f;        m[2][1] = 0.0f;        m[2][2] = pScale[2];   m[2][3] = 0.0f;
	  m[3][0] = 0.0f;        m[3][1] = 0.0f;        m[3][2] = 0.0f;        m[3][3] = 1.0f;
  	
	  return *this;
  }

  Matrix & Matrix::SetScale(const Vector3 & scaleVec)
  {
	  m[0][0] = scaleVec.x; m[0][1] = 0.0f;       m[0][2] = 0.0f;       m[0][3] = 0.0f;
	  m[1][0] = 0.0f;       m[1][1] = scaleVec.y; m[1][2] = 0.0f;       m[1][3] = 0.0f;
	  m[2][0] = 0.0f;       m[2][1] = 0.0f;       m[2][2] = scaleVec.z; m[2][3] = 0.0f;
	  m[3][0] = 0.0f;       m[3][1] = 0.0f;       m[3][2] = 0.0f;       m[3][3] = 1.0f;
  	
	  return *this;
  }

  Matrix & Matrix::SetTranslation(float x, float y, float z)
  {
	  m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	  m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	  m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	  m[3][0] =    x; m[3][1] =    y; m[3][2] =    z; m[3][3] = 1.0f;
  	
	  return *this;
  }

  Matrix & Matrix::SetTranslation( float *pTrans)
  {
	  m[0][0] = 1.0f;      m[0][1] = 0.0f;      m[0][2] = 0.0f;      m[0][3] = 0.0f;
	  m[1][0] = 0.0f;      m[1][1] = 1.0f;      m[1][2] = 0.0f;      m[1][3] = 0.0f;
	  m[2][0] = 0.0f;      m[2][1] = 0.0f;      m[2][2] = 1.0f;      m[2][3] = 0.0f;
	  m[3][0] = pTrans[0]; m[3][1] = pTrans[1]; m[3][2] = pTrans[2]; m[3][3] = 1.0f;
  	
	  return *this;
  }

  Matrix & Matrix::SetTranslation(const Vector3 &vec )
  {
	  m[0][0] =  1.0f; m[0][1] =  0.0f; m[0][2] =  0.0f; m[0][3] = 0.0f;
	  m[1][0] =  0.0f; m[1][1] =  1.0f; m[1][2] =  0.0f; m[1][3] = 0.0f;
	  m[2][0] =  0.0f; m[2][1] =  0.0f; m[2][2] =  1.0f; m[2][3] = 0.0f;
	  m[3][0] = vec.x; m[3][1] = vec.y; m[3][2] = vec.z; m[3][3] = 1.0f;
  	
	  return *this;
  }

  Matrix & Matrix::SetPerspective(float fovY, float aspect, float nearPlane, float farPlane)
  {
	  float height = 2.0f * nearPlane * tanf(fovY * 0.5f);
	  float width = height * aspect;
	  float n2 = 2.0f * nearPlane;
	  float rcpnmf = 1.f / (nearPlane - farPlane);

	  m[0][0] = n2 / width;	
	  m[1][0] = 0;
	  m[2][0] = 0;
	  m[3][0] = 0;

	  m[0][1] = 0;
	  m[1][1] = n2 / height;
	  m[2][1] = 0;
	  m[3][1] = 0;

	  m[0][2] = 0;
	  m[1][2] = 0;
	  m[2][2] = (farPlane + nearPlane) * rcpnmf;	
	  m[3][2] = farPlane * rcpnmf * n2;

	  m[0][3] = 0;
	  m[1][3] = 0;
	  m[2][3] = -1.f;
	  m[3][3] = 0;

	  return *this;
  }

  Matrix Matrix::Transpose()
  {
	  Matrix res;
	  res.m[0][0] = m[0][0]; res.m[0][1] = m[1][0]; res.m[0][2] = m[2][0]; res.m[0][3] = m[3][0];
	  res.m[1][0] = m[0][1]; res.m[1][1] = m[1][1]; res.m[1][2] = m[2][1]; res.m[1][3] = m[3][1];
	  res.m[2][0] = m[0][2]; res.m[2][1] = m[1][2]; res.m[2][2] = m[2][2]; res.m[2][3] = m[3][2];
	  res.m[3][0] = m[0][3]; res.m[3][1] = m[1][3]; res.m[3][2] = m[2][3]; res.m[3][3] = m[3][3];
	  return res;
  }

  Matrix Matrix::operator + (const Matrix & mat)
  {
	  Matrix res( *this );
	  res += mat;
	  return res;
  }

  Matrix & Matrix::operator += (const Matrix & mat)
  {
	  m[0][0] += mat.m[0][0]; m[0][1] += mat.m[0][1]; m[0][2] += mat.m[0][2]; m[0][3] += mat.m[0][3];
	  m[1][0] += mat.m[1][0]; m[1][1] += mat.m[1][1]; m[1][2] += mat.m[1][2]; m[1][3] += mat.m[1][3];
	  m[2][0] += mat.m[2][0]; m[2][1] += mat.m[2][1]; m[2][2] += mat.m[2][2]; m[2][3] += mat.m[2][3];
	  m[3][0] += mat.m[3][0]; m[3][1] += mat.m[3][1]; m[3][2] += mat.m[3][2]; m[3][3] += mat.m[3][3];

	  return *this;
  }

  Matrix Matrix::operator - (const Matrix & mat)
  {
	  Matrix res( *this );
	  res -= mat;
	  return res;
  }

  Matrix & Matrix::operator -= (const Matrix & mat)
  {
	  m[0][0] -= mat.m[0][0]; m[0][1] -= mat.m[0][1]; m[0][2] -= mat.m[0][2]; m[0][3] -= mat.m[0][3];
	  m[1][0] -= mat.m[1][0]; m[1][1] -= mat.m[1][1]; m[1][2] -= mat.m[1][2]; m[1][3] -= mat.m[1][3];
	  m[2][0] -= mat.m[2][0]; m[2][1] -= mat.m[2][1]; m[2][2] -= mat.m[2][2]; m[2][3] -= mat.m[2][3];
	  m[3][0] -= mat.m[3][0]; m[3][1] -= mat.m[3][1]; m[3][2] -= mat.m[3][2]; m[3][3] -= mat.m[3][3];

	  return *this;
  }

  Matrix Matrix::operator * (const Matrix & mat)
  {
	  Matrix res;
	  res.m[0][0] = m[0][0] * mat.m[0][0] + m[0][1] * mat.m[1][0] + m[0][2] * mat.m[2][0] + m[0][3] * mat.m[3][0];
	  res.m[0][1] = m[0][0] * mat.m[0][1] + m[0][1] * mat.m[1][1] + m[0][2] * mat.m[2][1] + m[0][3] * mat.m[3][1];
	  res.m[0][2] = m[0][0] * mat.m[0][2] + m[0][1] * mat.m[1][2] + m[0][2] * mat.m[2][2] + m[0][3] * mat.m[3][2];
	  res.m[0][3] = m[0][0] * mat.m[0][3] + m[0][1] * mat.m[1][3] + m[0][2] * mat.m[2][3] + m[0][3] * mat.m[3][3];

	  res.m[1][0] = m[1][0] * mat.m[0][0] + m[1][1] * mat.m[1][0] + m[1][2] * mat.m[2][0] + m[1][3] * mat.m[3][0];
	  res.m[1][1] = m[1][0] * mat.m[0][1] + m[1][1] * mat.m[1][1] + m[1][2] * mat.m[2][1] + m[1][3] * mat.m[3][1];
	  res.m[1][2] = m[1][0] * mat.m[0][2] + m[1][1] * mat.m[1][2] + m[1][2] * mat.m[2][2] + m[1][3] * mat.m[3][2];
	  res.m[1][3] = m[1][0] * mat.m[0][3] + m[1][1] * mat.m[1][3] + m[1][2] * mat.m[2][3] + m[1][3] * mat.m[3][3];

	  res.m[2][0] = m[2][0] * mat.m[0][0] + m[2][1] * mat.m[1][0] + m[2][2] * mat.m[2][0] + m[2][3] * mat.m[3][0];
	  res.m[2][1] = m[2][0] * mat.m[0][1] + m[2][1] * mat.m[1][1] + m[2][2] * mat.m[2][1] + m[2][3] * mat.m[3][1];
	  res.m[2][2] = m[2][0] * mat.m[0][2] + m[2][1] * mat.m[1][2] + m[2][2] * mat.m[2][2] + m[2][3] * mat.m[3][2];
	  res.m[2][3] = m[2][0] * mat.m[0][3] + m[2][1] * mat.m[1][3] + m[2][2] * mat.m[2][3] + m[2][3] * mat.m[3][3];

	  res.m[3][0] = m[3][0] * mat.m[0][0] + m[3][1] * mat.m[1][0] + m[3][2] * mat.m[2][0] + m[3][3] * mat.m[3][0];
	  res.m[3][1] = m[3][0] * mat.m[0][1] + m[3][1] * mat.m[1][1] + m[3][2] * mat.m[2][1] + m[3][3] * mat.m[3][1];
	  res.m[3][2] = m[3][0] * mat.m[0][2] + m[3][1] * mat.m[1][2] + m[3][2] * mat.m[2][2] + m[3][3] * mat.m[3][2];
	  res.m[3][3] = m[3][0] * mat.m[0][3] + m[3][1] * mat.m[1][3] + m[3][2] * mat.m[2][3] + m[3][3] * mat.m[3][3];

	  return res;
  }

  Matrix Matrix::operator * (float k)
  {
	  Matrix mat( *this );
	  mat *= k;
	  return mat;
  }

  Matrix & Matrix::operator *= (float k)
  {
	  m[0][0] *= k; m[0][1] *= k; m[0][2] *= k; m[0][3] *= k;
	  m[1][0] *= k; m[1][1] *= k; m[1][2] *= k; m[1][3] *= k;
	  m[2][0] *= k; m[2][1] *= k; m[2][2] *= k; m[2][3] *= k;
	  m[3][0] *= k; m[3][1] *= k; m[3][2] *= k; m[3][3] *= k;

	  return *this;
  }


  Vector4 Matrix::operator * (const Vector4 & vec)
  {
	  Vector4 res;
	  res.x = vec.x * m[0][0] + vec.y * m[1][0] + vec.z * m[2][0] + vec.w * m[3][0];
	  res.y = vec.x * m[0][1] + vec.y * m[1][1] + vec.z * m[2][1] + vec.w * m[3][1];
	  res.z = vec.x * m[0][2] + vec.y * m[1][2] + vec.z * m[2][2] + vec.w * m[3][2];
	  res.w = vec.x * m[0][3] + vec.y * m[1][3] + vec.z * m[2][3] + vec.w * m[3][3];

	  return res;
  }

};