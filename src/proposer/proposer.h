#ifndef PROPOSER_H
#define PROPOSER_H

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

private:
  // need a mapping of all nodes in view
  proposal_round m_proposal;
};

#endif
