class Solution(object):
    def countGoodRectangles(self, rectangles):
        return sorted(Counter(map(min, rectangles)).items())[-1][1]
