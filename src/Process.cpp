#include "Process.h"

namespace scheduler {
Process::Process(string &&pid, const int cycle_time, int execute_time)
    : pid(pid), cycle_time(cycle_time), execute_time(execute_time) {}

string Process::get_pid() const { return pid; }

int Process::get_cycle_id() const { return cycle_id; }

int Process::get_cycle_time() const { return cycle_time; }

int Process::get_execute_time() const { return execute_time; }

int Process::get_up_time() const { return up_time; }

void Process::inc_cycle_id() { cycle_id++; }

void Process::inc_up_time() { up_time++; }
} // namespace scheduler
