#include "proposer.h"

// Need to decide on how errors are handled

Proposer::Proposer() {
  m_proposal.id = 0;
  m_proposal.proposal = 0;
}

int inc_proposal(proposal_round &proposal) {
  proposal.id++;

  return 0;
}
int prepare(proposal_round &proposal) {
  // choose a proposal number
  if (inc_proposal(proposal) == -1)
    return -1;

  return 0;
}
int accept(proposal_round proposal, char *value);
int read_promise();
int read_accepted();
int quorum_wait();
