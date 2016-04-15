#pragma once

#include "SomeBox.h"

class ShippingOrder
{
private:
	SomeBox m_box;
	double m_postage;
public:
	ShippingOrder(SomeBox b, double postage)
		: m_box(b), m_postage(postage)
	{};
	SomeBox getProduct()
	{
		return m_box;
	}
	~ShippingOrder();
};

