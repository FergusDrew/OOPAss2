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
      static std::string toUpperOne(std::string caps);
      static std::string toUpperTwo(std::string caps, int temp);
      int randomrangeNum(int& rrnum);
      static std::string fullplayTime(int time, std::string& playtime);
};