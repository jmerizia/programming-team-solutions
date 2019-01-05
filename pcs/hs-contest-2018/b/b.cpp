#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, T;
set<pii> store;
set<pii> remote;
pii tecs[11]; // holds the event that each tec is currently working on

int get_next_available_time()
{
  int next_available_time = INT_MAX;
  for (int i = 0; i < T; i++) {
    int started = tecs[i].first;
    int time_to_complete = tecs[i].second;
    int finished = started + time_to_complete;
    if (finished < next_available_time) {
      next_available_time = finished;
    }
  }
  return next_available_time;
}

int assign_to_tec(pii event)
{
  int cur_time = event.first;
  int next_available_time = INT_MAX;
  int next_available_tec = -1;
  for (int i = 0; i < T; i++) { 
    int started = tecs[i].first;
    int time_to_complete = tecs[i].second;
    int finished = started + time_to_complete;
    if (finished < next_available_time) {
      next_available_time = finished;
      next_available_tec = i;
    }
  }
  int delay = max(0, next_available_time - cur_time); // the delay until the next available tec
  // if it's negative, then the tecs have free time
  pii new_event = {event.first + delay, event.second};
  tecs[next_available_tec] = new_event;
  return delay;
}

void solve()
{
  auto store_it = store.begin();
  auto remote_it = remote.begin();
  double total_remote_time = 0;
  double total_store_time = 0;
  while (store_it != store.end() && remote_it != remote.end()) {
    pii store_event = *store_it;
    pii remote_event = *remote_it;
    int next_available_time = get_next_available_time();
    int store_event_can_be_done = next_available_time <= store_event.first;
    int remote_event_can_be_done = next_available_time <= remote_event.first;
    int do_store_event = 0;
    if (store_event_can_be_done && remote_event_can_be_done) {
      // the next tec is free before both events come in, so just do the sooner event
      do_store_event = (store_event.first <= remote_event.first);
    } else if (store_event_can_be_done) {
      // do the store event
      do_store_event = 1;
    } else if (remote_event_can_be_done) {
      // do the remote event
      do_store_event = 0;
    } else {
      // we can't do either right now, so take the store event
      do_store_event = 1;
    }

    if (do_store_event) {
      int cur_time = store_event.first;
      int delay = assign_to_tec(store_event);
      printf("processed store %d %d with %d delay\n", store_event.first, store_event.second, delay);
      total_store_time += delay + store_event.second;

      store_it++;
    } else {
      int cur_time = remote_event.first;
      int delay = assign_to_tec(remote_event);
      printf("processed remote %d %d with %d delay\n", remote_event.first, remote_event.second, delay);
      total_remote_time += delay + remote_event.second;

      remote_it++;
    }

  }
  while (store_it != store.end()) {
    pii store_event = *store_it;
    int cur_time = store_event.first;
    int delay = assign_to_tec(store_event);
    printf("processed store %d %d with %d delay\n", store_event.first, store_event.second, delay);
    total_store_time += delay + store_event.second;

    store_it++;
  }
  while (remote_it != remote.end()) {
    pii remote_event = *remote_it;
    int cur_time = remote_event.first;
    int delay = assign_to_tec(remote_event);
    printf("processed remote %d %d with %d delay\n", remote_event.first, remote_event.second, delay);
    total_remote_time += delay + remote_event.second;

    remote_it++;
  }
  double ans_store;
  double ans_remote;
  ans_store = total_store_time / (double) store.size();
  ans_remote = total_remote_time / (double) remote.size();
  if (remote.size() == 0) {
    ans_remote = 0;
  }
  if (store.size() == 0) {
    ans_store = 0;
  }
  printf("%0.7f %0.7f", ans_store, ans_remote);
}

int main()
{
  cin >> n >> T;
  for (int i = 0; i < n; i++) {
    int d, k; char c;
    cin >> d >> c >> k;
    pii event = {d, k};
    if (c == 'S') {
      store.insert(event);
    } else {
      remote.insert(event);
    }
  }
  for (int i = 0; i < T; i++) tecs[i] = {0, 0};
  solve();
}
