import subprocess
import platform
import random
import sys

# ANSI Colors
RED = "\033[31m"
GREEN = "\033[32m"
BLUE = "\033[34m"
YELLOW = "\033[33m"
PURPLE = "\033[35m"
RESET = "\033[0m"

INT_MIN = -2147483648
INT_MAX = 2147483647
# INT_MIN = 0
# INT_MAX = 1000

def generate_unique_numbers(size, max_attempts=100):
	# Generate a random list of unique numbers
	numbers = random.sample(range(INT_MIN, INT_MAX), size)

	while True:
		# Shuffle the numbers randomly
		random.shuffle(numbers)

		# Check if the list is neither strictly sorted (ascending) nor strictly sorted (descending)
		if numbers != sorted(numbers):
			return numbers  # If the list is not sorted in either direction, return the list

def run_push_swap(args):
	"""Run push_swap with the given numbers and return the output."""
	result = subprocess.run(["./push_swap"] + args, capture_output=True, text=True)
	return result.stdout.strip()

def run_checker(args, instructions):
	try:
		# Ensure both args and instructions are lists
		if not isinstance(args, list):
			args = [args]
		if not isinstance(instructions, list):
			instructions = [instructions]
		
		# Detect OS
		os_type = platform.system().lower()
		if os_type == "linux":
			command = ['./checker_linux'] + args
		elif os_type == "darwin":  # macOS
			command = ['./checker_mac'] + args
		else:
			print(f"{RED}Unsupported OS checker: {os_type}.\nExiting...{RESET}")
			sys.exit(1)

		# Join instructions with newline characters to simulate line-by-line input
		input_data = "\n".join(instructions) + "\n"
		
		# Run the command and provide input via stdin
		result = subprocess.run(
			command,
			input=input_data,
			capture_output=True,
			text=True
		)
		
		# Print the output from the checker
		res = result.stdout.strip()
		return res
	except Exception as e:
		print(f"An error occurred: {e}")

def main():
	if len(sys.argv) > 2 and sys.argv[1] == "test":
		# Test a specific case provided as an argument
		# join the rest of the arguments to form the test case
		test_case = ' '.join(sys.argv[2:]).strip()
		args = test_case.split()
		
		instructions = run_push_swap(args)
		result = run_checker(args, instructions)

		success_text = f"{GREEN}Sorted OK{RESET}" if result == 'OK' else f"{RED}Sorted KO{RESET}"
		print(f"\n{YELLOW}[Test]:{RESET} {success_text}\n{RESET}{test_case}")
		if "Error" in instructions:
			print(f"{RED}./push_swap Error{RESET}")
	elif len(sys.argv) == 3:
		size = int(sys.argv[1])
		tries = int(sys.argv[2])

		total_instructions = 0
		min_instructions = float("inf")
		max_instructions = 0
		passed_tests = 0

		for i in range(1, tries + 1):
			numbers = generate_unique_numbers(size)
			args = list(map(str, numbers))

			instructions = run_push_swap(args)
			instruction_count = len(instructions.splitlines())
			result = run_checker(args, instructions)

			total_instructions += instruction_count
			min_instructions = min(min_instructions, instruction_count)
			max_instructions = max(max_instructions, instruction_count)

			is_ok = result == 'OK'
			if is_ok:
				passed_tests += 1

			success_text = f"{GREEN}Sorted OK{RESET}" if is_ok else f"{RED}Sorted KO{RESET}"
			print(f"\n{YELLOW}[Test {i}]: {BLUE}{instruction_count} instructions{RESET} {success_text}\n{RESET}{' '.join(args)}")

			if "Error" in instructions:
				print(f"{RED}./push_swap Error{RESET}")

		avg_instructions = total_instructions / tries
		print(f"\n\n{PURPLE}Stack Size		: {size} node{RESET}")
		print(f"{BLUE}Average instructions	: {avg_instructions:.2f}{RESET}")
		print(f"{GREEN}Min instructions	: {min_instructions}{RESET}")
		print(f"{RED}Max instructions	: {max_instructions}{RESET}")
		print(f"{YELLOW}Passed tests		: {GREEN}{passed_tests}{RESET}/{tries} ({(passed_tests/tries)*100:.0f}%){RESET}")
	else:
		print(f"{RED}Please Provide Enough Arguments{RESET}")

if __name__ == "__main__":
	main()
