def canWin(R, C, A, B):
    # Initialize a DP table
    dp = [[-1] * (C + 1) for _ in range(R + 1)]

    def dfs(x, y):
        # If the current cell is (R, C), the player whose turn it is wins
        if x == R and y == C:
            return True

        # If the cell has already been visited, return the result from DP table
        if dp[x][y] != -1:
            return dp[x][y]

        # Alice's turn
        if (x + A <= R and not dfs(x + A, y)) or (y + B <= C and not dfs(x, y + B)):
            dp[x][y] = 1
            return True

        # Bob's turn
        dp[x][y] = 0
        return False

    # Start the game from (1, 1), Alice's turn
    if dfs(1, 1):
        return "YES"
    else:
        return "NO"

# Read the number of test cases
T = int(input())

for i in range(1, T + 1):
    R, C, A, B = map(int, input().split())
    result = canWin(R, C, A, B)
    print(f"Case #{i}: {result}")
