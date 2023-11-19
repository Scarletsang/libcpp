/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:54:09 by htsang            #+#    #+#             */
/*   Updated: 2023/11/19 00:59:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>

RPN::RPN() : Parser() {}

RPN::RPN(std::istream& stream) : Parser(stream) {}

RPN::RPN(RPN const& other)
  : Parser(other), stack_(other.stack_) {}

RPN::~RPN() {}

RPN::ParserResult RPN::parse()
{
  ErrorTrace  trace;
  TokenResult result = stream_is_end().chain(&RPN::parse_token, *this, trace);
  while (result.is_ok())
    result = stream_is_end().chain(&RPN::parse_token, *this, trace);
  return result.chain(&RPN::parse_valid, *this, trace);
}

RPN::ParserResult RPN::parse_valid(ErrorTrace& trace)
{
  switch (stack_.size())
  {
    case 0:
      trace.push(Error::kStackIsEmpty);
      return ParserResult::Error(trace);
    case 1:
      if (stack_.top().is_operator())
      {
        trace.push(Error::kExpectedNumber);
        return ParserResult::Error(trace);
      }
      break;
    default:
      trace.push(Error::kStackHasMoreThanOneElement);
      return ParserResult::Error(trace);
  }
  return ParserResult::Ok(stack_.top().number());
}

RPN::TokenResult RPN::parse_token(ErrorTrace& trace)
{
  return parse_int()
    .otherwise(&RPN::parse_operator, *this)
    .otherwise(&RPN::accumulate_error_traces, *this, trace);
}

RPN::TokenResult RPN::parse_int()
{
  int number;
  if (!(input_ >> number))
    return TokenResult::Error(ErrorTrace(Error::kExpectedNumber));
  stack_.push(Token(number));
  return TokenResult::Ok(stack_.top());
}

// TODO
RPN::TokenResult RPN::parse_operator()
{
  return TokenResult::Ok(stack_.top());
}

RPN::NoResult RPN::parse_spaces()
{
  char c;
  while (input_ >> c && c == ' ')
    ;
  return NoResult::Ok(libcpp::Nothing());
}

RPN::NoResult RPN::stream_is_end()
{
  if (input_.eof())
    return NoResult::Error(ErrorTrace());
  return NoResult::Ok(libcpp::Nothing());
}

RPN::TokenResult   RPN::accumulate_error_traces(const ErrorTrace& new_trace, ErrorTrace& final_trace)
{
  final_trace.push(new_trace);
  return TokenResult::Error(final_trace);
}
