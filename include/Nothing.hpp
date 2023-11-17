/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nothing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:39:59 by htsang            #+#    #+#             */
/*   Updated: 2023/11/17 20:44:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTHING_HPP
# define NOTHING_HPP

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
    return false;
  }
} // namespace libcpp

#endif