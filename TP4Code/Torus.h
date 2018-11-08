#if !defined(TORUS)
#define TORUS

#include "PrimitiveAbs.h"

class Torus : public PrimitiveAbs
{
public:

	Torus(const Point3D& pt, float ir, float or );
	virtual ~Torus();
	virtual Torus* clone() const;

	virtual size_t getNbParameters() const;
	virtual PrimitiveParams getParameters() const;
	virtual void setParameter(size_t index, float pValue);

private:
	virtual std::ostream& toStream(std::ostream& o) const;
	float m_dimensions[2];

};

#endif