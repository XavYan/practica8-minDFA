#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>

#include "state_t.hpp"

class DFA {
private:
  set<state_t> states_; //conjunto de estados
  int all_states_; //cantidad de estados totales
  unsigned init_; //id del estado inicial
  set<char> alphabet; //alfabeto sobre el que el automata trabaja
public:
  DFA (void);
  DFA (const set<state_t>& states);
  ~DFA (void);

  const unsigned init (void);

  void create_dfa (const char* nombreFichero, bool& errorApertura);
  void create_dfa (const set<set<state_t> >& OM);
  void show_chain_result (void);
  void show_dead_states (void);
  void show_alphabet (void);

  void minDFA (void);

  ostream& dbg_write (void) const;
  ostream& write (void) const;
  ostream& write (ostream& os) const;
  void clear (void);

private:
  set<set<state_t> > new_partition (const set<set<state_t> >& COM);
  set<set<state_t> > descomp (const set<state_t>& G, const set<set<state_t> >& COM);
  set<set<state_t> > part (const set<state_t>& G, const char c, const set<set<state_t> >& COM);

  bool chain_test (const string& chain) const;
  set<state_t> dead_states (void);
  const state_t find_by_id (const unsigned& id) const;
  const bool equal (const set<set<state_t> >& set1, const set<set<state_t> >& set2);
  const bool equal (const set<state_t>& set1, const set<state_t>& set2);

  set<set<state_t> > join (const set<set<state_t> >& set1, const set<set<state_t> >& set2);
  set<state_t> join (const set<state_t>& set1, const set<state_t>& set2);

  void write_set_of_set (const set<set<state_t> >& set);
};
