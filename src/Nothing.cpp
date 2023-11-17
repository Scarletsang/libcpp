/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nothing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:42:31 by htsang            #+#    #+#             */
/*   Updated: 2023/11/17 23:13:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Nothing.hpp"

libcpp::Nothing::Nothing() {}

libcpp::Nothing::Nothing(const Nothing& other) { (void) other; }

libcpp::Nothing::~Nothing() {}

libcpp::Nothing& libcpp::Nothing::operator=(const Nothing& other)
{
  (void) other;
  return *this;
}

bool  libcpp::Nothing::operator==(const Nothing& other) const
{
  (void) other;
  return true;
}
