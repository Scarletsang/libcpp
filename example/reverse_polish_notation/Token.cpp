/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:38:07 by htsang            #+#    #+#             */
/*   Updated: 2023/11/19 00:32:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token()
  : is_operator_(false)
{
  data_.number = 0;
}

Token::Token(int number)
  : is_operator_(false)
{
  data_.number = number;
}

Token::Token(char op)
  : is_operator_(true)
{
  data_.op = op;
}

Token::Token(Token const& other)
  : data_(other.data_), is_operator_(other.is_operator_) {}

Token::~Token() {}

Token& Token::operator=(Token const& other)
{
  data_ = other.data_;
  is_operator_ = other.is_operator_;
  return *this;
}

bool  Token::is_operator() const
{
  return is_operator_;
}

int   Token::number() const
{
  return data_.number;
}

char  Token::op() const
{
  return data_.op;
}

bool  Token::operator==(Token const& other) const
{
  if (is_operator_ != other.is_operator_)
    return false;
  else if (is_operator_)
    return data_.op == other.data_.op;
  else
    return data_.number == other.data_.number;
}
