# decided to move to c++

class Solver:
    def __init__(self, grid):
        self.grid = grid
        self.cnt = 0
        self.z = self.count_zeros()

    def check(self):
        # rows
        for i in range(9):
            uniq = set()
            for j in range(9):
                uniq.add(self.grid[i][j])
            if len(uniq) != 9 or 0 in uniq:
                return False

        # cols
        for j in range(9):
            uniq = set()
            for i in range(9):
                uniq.add(self.grid[i][j])
            if len(uniq) != 9 or 0 in uniq:
                return False

        # squares
        for a in [(0, 3), (3, 6), (6, 9)]:
            for b in [(0, 3), (3, 6), (6, 9)]:
                uniq = set()
                for i in range(a[0], a[1]):
                    for j in range(b[0], b[1]):
                        uniq.add(self.grid[i][j])
                if len(uniq) != 9 or 0 in uniq:
                    return False

    def count_zeros(self):
        zeros = 0
        for i in range(9):
            for j in range(9):
                if self.grid[i][j] == 0:
                    zeros += 1
        return zeros

    def is_safe(self, x, y, k):

        # check col
        for i in range(9):
            if self.grid[i][y] == k:
                return False
        # check row
        for j in range(9):
            if self.grid[x][j] == k:
                return False

        # check square
        if 0 <= x < 3:
            a = (0, 3)
        elif 3 <= x < 6:
            a = (3, 6)
        else:
            a = (6, 9)
        if 0 <= y < 3:
            b = (0, 3)
        elif 3 <= y < 6:
            b = (3, 6)
        else:
            b = (6, 9)
        for i in range(a[0], a[1]):
            for j in range(b[0], b[1]):
                if self.grid[i][j] == k:
                    return False
        return True

    def bt(self):
        self.cnt += 1
        if self.cnt % 10000 == 0:
            print(self.cnt, self.z)

        if self.z == 0:
            print(self.grid)
            quit()
            if check():
                return True
            return False

        for i in range(9):
            for j in range(9):
                if self.grid[i][j] == 0:
                    for k in range(1, 10):
                        if self.is_safe(i, j, k):
                            self.grid[i][j] = k
                            self.z -= 1
                            ret = self.bt()
                            if ret:
                                return True
                            self.grid[i][j] = 0
                            self.z += 1

    def solve(self):
        self.bt()
        print('got it')

with open('p096_sudoku.txt', 'r') as f:
    for t in range(50):
        f.readline()
        grid = []
        for i in range(9):
            row = list(map(int, f.readline().strip()))
            grid.append(row)
        s = Solver(grid)
        s.solve()
        break
