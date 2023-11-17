/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Maybe.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:45:13 by htsang            #+#    #+#             */
/*   Updated: 2023/11/17 23:04:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAYBE_HPP
# define MAYBE_HPP

# include "Nothing.hpp"

namespace libcpp
{
  template <typename T>
  class Maybe
  {
    public:
      Maybe();
      Maybe(const Nothing value);
      Maybe(const T& value);
      Maybe(const Maybe& other);
      ~Maybe();
      Maybe& operator=(const Maybe& other);

      bool  is_ok() const;
      T     value() const;

      //////////////////////////////////////////
      ////////////   Maybe monads   ////////////
      //////////////////////////////////////////

      template <typename T2>
      Maybe<T2> chain(Maybe<T2> (*f)()) const;

      template <typename T2>
      Maybe<T2> chain(Maybe<T2> (*f)(T)) const;

      template <typename T2, typename Env>
      Maybe<T2> chain(Maybe<T2> (*f)(Env), Env data) const;

      template <typename T2, typename Env>
      Maybe<T2> chain(Maybe<T2> (*f)(Env&), Env& data) const;

      template <typename T2, typename Env>
      Maybe<T2> chain(Maybe<T2> (*f)(T, Env), Env data) const;

      template <typename T2, typename Env>
      Maybe<T2> chain(Maybe<T2> (*f)(T, Env&), Env& data) const;

    private:
      T     value_;
      bool  is_ok_;
  };

  /////////////////////////////////////////////////////
  ////////////   template implementation   ////////////
  /////////////////////////////////////////////////////

  template <typename T>
  Maybe<T>::Maybe()
    : value_(), is_ok_(false) {}
  
  template <typename T>
  Maybe<T>::Maybe(const Nothing value)
    : value_(), is_ok_(false) {}
  
  template <typename T>
  Maybe<T>::Maybe(const T& value)
    : value_(value), is_ok_(true) {}
  
  template <typename T>
  Maybe<T>::Maybe(const Maybe& other)
    : value_(other.value_), is_ok_(other.is_ok_) {}
  
  template <typename T>
  Maybe<T>::~Maybe() {}

  template <typename T>
  Maybe<T>& Maybe<T>::operator=(const Maybe& other)
  {
    if (this != &other)
    {
      this->value_ = other.value_;
      this->is_ok_ = other.is_ok_;
    }
    return *this;
  }

  template <typename T>
  bool  Maybe<T>::is_ok() const
  {
    return this->is_ok_;
  }

  template <typename T>
  T     Maybe<T>::value() const
  {
    return this->value_;
  }

  //////////////////////////////////////////
  ////////////   Maybe monads   ////////////
  //////////////////////////////////////////

  template <typename T>
  template <typename T2>
  Maybe<T2> Maybe<T>::chain(Maybe<T2> (*f)()) const
  {
    if (this->is_ok())
      return f();
    return Nothing();
  }

  template <typename T>
  template <typename T2>
  Maybe<T2> Maybe<T>::chain(Maybe<T2> (*f)(T)) const
  {
    if (this->is_ok())
      return f(this->value());
    return Nothing();
  }

  template <typename T>
  template <typename T2, typename Env>
  Maybe<T2> Maybe<T>::chain(Maybe<T2> (*f)(Env), Env data) const
  {
    if (this->is_ok())
      return f(data);
    return Nothing();
  }

  template <typename T>
  template <typename T2, typename Env>
  Maybe<T2> Maybe<T>::chain(Maybe<T2> (*f)(Env&), Env& data) const
  {
    if (this->is_ok())
      return f(data);
    return Nothing();
  }

  template <typename T>
  template <typename T2, typename Env>
  Maybe<T2> Maybe<T>::chain(Maybe<T2> (*f)(T, Env), Env data) const
  {
    if (this->is_ok())
      return f(this->value(), data);
    return Nothing();
  }

} // namespace libcpp

#endif