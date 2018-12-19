// This source file is part of the polarphp.org open source project
//
// Copyright (c) 2017 - 2018 polarphp software foundation
// Copyright (c) 2017 - 2018 zzu_softboy <zzu_softboy@163.com>
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://polarphp.org/LICENSE.txt for license information
// See https://polarphp.org/CONTRIBUTORS.txt for the list of polarphp project authors
//
// Created by polarboy on 2018/12/18.

#include "Utils.h"
#include <cctype>

namespace polar {

std::size_t php_format_date(char* str, std::size_t count, const char* format,
                            time_t ts, bool localtime)
{
   /// TODO modify for multithread
   std::tm tm;
   std::tm *tempTm;
   if (localtime) {
      tempTm = std::localtime(&ts);
   } else {
      tempTm = std::gmtime(&ts);
   }
   tm = *tempTm;
   return std::strftime(str, count, format, &tm);
}

char *php_strtolower(char *s, size_t len)
{
   unsigned char *c;
   const unsigned char *e;

   c = (unsigned char *)s;
   e = c+len;

   while (c < e) {
      *c = std::tolower(*c);
      c++;
   }
   return s;
}

char *php_strtoupper(char *s, size_t len)
{
   unsigned char *c;
   const unsigned char *e;

   c = (unsigned char *)s;
   e = (unsigned char *)c+len;

   while (c < e) {
      *c = toupper(*c);
      c++;
   }
   return s;
}

} // utils