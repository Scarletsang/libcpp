/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:44:25 by htsang            #+#    #+#             */
/*   Updated: 2023/11/19 00:06:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

Error::Error() : code_(kInvalidToken) {}

Error::Error(Error::Code code) : code_(code) {}

Error::Error(Error const& other) : code_(other.code_) {}

Error::~Error() {}

Error& Error::operator=(Error const& other)
{
  if (this == &other)
    return *this;
  code_ = other.code_;
  return *this;
}

Error::Code Error::code() const
{
  return code_;
}

std::ostream& operator<<(std::ostream& os, Error const& error)
{
  os << "Error: " << error.code();
  return os;
}
