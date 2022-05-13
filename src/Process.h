#ifndef SCHEDULER_PROCESS_H
#define SCHEDULER_PROCESS_H

namespace scheduler {
class Process {
private:
  int up_time = 0;  // 线程上线时间
  int execute_time; // 线程需要的执行时间
  int cycle_time;   // 线程执行周期
  int cycle_id = 0; // 周期 ID
public:
  Process(const int execute_time, const int cycle_time);

  // Getters and setters
  int get_cycle_id() const;
  int get_cycle_time() const;
  int get_execute_time() const;
  int get_up_time() const;
  void inc_cycle_id();
  void inc_up_time();

  int calc_laxity(int time_now) const;
};

} // namespace process_scheduler
#endif
