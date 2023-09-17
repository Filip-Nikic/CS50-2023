import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Missing command-line argument")
        sys.exit(1)

    # TODO: Read database file into a variable
    file_txt = open(sys.argv[2], "r")

    # TODO: Read DNA sequence file into a variable
    dna = file_txt.readline()
    file_txt.close()

    with open(sys.argv[1], newline="") as csvfile:
        reader = csv.DictReader(csvfile)
        subsequences = []
        for row in reader:
            seq = []
            keys = list(row)
            for i in range(1, len(row)):
                seq.append(int(row[keys[i]]))
        for i in range(1, len(row)):
            subsequences.append(keys[i])

    # TODO: Find longest match of each STR in DNA sequence
    dna_sequence = []
    for value in subsequences:
        dna_sequence.append(longest_match(dna, value))

    # TODO: Check database for matching profiles
    with open(sys.argv[1], newline="") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            seq = []
            keys = list(row)
            for i in range(1, len(row)):
                seq.append(int(row[keys[i]]))
            if dna_sequence == seq:
                print(row[keys[0]])
                return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
