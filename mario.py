# TODO
while True:
    n = input("Height:")
    if not n.isdigit():
        continue
    n = int(n)
    if 1 <= n <= 8:
        break
for x in range(1, n + 1):
    print((" " * (n - x)) + ("#" * x) + "  " + ("#" * x))
