/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nothing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:42:31 by htsang            #+#    #+#             */
/*   Updated: 2023/11/17 20:44:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Nothing.hpp"

libcpp::Nothing::Nothing() {}

libcpp::Nothing::Nothing(const Nothing& other) {}

libcpp::Nothing::~Nothing() {}

libcpp::Nothing& libcpp::Nothing::operator=(const Nothing& other)
{
  return *this;
}

bool  libcpp::Nothing::operator==(const Nothing& other) const
{
  return true;
}
