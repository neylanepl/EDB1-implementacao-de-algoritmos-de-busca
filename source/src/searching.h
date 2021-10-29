/*!
 * A simple implementation of the following algorithms for array of integers:
 *  + linear search
 *  + upper bound
 *  + lower bound
 *  + binary search
 *
 * \file searching.h
 * \author Neylane Lopes
 * \date June 22th, 2021.
 */

#ifndef SEARCHING_H
#define SEARCHING_H

#include <iterator>

/// Searching Algorithms Namespace
namespace sa {

    /// just an alias for an integer type.
    using value_type = int;

    /// Linear search.
    value_type * lsearch( value_type * first, value_type * last, value_type value );

    /// Binary search.
    value_type * bsearch( value_type * first, value_type * last, value_type value );

    /// Binary search recursive.
    value_type * bsearchR( value_type * first, value_type * last, value_type value );

    /// Lower bound.
    value_type * lbound( value_type * first, value_type * last, value_type value );

    /// Upper bound.
    value_type * ubound( value_type * first, value_type * last, value_type value );
}

#endif // SEARCHING_H
