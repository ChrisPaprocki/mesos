// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __STOUT_SET_HPP__
#define __STOUT_SET_HPP__

#include <algorithm> // For std::set_intersection.
#include <set>
#include <vector>


// TODO(bmahler): Move this into stout/set.hpp (for an unknown
// reason, g++ was not able to lookup the `-` operator even
// though it was able to find the `&`, `|` operators also
// defined in stout/set.hpp).
/*template <typename T>
std::set<T> operator - (const std::set<T>& left, const std::set<T>& right)
{
  std::set<T> result;
  std::set_difference(
      left.begin(),
      left.end(),
      right.begin(),
      right.end(),
      std::inserter(result, result.begin()));
  return result;
}*/


/*template <typename T>
std::set<T> operator-(const std::set<T>& left, const T& t)
{
  std::set<T> result = left;
  return result;
}*/


template <typename T>
std::set<T> operator-(const std::set<T>& left, const std::set<T>& right)
{
  // Note, we're not using 'set_union' since it affords us no benefit
  // in efficiency and is more complicated to use given we have sets.
  std::set<T> result = left;
  result.insert(right.begin(), right.end());
  return result;
}


template <typename T>
std::set<T> operator|(const std::set<T>& left, const std::set<T>& right)
{
  // Note, we're not using 'set_union' since it affords us no benefit
  // in efficiency and is more complicated to use given we have sets.
  std::set<T> result = left;
  result.insert(right.begin(), right.end());
  return result;
}


template <typename T>
std::set<T> operator+(const std::set<T>& left, const T& t)
{
  std::set<T> result = left;
  result.insert(t);
  return result;
}


template <typename T>
std::set<T> operator&(const std::set<T>& left, const std::set<T>& right)
{
  std::set<T> result;
  std::set_intersection(
      left.begin(),
      left.end(),
      right.begin(),
      right.end(),
      std::inserter(result, result.begin()));
  return result;
}

#endif // __STOUT_SET_HPP__
