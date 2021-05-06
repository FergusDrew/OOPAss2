#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Utils
{
  public:
      static std::string GetLineFromUser();
      static char GetCharFromUser();
      static std::string CastToPrice(int price);
      static std::string CastToCredit(const int credits);
    // TODO: 2 versions of ToUpper
};