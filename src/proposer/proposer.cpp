#include "proposer.h"
#include <unordered_map>
// Need to decide on how errors are handled

Proposer::Proposer() {
  m_proposal.id = 0;
  m_proposal.proposal = 0;
}
// returns
int quorum_wait(std::unordered_map<int, int> &acceptors) {
  // start listening for resposes for acceptors, and tally up the responses

  return 0;
}
int inc_proposal(proposal_round &proposal) {
  // need to lock in a multi-threaded scenario
  proposal.id++;

  return 0;
}
int prepare(proposal_round &proposal) {
  // choose a proposal number
  if (inc_proposal(proposal) == -1)
    return -1;
  // send a proposal to all the acceptors

  // wait for a response from a majority of the acceptors
  // need to deal with being a lower proposal number than other proposers
  // once finished, exit
  return 0;
}
int accept(proposal_round &proposal, char *value) {
  // send out an accept message and wait for responses

  return 0;
}
int read_promise();
int read_accepted();
