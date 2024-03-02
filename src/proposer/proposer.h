#ifndef PROPOSER_H
#define PROPOSER_H
#include <string>
typedef struct {
  int proposal;
  int id;
} proposal_round;

class Proposer {
public:
  Proposer();
  Proposer(Proposer &&) = default;
  Proposer(const Proposer &) = default;
  Proposer &operator=(Proposer &&) = default;
  Proposer &operator=(const Proposer &) = default;
  ~Proposer();
  void propose_value(std::string new_value);

private:
  // need a mapping of all nodes in view
  proposal_round m_proposal;
  std::string value;
};

#endif
