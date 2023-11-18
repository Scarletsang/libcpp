/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:33:10 by htsang            #+#    #+#             */
/*   Updated: 2023/11/19 00:33:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCPP_PARSER_HPP
# define LIBCPP_PARSER_HPP

#include "Result.hpp"
#include "Nothing.hpp"

#include <istream>
#include <stack>
#include <vector>

namespace libcpp
{
  class Parser
  {
    public:
      Parser();
      Parser(std::istream& stream);
      Parser(const Parser& other);
      virtual ~Parser();

    protected:
      std::istream& input_;
      std::stack<std::streampos, std::vector<std::streampos> > positions_;

      virtual void  snapshot();
      virtual void  rollback();

    private:
      Parser& operator=(const Parser& other);
  };

  template <typename T, typename Err>
  Result<T,Err> Swap(T value, T* location)
  {
    *location = value;
    return Result<T,Err>::Ok(Nothing());
  }

  template <typename T, typename Err>
  Result<T, Err>  Return(T value)
  {
    return Result<T, Err>::Ok(value);
  }
} // namespace libcpp

#endif
