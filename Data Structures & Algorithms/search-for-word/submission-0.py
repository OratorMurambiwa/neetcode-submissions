class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        rows = len(board)
        cols = len(board[0])

        used = set()

        def dfs(r,c,i):
            if i == len(word):
                return True

            if (
                r < 0 or r >= rows or
                c < 0 or c >= cols or
                (r,c) in used or
                board[r][c] != word[i]
            ):

                return False

            used.add((r,c))

            found = (
                dfs(r+1, c, i+1) or
                dfs(r-1, c, i+1) or
                dfs(r, c+1, i+1) or
                dfs(r, c-1, i+1)
            )

            used.remove((r,c))

            return found

        for r in range(rows):
            for c in range(cols):
                if dfs(r,c,0):
                    return True

        return False







