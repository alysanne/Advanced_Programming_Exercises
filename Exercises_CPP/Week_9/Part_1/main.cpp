#include <iostream>
#include <thread>
#include <sched.h>
#include <chrono>

using namespace std;


void BasicThread(int id) {
  cout << "Thread " << id << " start" << endl;
  this_thread::sleep_for (chrono::seconds(2));
  cout << "Thread " << id << " end" << endl;
}

void MessageThread(int id) {
  for(int i = 0; i < 100; i++) {
    if (id == 3) {
      cout <<"\t\t 3:Thread\n";
    } else if (id == 4) {
      cout <<"\t\t\t\t 4:Thread\n";
    } else {
      cout <<"\t\t\t\t\t\t 5:Thread\n";
    }
  }
}

int main() {
  cout << "------ Exercise 1 ------" << endl;
  cout << "------ Basic Thread ------" << endl;
  thread thread1 (BasicThread, 1);
//  thread1.join(); // Join the main thread, main will wait for it to finish before continuing with the code after it
  thread thread2 (BasicThread, 2);
//  thread2.join(); // Join the main thread

  this_thread::sleep_for (chrono::seconds(3)); // Option to avoid exiting before the threads end, if they don't join the main thread
//  cin.get(); // Option to avoid exiting before the threads end, if they don't join the main thread

  cout << "------ Message Thread ------" << endl;
  thread thread3 (MessageThread, 3);
  sched_param th3_sched_param;
  th3_sched_param.sched_priority = 0;
  pthread_setschedparam(thread3.native_handle(), SCHED_OTHER, &th3_sched_param);
//  thread3.join();

  thread thread4 (MessageThread, 4);
  sched_param th4_sched_param;
  th4_sched_param.sched_priority = 99; // Highest priority
  pthread_setschedparam(thread4.native_handle(), SCHED_RR, &th4_sched_param);
//  thread4.join();

  thread thread5 (MessageThread, 5);
  sched_param th5_sched_param;
  th5_sched_param.sched_priority = 1; // Lowest priority (1)
  pthread_setschedparam(thread5.native_handle(), SCHED_RR, &th5_sched_param);
//  thread5.join();

  this_thread::sleep_for (chrono::seconds(5));
}