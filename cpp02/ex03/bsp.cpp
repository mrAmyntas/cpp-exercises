#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

	//Set some readable variables
	Fixed a_x = a.get_x();
	Fixed a_y = a.get_y();
	Fixed b_x = b.get_x();
	Fixed b_y = b.get_y();
	Fixed c_x = c.get_x();
	Fixed c_y = c.get_y();
	Fixed point_x = point.get_x();
	Fixed point_y = point.get_y();
	Fixed dydx;
	Fixed dxdy;
	Fixed y_diff;
	Fixed x_diff;
	Fixed intersect_x_1;
	Fixed intersect_x_2;
	Fixed intersect_x_3;
	Fixed intersect_y_1;
	Fixed intersect_y_2;
	Fixed intersect_y_3;
	bool ab = false;
	bool ac = false;
	bool bc = false;

	// is point_y crossed by lines a->b a->c or b->c?
	//a->b
	if (a_y != b_y)
	{
		if ((a_y > point_y && point_y > b_y) || (a_y < point_y && point_y < b_y))
		{
			if (a_x != b_x)
			{
				dydx = (Fixed::max(a_y, b_y) - Fixed::min(a_y, b_y)) / (Fixed::max(a_x, b_x) - Fixed::min(a_x, b_x));
				y_diff = a_y - point_y;
				x_diff = y_diff / dydx;
				intersect_x_1 = a_x + x_diff;
			}
			else
				intersect_x_1 = a_x;
			ab = true;
		}
	}
	//a->c
	if (a_y != c_y)
	{
		if ((a_y > point_y && point_y > c_y) || (a_y < point_y && point_y < c_y))
		{
			if (a_x != c_x)
			{
				dydx = (Fixed::max(a_y, c_y) - Fixed::min(a_y, c_y)) / (Fixed::max(a_x, c_x) - Fixed::min(a_x, c_x));
				y_diff = a_y - point_y;
				x_diff = y_diff / dydx;
				intersect_x_2 = a_x + x_diff;
			}
			else
				intersect_x_2 = a_x;
			ac = true;
		}
	}
	//b->c
	if (b_y != c_y)
	{
		if ((b_y > point_y && point_y > c_y) || (b_y < point_y && point_y < c_y))
		{
			if (b_x != c_x)
			{
				dydx = (Fixed::max(b_y, c_y) - Fixed::min(b_y, c_y)) / (Fixed::max(b_x, c_x) - Fixed::min(b_x, c_x));
				y_diff = b_y - point_y;
				x_diff = y_diff / dydx;
				intersect_x_3 = b_x + x_diff;
			}
			else
				intersect_x_3 = b_x;
			bc = true;
		}
	}
	if (!ab && !ac && !bc)
		return (false);
	if (ab && ac)
	{
		if ((Fixed::min(intersect_x_1, intersect_x_2) >= point_x) || (point_x >= Fixed::max(intersect_x_1, intersect_x_2)))
			return (false);
	}
	if (ab && bc)
	{
		if ((Fixed::min(intersect_x_1, intersect_x_3) >= point_x) || (point_x >= Fixed::max(intersect_x_1, intersect_x_3)))
			return (false);
	}
	if (ac && bc)
	{
		if ((Fixed::min(intersect_x_2, intersect_x_3) >= point_x) || (point_x >= Fixed::max(intersect_x_2, intersect_x_3)))
			return (false);
	}
	// is point_x crossed by lines a->b a->c or b->c?
	ab = false;
	ac = false;
	bc = false;
	if (a_x != b_x)
	{
		if ((a_x > point_x && point_x > b_x) || (a_x < point_x && point_x < b_x))
		{
			if (a_y != b_y)
			{
				dxdy = (Fixed::max(a_x, b_x) - Fixed::min(a_x, b_x)) / (Fixed::max(a_y, b_y) - Fixed::min(a_y, b_y));
				x_diff = a_x - point_x;
				y_diff = x_diff / dxdy;
				intersect_y_1 = a_y + y_diff;
			}
			else
				intersect_y_1 = a_y;
			ab = true;
		}
	}
	if (a_x != c_x)
	{
		if ((a_x > point_x && point_x > c_x) || (a_x < point_x && point_x < c_x))
		{
			if (a_y != c_y)
			{
				dxdy = (Fixed::max(a_x, c_x) - Fixed::min(a_x, c_x)) / (Fixed::max(a_y, c_y) - Fixed::min(a_y, c_y));
				x_diff = a_x - point_x;
				y_diff = x_diff / dxdy;
				intersect_y_2 = a_y + y_diff;
			}
			else
				intersect_y_2 = a_y;
			ac = true;
		}
	}
	if (b_x != c_x)
	{
		if ((b_x > point_x && point_x > c_x) || (b_x < point_x && point_x < c_x))
		{
			if (a_y != b_y)
			{
				dxdy = (Fixed::max(b_x, c_x) - Fixed::min(b_x, c_x)) / (Fixed::max(b_y, c_y) - Fixed::min(b_y, c_y));
				x_diff = b_x - point_x;
				y_diff = x_diff / dxdy;
				intersect_y_3 = b_y + y_diff;
			}
			else
				intersect_y_3 = b_y;
			ac = true;
		}
	}
	if (!ab && !ac && !bc)
		return (false);
	if (ab && ac)
	{
		if ((Fixed::min(intersect_y_1, intersect_y_2) > point_y) || (point_y > Fixed::max(intersect_y_1, intersect_y_2)))
			return (false);
	}
	if (ab && bc)
	{
		if ((Fixed::min(intersect_y_1, intersect_y_3) > point_y) || (point_y > Fixed::max(intersect_y_1, intersect_y_3)))
			return (false);
	}
	if (ac && bc)
	{
		if ((Fixed::min(intersect_y_2, intersect_y_3) > point_y) || (point_y > Fixed::max(intersect_y_2, intersect_y_3)))
			return (false);
	}
	return (true);
}
// if y value of point is within range of min - max of x values of abc of that specific y height