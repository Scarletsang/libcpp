/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:43:30 by htsang            #+#    #+#             */
/*   Updated: 2023/11/19 00:08:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Error
{
  public:
    typedef enum {
      kInvalidToken = 1,
      kExpectedNumber,
      kExpectedOperator,
      kStackIsEmpty,
      kStackHasMoreThanOneElement
    } Code;
    Error();
    Error(Code code);
    Error(Error const& other);
    ~Error();

    Error& operator=(Error const& other);

    Code code() const;
  
  private:
    Code code_;
};

std::ostream& operator<<(std::ostream& os, Error const& error);
