#include "proposer.h"
#include <fstream>
#include <string>
#include <vector>
// Need to decide on how errors are handled

Proposer::Proposer() {
  m_proposal.id = 0;
  m_proposal.proposal = 0;
}

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
// reads takes data from the buffer, updates proposal round and value if those
// are returned from an acceptor
int extract_data(char *&data, proposal_round &proposal, char *&value) {
  std::string temp(data);
  std::string delim(":");
  std::vector<std::string> result = split(delim, temp);

  return 0;
}

// returns
int quorum_wait() {
  // start listening for resposes for acceptors, and tally up the responses

  return 0;
}
int inc_proposal(proposal_round &proposal) {
  // need to lock in a multi-threaded scenario
  proposal.id++;

  return 0;
}
// begin sending out messages to the known accecptors
int start_proposal(proposal_round &proposal) {
  // use the communication interface when its ready
  // for now, write to dummy file
  std::ofstream out;
  out.open("proposal_out");

  if (!out.fail())
    out << proposal.id << " " << proposal.proposal;
  out.close();

  std::ifstream in;
  in.open("proposal_in");
  proposal_round acceptor;
  while (!in.fail()) {
    if (in >> acceptor.id) {
      return 0;
    }
  }
  return 0;
}

int prepare(proposal_round &proposal) {
  // choose a proposal number
  if (inc_proposal(proposal) == -1)
    return -1;
  // send a proposal to all the acceptors
  start_proposal(proposal);
  // wait for a response from a majority of the acceptors

  // need to deal with being a lower proposal number than other proposers
  // function for splitting the msg_data
  // extract the proposal_round data from msg_data
  // set the proposal round for m_proposal as msg_data proposal_round
  // once finished, exit
  return 0;
}
int accept(proposal_round &proposal, char *value) {
  // send out an accept message and wait for responses

  return 0;
}
