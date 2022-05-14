#include "OS.h"

namespace scheduler {

void OS::tick() { up_time++; }

void OS::add_process(process_ptr process_obj) {
  processes.insert(make_pair(process_obj->get_pid(), move(process_obj)));
}



void OS::startTicking() {
  while (up_time < OSExecuteTime) {
    tick();
    timeInterrupt(); // 每次时钟 tick 以后触发时钟中断
  }
}

void OS::timeInterrupt() {}

} // namespace scheduler
