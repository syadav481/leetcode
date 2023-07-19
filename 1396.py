class UndergroundSystem:
    def __init__(self):
        # id -> (startStation, checkInTime)
        self.in_m = {}
        # (start, end) -> [totalTime, numberOfPeople]
        self.t_m = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        if id in self.in_m:
            self.in_m.pop(id)
        self.in_m[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        timeTaken = t - self.in_m[id][1]
        source = self.in_m[id][0]
        if (source, stationName) in self.t_m:
            self.t_m[(source, stationName)][0] += timeTaken
            self.t_m[(source, stationName)][1] += 1
            return
        self.t_m[(source, stationName)] = [timeTaken, 1]

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        i = self.t_m[(startStation, endStation)]
        return i[0] / i[1]


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
