
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

#ifndef GLOBAL_H
#define GLOBAL_H

#include "misc.h"

struct globals {
// We used the same prior at every location, but POMSolver::solve
// takes as parameter a vector of priors if you want
static   scalar_t global_prior;// = 0.01;

// The parameters of the Normal law for the conditional image density,
// given the true state. Mu does not appear in the paper, sigma does.
static   scalar_t global_mu_image_density;// = 0.0;
static   scalar_t global_sigma_image_density;// = 0.01;

// When we iterate the solver, we smooth the estimate to prevent from
// oscillating effects that tend to appear naturally
static   scalar_t global_smoothing_coefficient;// = 0.8;

// Ugly parameters for defining the convergence of the solver. I guess
// there are far better ways to do

// Hard bound on the number of iterations
static   int global_max_nb_solver_iterations;// = 100;

// What error is considered acceptable
static   scalar_t global_error_max;// = 1e-4;

// How many steps under the global_error_max defines convergence
static   int global_nb_stable_error_for_convergence;// = 5;

// If the probability of absence is greated than that, ignore the
// avatar in the computation of the average image to save computation
static   scalar_t global_proba_ignored;// = 1.00;
};

#endif
