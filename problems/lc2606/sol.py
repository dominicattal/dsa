#https://leetcode.com/problems/find-the-substring-with-maximum-cost/?envType=problem-list-v2&envId=dynamic-programming
def solve(s, chars, vals):
    costs = [i+1 for i in range(26)]
    for i, c in enumerate(chars):
        costs[ord(c)-ord('a')] = vals[i]
    dp = 0
    res = 0
    for i, c in enumerate(s):
        dp = max(dp + costs[ord(c)-ord('a')], costs[ord(c)-ord('a')])
        res = max(res, dp)
    return res
