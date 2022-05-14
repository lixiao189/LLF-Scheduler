#ifndef SCHEDULER_PROCESS_H
#define SCHEDULER_PROCESS_H

#include <string>
namespace scheduler {

using std::string;
class Process {
private:
  string pid;
  int up_time = 0;  // 线程上线时间
  int execute_time; // 线程需要的执行时间
  int cycle_time;   // 线程执行周期
  int cycle_id = 0; // 周期 ID
public:
  Process(string &&pid, const int cycle_time, const int execute_time);

  // Getters and setters
  string get_pid() const;
  int get_cycle_id() const;
  int get_cycle_time() const;
  int get_execute_time() const;
  int get_up_time() const;
  void inc_cycle_id();
  void inc_up_time();
};

} // namespace scheduler
#endif
