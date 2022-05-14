#include "OS.h"
#include <iostream>

namespace scheduler {

void OS::add_process(process_ptr process_obj) {
  processes.insert(make_pair(process_obj->get_pid(), move(process_obj)));
}

void OS::start() {
  // debug
  for (auto & process_pair : processes) {
    std::cout << process_pair.second->get_pid() << std::endl;
  }
}

} // namespace scheduler
