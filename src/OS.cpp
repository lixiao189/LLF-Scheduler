#include "OS.h"
#include <string>

namespace scheduler {

void OS::tick() { up_time++; }

int OS::getProcessLaxity(const string &pid) const {
  const auto &process = processes.find(pid)->second;
  
  const auto dead_time = process->get_cycle_time() * (process->get_cycle_id() + 1);
  const auto rest_time = process->get_execute_time() - process->get_up_time();
  
  return dead_time - rest_time - up_time;
}

void OS::add_process(process_ptr process_obj) {
  processes.insert(make_pair(process_obj->get_pid(), move(process_obj)));
}

void OS::startTicking() {
  while (up_time < OSExecuteTime) {
    timeInterrupt(); // 每次时钟 tick 以后触发时钟中断
    tick();
  }
}

void OS::timeInterrupt() {
  for (auto & process_pair : processes) {
    const auto & process = process_pair.second;
    // TODO  
  }
}

void OS::start() {
  // 添加进程 
  const auto aCycleTime = 15;
  const auto aExecuteTime = 5;

  const auto bCycleTime = 30;
  const auto bExecuteTime = 10;

  const auto cCycleTime = 45;
  const auto cExecuteTime = 12;

  add_process(process_ptr(new Process("A", aCycleTime, aExecuteTime)));
  add_process(process_ptr(new Process("B", bCycleTime, bExecuteTime)));
  add_process(process_ptr(new Process("C", cCycleTime, cExecuteTime)));

  // 开始记时
  startTicking();
}

} // namespace scheduler
