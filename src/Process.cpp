#include "Process.h"

namespace scheduler {
Process::Process(const int execute_time, int cycle_time)
    : cycle_time(cycle_time), execute_time(execute_time) {}

int Process::calc_laxity(int time_now) const {
  return (cycle_id + 1) * cycle_time - (execute_time - up_time) - time_now;
}

int Process::get_cycle_id() const { return cycle_id; }

int Process::get_cycle_time() const { return cycle_time; }

int Process::get_execute_time() const { return execute_time; }

int Process::get_up_time() const { return up_time; }

void Process::inc_cycle_id() { cycle_id++; }

void Process::inc_up_time() { up_time++; }
} // namespace scheduler
