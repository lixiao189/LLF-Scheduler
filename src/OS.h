#ifndef SCHEDULER_OS_H
#define SCHEDULER_OS_H

#include "Process.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using scheduler::Process;
using std::map;
using std::string;
using std::unique_ptr;

namespace scheduler {
using process_ptr = unique_ptr<Process>;

class OS {
private:
  map<string, process_ptr> processes;

public:
  // Getters and setters 
  void add_process(process_ptr process_obj);

  void start();     // 操作系统开始运行
  void timeInterrupt(); // 操作系统时钟中断
};

using os_ptr = unique_ptr<scheduler::OS>;
} // namespace scheduler

#endif
