#include "OS.h"
#include <string>

namespace scheduler {
using std::string;

void OS::tick() { up_time++; }

int OS::getProcessLaxity(const string &pid) const {
  const auto &process = processes.find(pid)->second;

  const auto dead_time =
      process->get_cycle_time() * (process->get_cycle_id() + 1);
  const auto rest_time = process->get_execute_time() - process->get_up_time();

  return dead_time - rest_time - up_time;
}

void OS::add_process(process_ptr process_obj) {
  processes.insert(make_pair(process_obj->get_pid(), move(process_obj)));
}

void OS::startTicking() {
  while (up_time <= OSExecuteTime) {
    timeInterrupt(); // 每次时钟 tick 以后触发时钟中断
    tick();
  }
}

void OS::timeInterrupt() {
  const auto process_it = processes.find(current_process_pid);
  const auto has_running_process = process_it != processes.end();
  const auto &process = process_it->second; // 当前运行的进程

  if (has_running_process) {
    if (process->get_up_time() == process->get_execute_time()) {
      process->clear_up_time();
      process->inc_cycle_id();
    }
  }

  // 寻找当前松弛度最低的进程
  int min_laxity = minLaxityInit;
  string urgent_process_pid;
  for (auto &process_pair : processes) {
    const auto &process = process_pair.second;
    if (process->get_cycle_id() * process->get_cycle_time() > up_time) {
      continue;
    }
    const auto laxity = getProcessLaxity(process->get_pid());
    if (laxity < min_laxity) {
      min_laxity = laxity;
      urgent_process_pid = process->get_pid();
    }
  }
  if (urgent_process_pid.empty()) { // 所有进程都执行完了
    current_process_pid = "";
    return;
  }

  auto can_preempt = false;
  if (has_running_process) {
    if (min_laxity == 0 || process->get_up_time() == 0) {
      can_preempt = true;
    }
  } else {
    can_preempt = true;
  }
  if (urgent_process_pid != current_process_pid && can_preempt) { // 进程抢占
    const auto &urgent_process = processes.find(urgent_process_pid)->second;
    std::cout << "任务名: " << urgent_process_pid << std::endl
              << "周期数: " << urgent_process->get_cycle_id() + 1 << std::endl
              << "调度时刻: " << up_time << std::endl
              << "运行持续时间: " << urgent_process->get_up_time() << std::endl
              << "====================" << std::endl;
    current_process_pid = urgent_process_pid;
  }

  // 增加经过竞争后的当前进程的运行时间
  processes.find(current_process_pid)->second->inc_up_time();
}

void OS::start() {
  // 添加进程
  const auto aCycleTime = 20;
  const auto aExecuteTime = 10;

  const auto bCycleTime = 50;
  const auto bExecuteTime = 25;

  // const auto cCycleTime = 45;
  // const auto cExecuteTime = 12;

  add_process(process_ptr(new Process("A", aCycleTime, aExecuteTime)));
  add_process(process_ptr(new Process("B", bCycleTime, bExecuteTime)));
  // add_process(process_ptr(new Process("C", cCycleTime, cExecuteTime)));

  // 开始记时
  startTicking();
}

} // namespace scheduler
