def extended_euclidean_algorithm(a, b):
    if b == 0:
        return a, 1, 0

    gcd, x1, y1 = extended_euclidean_algorithm(b, a % b)
    x = y1
    y = x1 - (a // b) * y1

    return gcd, x, y

def find_modular_inverse(a, m):
    gcd, x, y = extended_euclidean_algorithm(a, m)
    if gcd != 1:
        raise ValueError("Inverse does not exist.")

    return x % m

# Example usage:
a = int(input("Enter a number to find inverse: "))
m = int(input("Enter the number whose modulus is to be found: "))

inverse = find_modular_inverse(a, m)
print("Modular inverse of", a, "mod", m, "is:", inverse)
