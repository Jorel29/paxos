#ifndef PROPOSER_H
#define PROPOSER_H

class Proposer {
public:
  Proposer();
  Proposer(Proposer &&) = default;
  Proposer(const Proposer &) = default;
  Proposer &operator=(Proposer &&) = default;
  Proposer &operator=(const Proposer &) = default;
  ~Proposer();

private:
  struct proposal_round;
  int prepare(struct proposal_round);
  int accept(struct proposal_round, char *value);
  int read_promise();
  int read_accepted();
  int inc_prop_round(struct proposal_round);
  int quorum_wait();
};

#endif
