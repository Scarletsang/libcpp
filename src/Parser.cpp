/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:03:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/19 00:56:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcpp/Parser.hpp"

#include <iostream>

namespace libcpp
{
  Parser::Parser()
    : input_(std::cin) {}

  Parser::Parser(std::istream& stream)
    : input_(stream) {}

  Parser::Parser(const Parser& other)
    : input_(other.input_), positions_(other.positions_) {}

  Parser::~Parser() {}

  void  Parser::snapshot()
  {
    positions_.push(input_.tellg());
  }

  void  Parser::rollback()
  {
    if (positions_.empty())
      return ;
    input_.seekg(positions_.top());
    positions_.pop();
  }
} // namespace libcpp
