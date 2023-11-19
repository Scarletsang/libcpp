/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:57:22 by htsang            #+#    #+#             */
/*   Updated: 2023/11/19 00:47:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Token.hpp"
#include "Error.hpp"

#include <stack>

#include "libcpp/Parser.hpp"
#include "libcpp/Nothing.hpp"
#include "libcpp/Result.hpp"
#include "libcpp/parser/ErrorTrace.hpp"

class RPN : public libcpp::Parser
{
  public:
    typedef libcpp::ErrorTrace<Error> ErrorTrace;
    typedef libcpp::Result<int, ErrorTrace> ParserResult;
    typedef libcpp::Result<Token, ErrorTrace> TokenResult;
    typedef libcpp::Result<libcpp::Nothing, ErrorTrace> NoResult;

    RPN();
    RPN(std::istream& stream);
    RPN(RPN const& other);
    ~RPN();

    ParserResult  parse();

  private:
    std::stack<Token> stack_;

    ParserResult  parse_valid(ErrorTrace& trace);

    TokenResult   parse_token(ErrorTrace& trace);
    TokenResult   parse_int();
    TokenResult   parse_operator();

    NoResult      parse_spaces();
    NoResult      stream_is_end();

    TokenResult   accumulate_error_traces(const ErrorTrace& new_trace, ErrorTrace& final_trace);

    RPN& operator=(RPN const& other);
};
