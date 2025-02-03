import random

def generate_push_swap_numbers():
    int_min = 0
    int_max = 100

    # Generate 1000 unique numbers (including INT_MIN and INT_MAX)
    numbers = set()
    numbers.add(int_min)  # Include edge case
    numbers.add(int_max)  # Include edge case

    # Fill the rest with random unique numbers
    while len(numbers) < 100:
        numbers.add(random.randint(int_min, int_max))

    # Shuffle and convert to list
    numbers_list = list(numbers)
    random.shuffle(numbers_list)
    
    # Print as space-separated string
    print(' '.join(map(str, numbers_list)))

generate_push_swap_numbers()