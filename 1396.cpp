#include <map>
#include <string>

using namespace std;

class UndergroundSystem {
private:
  struct Customer {
    int t;
    string source;
  };
  struct Average {
    long long total;
    long long count;
    double getAverage() {
      return static_cast<double>(total) / static_cast<double>(count);
    }
  };
  string concatenate(string s, string u) { return s + " #\\# " + u; };
  map<int, Customer> cm;
  map<string, Average> tm;

public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    if (cm.find(id) != cm.end()) {
      cm.erase(id);
    }
    cm[id] = {t, stationName};
  }

  void checkOut(int id, string stationName, int t) {
    string concat = concatenate(cm[id].source, stationName);
    long long timeTaken = t - cm[id].t;
    // if it was already there
    if (tm.find(concat) != tm.end()) {
      ++tm[concat].count;
      tm[concat].total += timeTaken;
      return;
    }
    // if it wasn't already there
    tm[concat] = {timeTaken, 1};
  }

  double getAverageTime(string startStation, string endStation) {
    string concat = concatenate(startStation, endStation);
    return tm[concat].getAverage();
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */