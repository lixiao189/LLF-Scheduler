#ifndef SCHEDULER_OS_H
#define SCHEDULER_OS_H

#include "Process.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using std::map;
using std::string;
using std::unique_ptr;

namespace scheduler {
const auto minLaxityInit = 0x3f3f3f3f;

class OS {
private:
  // 常量定义
  const int OSExecuteTime = 80; // 系统执行时间为 1000 ms

  // 变量定义
  map<string, process_ptr> processes;
  int up_time = 0;
  std::string current_process_pid; // 当前进程的 pid

  // 私有方法
  void tick();
  void startTicking();
  void timeInterrupt();
  int getProcessLaxity(const string &pid) const;

public:
  // Getters and setters
  void add_process(process_ptr process_obj);

  void start(); // 系统启动
};

using os_ptr = std::unique_ptr<OS>;
} // namespace scheduler

#endif
