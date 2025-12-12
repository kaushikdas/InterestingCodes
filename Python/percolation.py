import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

from matplotlib.colors import ListedColormap


OPEN = 0
FLOW = 1
BLOCKED = 2


def create2D(n, v=0):
    a = [None]*n
    for i in range(n):
        a[i] = [v]*n
    return a


def show(m, cc=2):
    if (cc == 2):
        colors = ListedColormap(['white', 'black'])
    elif (cc == 3):
        colors = ListedColormap(['white', "#66b2ff", 'black'])

    sns.heatmap(m,
                square=True,
                cmap=colors,
                linewidths=0.5,
                linecolor='grey',
                # annot=True,
                vmin=0)
    plt.show()


def check_flow(cells, flow):
    n = len(cells)

    # top row of flow is similar to first row of cells
    for j in range(n):
        flow[0][j] = FLOW if cells[0][j] == 1 else BLOCKED

    for i in range(1, n):  # start checking from next row
        j = 0
        while (j < n):  # we cannot use `for j in range(n)`
            # because inside loop body i is changed

            """
            Checking if the cell just above or left has FLOW
            if is not enough because that will fail in scenarios
            where a cell's immediate left or top cell is not
            percolatabled cell but some cell connected to its
            RIGHT is percolatabled.

            So we need to check if ANY cell in a CONTINGUOUS
            SUBROW of open cells in the current row is 
            connected to some FLOW cell inn the previous row,
            then all of the cells in the subrow become FLOW
            """

            connected = False
            for k in range(j, n):
                if cells[i][k] != 1:
                    break
                connected = ((connected == True) or
                             (flow[i-1][k] == FLOW))

            if (connected == True):
                while ((j < n) and (cells[i][j] == 1)):
                    # all OPEN cells in this subrow are FLOW
                    flow[i][j] = FLOW
                    j += 1
            else:
                # This cell is not percolatable
                flow[i][j] = OPEN if cells[i][j] == 1 else BLOCKED
                j += 1

    result = False
    for j in range(n):
        if flow[n-1][j] == FLOW:
            result = True

    return (result, flow)


def percolate(cells):
    n = len(cells)

    flow = create2D(n, OPEN)

    return check_flow(cells, flow)


def main(cells):
    result, flow = percolate(cells)

    print(result)

    print('Input')
    # In cells 1 indicates an open cell
    #   Therefore, to show the cell as heatmap we will
    #   invert the values
    cells_copy = cells.copy()
    n = len(cells)
    for i in range(n):
        for j in range(n):
            cells_copy[i][j] = 0 if cells[i][j] == 1 else 1

    show(cells)

    print('Output')
    show(flow, cc=3)


if __name__ == '__main__':
    cells = [[0, 1, 1, 0, 0, 0],
             [0, 0, 1, 1, 1, 1],
             [0, 0, 0, 1, 1, 0],
             [0, 0, 0, 0, 1, 1],
             [0, 1, 1, 1, 1, 1],
             [1, 1, 0, 1, 0, 0]]
    main(cells)

    cells = [[0, 1, 0, 1, 0, 0],
             [1, 1, 1, 0, 0, 0],
             [1, 0, 1, 1, 0, 0],
             [0, 0, 0, 1, 1, 1],
             [0, 0, 0, 0, 0, 1],
             [0, 0, 0, 0, 0, 0]]
    main(cells)
