/**
 * @date Tue Apr 2 13:00:00 2013 +0200
 * @author Laurent El Shafey <Laurent.El-Shafey@idiap.ch>
 *
 * Copyright (C) Idiap Research Institute, Martigny, Switzerland
 */

#ifndef BOB_CORE_ARRAY_RANDOM_H
#define BOB_CORE_ARRAY_RANDOM_H

#include <blitz/array.h>
#include <bob.core/random.h>

namespace bob { namespace core { namespace array {
/**
 * @ingroup CORE_ARRAY
 * @{
 */

/**
 * @brief Fills in a blitz++ array with random numbers generated by a normal
 * distribution. The array should be of type float or double.
 * @warning Because of the use of the blitz iterator, the array is filled in
 * according to the memory order.
 * @warning Please note that we rely on boost rather than blitz++ ranlib
 * because of design considerations.
 */
template <typename T, int N>
void randn(boost::mt19937& rng, blitz::Array<T,N>& dest,
  const T mean=0., const T var=1.)
{
  bob::core::random::normal_distribution<T> distrib(mean, var);
  typedef typename blitz::Array<T,N>::iterator BA_iterator;
  for (BA_iterator it=dest.begin(); it !=dest.end(); ++it)
    *it = distrib(rng);
}

/**
 * @}
 */
}}}

#endif /* BOB_CORE_ARRAY_RANDOM_H */
