/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:31:10 by htsang            #+#    #+#             */
/*   Updated: 2023/11/19 00:09:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Token
{
  public:
    Token();
    Token(int number);
    Token(char op);
    Token(Token const& other);
    Token& operator=(Token const& other);
    ~Token();

    bool  is_operator() const;
    int   number() const;
    char  op() const;

    bool  operator==(Token const& other) const;

  private:
    union Data
    {
      int   number;
      char  op;
    }     data_;
    bool  is_operator_;
};
