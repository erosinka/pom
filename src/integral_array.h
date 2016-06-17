
//////////////////////////////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify         //
// it under the terms of the version 3 of the GNU General Public License        //
// as published by the Free Software Foundation.                                //
//                                                                              //
// This program is distributed in the hope that it will be useful, but          //
// WITHOUT ANY WARRANTY; without even the implied warranty of                   //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU             //
// General Public License for more details.                                     //
//                                                                              //
// You should have received a copy of the GNU General Public License            //
// along with this program. If not, see <http://www.gnu.org/licenses/>.         //
//                                                                              //
// Written by Francois Fleuret                                                  //
// (C) Ecole Polytechnique Federale de Lausanne                                 //
// Contact <pom@epfl.ch> for comments & bug reports                             //
//////////////////////////////////////////////////////////////////////////////////

#ifndef INTEGRAL_Matrix_H
#define INTEGRAL_Matrix_H

#include <iostream>

using namespace std;

#include "Matrix.h"

template <class T>
class IntegralArray: public Matrix<T> {
public:

  void compute(const Matrix<T> *m) {
    T *v = Matrix<T>::content, *w = m->Matrix<T>::content;
    for(int x = 0; x < Matrix<T>::height; x++) *(v++) = 0;

    register T sl;
    for(int y = 1; y < Matrix<T>::width; y++) {
      sl = 0; *(v++) = 0;
      for(int x = 0; x < Matrix<T>::height - 1; x++) {
        sl += *(w++);
        *(v++) = sl + *(v - Matrix<T>::height);
      }
    }
  }

  IntegralArray(int w, int h) : Matrix<T>(w+1, h+1) { }

  IntegralArray(const Matrix<T> &m) : Matrix<T>(m->get_width() + 1, m->get_height() + 1) {
    compute(m);
  }

  // Integral on xmin <= x < xmax, ymin <= y < ymax
  // Thus, xmax and ymax can go up to m->width+1 and m->height+1 respectively

  inline T integral(int xmin, int ymin, int xmax, int ymax) const {
    ASSERT(xmin <= xmax && ymin <= ymax, "Inconsistent bounds for integral");
    ASSERT(xmin >= 0 && xmax < Matrix<T>::width &&
           ymin >= 0 && ymax < Matrix<T>::height, "Index out of bounds in Matrix::operator () const");
    return Matrix<T>::heads[xmax][ymax] + Matrix<T>::heads[xmin][ymin]
      - Matrix<T>::heads[xmax][ymin] - Matrix<T>::heads[xmin][ymax];
  }
};

#endif
