//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gazta�aga 2004-2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2001-2003
// William E. Kempf
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee,
// provided that the above copyright notice appear in all copies and
// that both that copyright notice and this permission notice appear
// in supporting documentation.  William E. Kempf makes no representations
// about the suitability of this software for any purpose.
// It is provided "as is" without express or implied warranty.

#ifndef BOOST_INTERPROCESS_TEST_UTIL_HEADER
#define BOOST_INTERPROCESS_TEST_UTIL_HEADER
/*
#include <boost/thread/xtime.hpp>
#include <boost/thread/interprocess_mutex.hpp>
#include <boost/thread/interprocess_condition.hpp>
#include <boost/thread/thread.hpp>
*/

#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>

#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#ifndef DEFAULT_EXECUTION_MONITOR_TYPE
#   define DEFAULT_EXECUTION_MONITOR_TYPE execution_monitor::use_condition
#endif

namespace boost {
namespace interprocess {
namespace test {

inline void sleep(const boost::posix_time::ptime &xt)
{
   boost::interprocess::interprocess_mutex mx;
   boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex>
      lock(mx);
   boost::interprocess::interprocess_condition cond;
   cond.timed_wait(lock, xt);
}

inline boost::posix_time::ptime delay(int secs, int msecs=0, int nsecs = 0)
{
   using namespace boost::posix_time;
   int count = static_cast<int>(double(nsecs)*
               (double(time_duration::ticks_per_second())/double(1000000000.0)));
   return   microsec_clock::universal_time() + 
            boost::posix_time::time_duration(0, 0, secs, count);
}

inline bool in_range(const boost::posix_time::ptime& xt, int secs=1)
{
    boost::posix_time::ptime min = delay(-secs);
    boost::posix_time::ptime max = delay(0);
    return (xt > min) && (max > xt);
}

boost::xtime xsecs(int secs)
{
   boost::xtime ret;
   boost::xtime_get(&ret, boost::TIME_UTC);
   ret.sec += secs;
   return ret;
}

template <typename P>
class thread_adapter
{
   public:
   thread_adapter(void (*func)(void*, P &), void* param1, P &param2)
      : _func(func), _param1(param1) ,_param2(param2){ }
   void operator()() const { _func(_param1, _param2); }

   private:
   void (*_func)(void*, P &);
   void* _param1;
   P& _param2;
};

template <typename P>
struct data
{
   data(int id, int secs=0)
      : m_id(id), m_value(-1), m_secs(secs)
   {}
   int m_id;
   int m_value;
   int m_secs;
};

static int shared_val = 0;
static const int BaseSeconds = 1;

}  //namespace test {
}  //namespace interprocess {
}  //namespace boost {

#endif   //#ifndef BOOST_INTERPROCESS_TEST_UTIL_HEADER
