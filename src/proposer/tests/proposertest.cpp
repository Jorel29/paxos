#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>
#include <vector>

typedef struct {
  int proposal;
  int id;
} proposal_round;

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
// data format "ip:port,id:round,value"
int extract_data(std::string &data, proposal_round &proposal,
                 std::string &value) {
  std::string temp(data);
  std::string delim(",");
  // extract ip:port,id:round,value
  std::vector<std::string> result = split(delim, temp);
  if (result.size() > 2)
    value = result[2].data();
  delim = ":";
  // if result[1] exists
  std::vector<std::string> prop = split(delim, result[1]);

  proposal.id = std::stoi(prop[0]);
  proposal.proposal = std::stoi(prop[1]);
  return 0;
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

TEST_CASE("extract data functional") {
  std::string data = "42:1000,2:1,value";
  std::string value = "";
  std::string cmp1 = "value";
  proposal_round cmp_round;
  cmp_round.id = 2;
  cmp_round.proposal = 1;
  proposal_round test_round;
  test_round.id = 0;
  test_round.proposal = 0;

  extract_data(data, test_round, value);

  CHECK(value == cmp1);
  CHECK(test_round.id == cmp_round.id);
  CHECK(test_round.proposal == cmp_round.proposal);
};
