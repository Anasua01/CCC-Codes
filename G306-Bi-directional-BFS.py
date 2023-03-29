from collections import deque

n = int(input())
adj = [[] for _ in range(n+1)]

# Build the tree
for _ in range(n-1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

d = int(input())

# Perform BFS to find the nodes at dth level
visited = [False] * (n+1)
queue = deque([1])
visited[1] = True
level = 0
count = 0

while queue:
    level_size = len(queue)
    level += 1
    
    for _ in range(level_size):
        node = queue.popleft()
        
        if level == d:
            count += 1
        
        for neighbor in adj[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)
    
print(count)
