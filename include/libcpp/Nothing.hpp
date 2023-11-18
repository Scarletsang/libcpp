/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nothing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:39:59 by htsang            #+#    #+#             */
/*   Updated: 2023/11/18 19:35:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCPP_NOTHING_HPP
# define LIBCPP_NOTHING_HPP

namespace libcpp
{
  class Nothing
  {
    public:
      Nothing();
      Nothing(const Nothing& other);
      ~Nothing();
      Nothing& operator=(const Nothing& other);

      bool  operator==(const Nothing& other) const;

      template <typename T>
      bool  operator==(const T& other) const;
  };

  template <typename T>
  bool  Nothing::operator==(const T& other) const
  {
    (void) other;
    return false;
  }
} // namespace libcpp

#endif
