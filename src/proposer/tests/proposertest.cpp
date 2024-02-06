#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>
#include <vector>

static std::vector<std::string> split(std::string delim, std::string text) {
  std::vector<std::string> res;
  size_t pos = 0;
  size_t last = 0;
  std::string token;
  while ((pos = text.find(delim, last)) != std::string::npos) {
    token = text.substr(last, pos - last);
    last = pos + delim.length();
    res.push_back(token);
  }

  token = text.substr(last);
  res.push_back(token);
  return res;
}

TEST_CASE("split string test") {
  std::string text = "42:1000,value";
  std::string delim = ",";
  std::vector<std::string> result = split(delim, text);
  for (std::string str : result)
    std::cout << str << std::endl;
  std::string cmp1 = "42:1000";
  std::string cmp2 = "value";
  CHECK(result[0] == cmp1);
  CHECK(result[1] == cmp2);
  delim = ":";
  text = result[0];
  result = split(delim, text);
  for (std::string str : result)
    std::cout << str << std::endl;
  cmp1 = "42";
  cmp2 = "1000";
  CHECK(result[0] == cmp1);
  CHECK(result[1] == cmp2);
};
