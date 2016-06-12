#define BOOST_TEST_MODULE first
#include <boost/test/included/unit_test.hpp>

#include "rectangle.h"

BOOST_AUTO_TEST_CASE(first)
{
    Rectangle obj;
    BOOST_CHECK_EQUAL(obj.visible, false);
    BOOST_CHECK_EQUAL(obj.xmin, 0);
    BOOST_CHECK_EQUAL(obj.ymin, 0);
    BOOST_CHECK_EQUAL(obj.xmax, 0);
    BOOST_CHECK_EQUAL(obj.ymax, 0);
}

