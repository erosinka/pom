#define BOOST_TEST_MODULE first
#include <boost/test/included/unit_test.hpp>

#include "rectangle.h"
#include "matrix.h"

BOOST_AUTO_TEST_CASE(rectangle)
{
    Rectangle obj;
    BOOST_CHECK_EQUAL(obj.visible, false);
    BOOST_CHECK_EQUAL(obj.xmin, 0);
    BOOST_CHECK_EQUAL(obj.ymin, 0);
    BOOST_CHECK_EQUAL(obj.xmax, 0);
    BOOST_CHECK_EQUAL(obj.ymax, 0);
}
BOOST_AUTO_TEST_CASE(matrix_obj)
{
//    Matrix<float> obj;
//    BOOST_CHECK_EQUAL(obj.get_width(), 0);
//    BOOST_CHECK_EQUAL(obj.get_height(), 0);
//    BOOST_CHECK_EQUAL(obj.content, 0);
//    BOOST_CHECK_EQUAL(obj.heads, 0);
}
