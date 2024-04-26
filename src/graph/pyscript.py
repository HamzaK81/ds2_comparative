import matplotlib.pyplot as plt


def plot_graph(filename):
    x, y = [], []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split(',')
            x.append(float(parts[0]))
            y.append(float(parts[1]))

    plt.plot(x, y)
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('Simple Plot')
    plt.show()


if __name__ == '__main__':
    plot_graph('src/graph/graphdata.csv')


