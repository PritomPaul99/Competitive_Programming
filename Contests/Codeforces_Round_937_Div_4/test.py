def generate_checkerboard(n):
    checkerboard = [['#' if (i + j) % 2 == 0 else '.' for j in range(2 * n)] for i in range(2 * n)]
    return checkerboard

def print_checkerboard(checkerboard):
    for row in checkerboard:
        print(''.join(row))

n = int(input("Enter the value of n: "))
checkerboard = generate_checkerboard(n)
print_checkerboard(checkerboard)
