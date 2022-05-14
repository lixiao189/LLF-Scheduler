#include "OS.h"
#include "Process.h"

using scheduler::OS;
using scheduler::process_ptr;
using scheduler::os_ptr;

int main() {
  os_ptr os_obj(new OS);

  os_obj->start();

  return 0;
}
