class Solution:
    def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
        diff = [x - y for x, y in zip(gas, cost)]
        total_gas_differential = 0
        total = 0
        start = 0
        for idx, gain in enumerate(diff):
            total_gas_differential += gain
            total += gain
            if total < 0:
                total = 0
                start = (idx + 1) % len(gas)
        if total_gas_differential < 0:
            return -1
        return start
