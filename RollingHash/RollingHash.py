def rolling_hash(s: str, window_size: int, base: int = 26, mod: int = 10**9 + 7) -> List[int]:

    n = len(s)
    power = [1] * (n + 1)
    hash_values = [0] * (n - window_size + 1)
 
    for i in range(1, n + 1):
        power[i] = (power[i - 1] * base) % mod
 
    current_hash = 0
    for i in range(window_size):
        current_hash = (current_hash * base + ord(s[i])) % mod
 
    hash_values[0] = current_hash
 
    for i in range(1, n - window_size + 1):
 
        current_hash = (
            current_hash - power[window_size - 1] * ord(s[i - 1])) % mod
 
        current_hash = (current_hash * base + ord(s[i + window_size - 1])) % mod
 
        hash_values[i] = current_hash
 
    return hash_values