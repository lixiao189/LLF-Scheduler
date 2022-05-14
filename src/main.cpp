#include "OS.h"
#include <iostream>
#include <string>

using scheduler::OS;
using scheduler::process_ptr;

int main() {
  scheduler::os_ptr os_obj(new OS());

  const auto aCycleTime = 15;
  const auto aExecuteTime = 5; 

  const auto bCycleTime = 30;
  const auto bExecuteTime = 10; 
  
  const auto cCycleTime = 45;
  const auto cExecuteTime = 12; 
  
  os_obj->add_process(process_ptr(new Process("A", aCycleTime, aExecuteTime)));
  os_obj->add_process(process_ptr(new Process("B", bCycleTime, bExecuteTime)));
  os_obj->add_process(process_ptr(new Process("C", cCycleTime, cExecuteTime)));
  
  os_obj->start();
}
