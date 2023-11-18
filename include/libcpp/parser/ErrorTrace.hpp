/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorTrace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:02:19 by htsang            #+#    #+#             */
/*   Updated: 2023/11/19 00:55:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCPP_ERRORTRACE_HPP
# define LIBCPP_ERRORTRACE_HPP

# include <stack>
# include <vector>
# include <iostream>

namespace libcpp
{
  template <typename Err>
  class ErrorTrace
  {
    public:
      ErrorTrace();
      ErrorTrace(const Err error);
      ErrorTrace(const ErrorTrace& other);
      virtual ~ErrorTrace();
      ErrorTrace& operator=(const ErrorTrace& other);

      void  push(const Err error);
      void  push(const ErrorTrace& error_trace);
      bool  is_empty() const;
      Err   pop();

    private:
      std::stack<Err, std::vector<Err> > trace_;
  };

  /////////////////////////////////////////////////////
  ////////////   template implementation   ////////////
  /////////////////////////////////////////////////////

  template <typename Err>
  ErrorTrace<Err>::ErrorTrace() {}

  template <typename Err>
  ErrorTrace<Err>::ErrorTrace(const Err error)
  {
    trace_.push(error);
  }

  template <typename Err>
  ErrorTrace<Err>::ErrorTrace(const ErrorTrace& other)
    : trace_(other.trace_) {}
  
  template <typename Err>
  ErrorTrace<Err>::~ErrorTrace() {}

  template <typename Err>
  ErrorTrace<Err>& ErrorTrace<Err>::operator=(const ErrorTrace& other)
  {
    if (this == &other)
      return *this;
    trace_ = other.trace_;
    return *this;
  }

  template <typename Err>
  void  ErrorTrace<Err>::push(const Err error)
  {
    trace_.push(error);
  }

  template <typename Err>
  void  ErrorTrace<Err>::push(const ErrorTrace& error_trace)
  {
    std::stack<Err, std::vector<Err> >  copy = error_trace.trace_;
    std::stack<Err, std::vector<Err> >  tmp;
    while (!copy.empty())
    {
      tmp.push(copy.top());
      copy.pop();
    }
    while (!tmp.empty())
    {
      trace_.push(tmp.top());
      tmp.pop();
    }
  }

  template <typename Err>
  bool  ErrorTrace<Err>::is_empty() const
  {
    return trace_.empty();
  }

  template <typename Err>
  Err  ErrorTrace<Err>::pop()
  {
    Err error = trace_.top();
    trace_.pop();
    return error;
  }

  template <typename Err>
  std::ostream& operator<<(std::ostream& os, const ErrorTrace<Err>& error_trace)
  {
    while (!error_trace.trace_.empty())
    {
      os << error_trace.trace_.top() << std::endl;
      error_trace.trace_.pop();
    }
    return os;
  }

} // namespace libcpp

#endif
