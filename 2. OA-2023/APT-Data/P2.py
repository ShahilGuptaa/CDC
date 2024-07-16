n, k = map(int, input().split())
degree = [0] * 1001
deleted = [0] * 1001
seen = [0] * 1001
distance = [0] * 1001
G = [[] for _ in range(1001)]

def get_distance(node, dist):
    seen[node] = 1
    for i in G[node]:
        if not seen[i]:
            if not deleted[i]:
                get_distance(i, dist + 1)
    distance[node] = dist

def get_diameter():
    global distance, seen
    distance = [-1] * 1001
    seen = [0] * 1001
    for i in range(n):
        if not deleted[i]:
            get_distance(i, 0)
            break
    mxd = -1
    mxi = 0
    for i in range(n):
        if distance[i] > mxd:
            mxd = distance[i]
            mxi = i
    distance = [-1] * 1001
    seen = [0] * 1001
    get_distance(mxi, 0)
    return max(distance)

def calculate(node):
    global distance, seen
    distance = [0] * 1001
    seen = [0] * 1001
    get_distance(node, 0)
    ret = 0
    for i in range(n):
        if distance[i] == diameter:
            ret += 1
    return ret

for i in range(n - 1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append(v)
    G[v].append(u)
    degree[u] += 1
    degree[v] += 1

best = (0, -1)
diameter = get_diameter()

for removed in range(1, k + 1):
    for i in range(n):
        if not deleted[i]:
            if degree[i] == 1:
                temp = calculate(i)
                if temp > best[0]:
                    best = (temp, i)

    deleted[best[1]] = 1
    for i in G[best[1]]:
        if not deleted[i]:
            degree[i] -= 1

    best = (0, -1)
    diameter = get_diameter()

print(diameter)